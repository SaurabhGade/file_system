#include "../../include/disk_utils.h"

bool add_file(vdisk *dsk, char *path){

    assert(path != NULL);
    assert(dsk->vd != NULL);
    FILE *file = fopen(path, "r");
    if(file == NULL){
        printf(" NO SUCH FILE OR DIRECTORY\n");
        return false;
    }

    size_t file_size = 0;
    fseek(file, 0, SEEK_END);
    file_size = (ftell(file) + MAX_FILE_NAME_LEN) ; /// got file size in bytes.

    if (dsk->free < file_size){         ///check disk status.
        printf("STORAGE SPACE NOT AVAILABLE!\n");
        return false;
    }
    size_t enc_seq_size = 0;
    void *buff = encode_size(file_size, &enc_seq_size); 

    if(dsk->curr_size_block_number + enc_seq_size >= dsk->curr_data_block_number-file_size){
        printf("DISK FULL!\n");
        return false;
    }
    // memprint(buff, enc_seq_size);    

    fseek(file, dsk->curr_size_block_number, SEEK_CUR);
    rewind(file); // file pointer at the beginning.

    char file_name[MAX_FILE_NAME_LEN];
    trim_fname(file_name, path);
    if(search_file_name(*dsk, file_name) > 0){
        printf(" SAME FILE NAME ALREADY EXIST\n");
        free(buff);
        return false;
    }

    char data[1];
    //fread(data+MAX_FILE_NAME_LEN, file_size, 1, file);        //read all bytes from the file and store in data.
    

    //insert file name at the end.
    


    rewind(file);
    fseek(dsk->vd , dsk->curr_size_block_number, SEEK_SET);
    fwrite(buff, enc_seq_size, 1, dsk->vd);

    dsk->curr_size_block_number += enc_seq_size;
    dsk->occupied += enc_seq_size;
    dsk->free -= enc_seq_size;
    dsk->file_count += 1;
    update_disk(dsk);

    rewind(dsk->vd);
    fseek(dsk->vd, dsk->curr_data_block_number - (file_size), SEEK_SET);
    fwrite(file_name,MAX_FILE_NAME_LEN, 1 , dsk->vd);
    rewind(file);
    fread(data, 1, 1, file);
    while(!feof(file)){
      fwrite(data,1, 1, dsk->vd);
      fread(data, 1, 1, file);
    }
    free(buff);         

    dsk->curr_data_block_number -= file_size;
    dsk->occupied += file_size;
    dsk->free -= file_size;
    update_disk(dsk);           //write change in the disk.

    rewind(dsk->vd); 
    fseek(dsk->vd, dsk->curr_size_block_number, SEEK_SET);

    fclose(file);               //no need of file anymores
    return true;
}
