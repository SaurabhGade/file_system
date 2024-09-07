#include "../../include/disk_utils.h"

void update_disk(vdisk *dsk){
    assert(dsk->vd != NULL);
    rewind(dsk->vd);

    
    fseek(dsk->vd, DISK_FREE_BLOCK_NO, SEEK_SET);

    //update no of free block in the disk.
    fwrite(&dsk->free, sizeof(dsk->free), 1, dsk->vd);
    fwrite(&dsk->occupied, sizeof(dsk->occupied), 1, dsk->vd);
    fwrite(&dsk->file_count, sizeof(dsk->file_count), 1, dsk->vd); 
    fwrite(&dsk->curr_size_block_number, sizeof(dsk->curr_size_block_number), 1, dsk->vd);
    fwrite(&dsk->curr_data_block_number, sizeof(dsk->curr_data_block_number), 1, dsk->vd);
}