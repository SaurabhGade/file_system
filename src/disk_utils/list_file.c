#include "../../include/disk_utils.h"
void list_file(vdisk dsk){
    assert(dsk.vd != NULL);
    unsigned char buff[8] = {0};
    size_t nxt_size = 0; 
    char fname[MAX_FILE_NAME_LEN];
    size_t skip_bytes = 0;
    char *delf = DELETED_FILE_NAME;
    size_t counter = 1;
    for (size_t i = 0; i < dsk.file_count+dsk.deleted; i++){
        size_t fsize = 0;
        rewind(dsk.vd);
        fseek(dsk.vd, FIRST_SIZE_SEQ+nxt_size, SEEK_SET);
        fread(buff, 1, sizeof(fsize), dsk.vd);
        fsize = decode_size(buff);
        
        seq.bit_count = 0;
        set_seq(log2(fsize)+1);
        nxt_size += (seq.bit_count / 8) + !(!seq.bit_count % 8);
        skip_bytes += fsize;
        get_file_name(fname, dsk, skip_bytes);
        fname[MAX_FILE_NAME_LEN-1] = 0;
        if(strcmp(fname, delf) != 0){
            printf("%zu: %s\t  %zu Bytes\n", counter, fname, fsize);
            counter+=1;
        }
    }
    return;
}