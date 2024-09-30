#include "../../include/disk_utils.h"

long long  search_file_name(vdisk dsk, char *file_name){
    assert(dsk.vd != NULL);
    assert(file_name != NULL);  

    unsigned char buff[8] = {0};
    size_t nxt_size = 0; 
    char fname[MAX_FILE_NAME_LEN];
    size_t skip_bytes = 0;
    
    for (size_t i = 0; i < dsk.file_count + dsk.deleted; i++){
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
        if(strcmp(file_name, fname) == 0)
            return fsize-MAX_FILE_NAME_LEN;
    }
    return -1;
}
