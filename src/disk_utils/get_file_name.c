#include "../../include/disk_utils.h"

void get_file_name(char *dst, vdisk dsk, size_t skip_bytes){
    assert(dst != NULL);
    assert(dsk.vd != NULL);

    fseek(dsk.vd, 0, SEEK_END);         //pointer at the end of the  file.
    fseek(dsk.vd, -1, SEEK_CUR);

    fseek(dsk.vd, -(skip_bytes), SEEK_CUR);
    // fscanf(dsk.vd, "%s", dst);
    fread(dst, 1 , MAX_FILE_NAME_LEN, dsk.vd);
    return;
}