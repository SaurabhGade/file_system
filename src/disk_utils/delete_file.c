#include "../../include/disk_utils.h"

bool delete_file(vdisk *dsk, char *f_name){
    assert(dsk != NULL);
    if(f_name == NULL)
        return false;
    long long file_size = 0;
    if((file_size = search_file_name(*dsk, f_name)) <= 0)   /// FILE DOES NOT EXIST.
        return false;
    fseek(dsk->vd, -1 * MAX_FILE_NAME_LEN, SEEK_CUR);    
    fwrite(DELETED_FILE_NAME, MAX_FILE_NAME_LEN, 1, dsk->vd);
    dsk->deleted += 1;
    dsk->file_count -= 1;
    dsk->free += file_size;
    dsk->occupied -= file_size;
    update_disk(dsk);
    return true;
}
