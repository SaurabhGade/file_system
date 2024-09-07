#include "../../include/disk_utils.h"

void unmount_disk(vdisk *dsk){
  if(dsk->vd == NULL){
    return ;
  }
  dsk->capacity = dsk->curr_data_block_number = dsk->curr_size_block_number = dsk->file_count = dsk->free = dsk->occupied = 0; 
  fclose(dsk->vd);
}