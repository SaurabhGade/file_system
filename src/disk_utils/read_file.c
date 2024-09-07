/*
  read_file:
    parems: struct vdisk, unsigned value indicating file number > 0
    returns char array.
*/
#include "../../include/disk_utils.h"
char* read_file(vdisk disk, size_t num){
  assert(disk.vd != NULL);

  if (num == 0 || disk.file_count < num){
    return NULL;
  }
  unsigned char buff[MAX_LEN];
  rewind(disk.vd);
  fseek(disk.vd, FIRST_SIZE_SEQ, SEEK_SET);
  
  return NULL;
}