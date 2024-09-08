/*
  read_file:
    parems: vdisk disk, char *file_name
    store named file in current directory if exist in vdisk. 

    NOTE: if file already exist in same directory the overwrite its contain.
*/
#include "../../include/disk_utils.h"
bool get_file(vdisk disk, char *file_name){
  assert(disk.vd != NULL);
  assert(file_name != NULL);
  long long file_size = 0;
  file_size = search_file_name(disk, file_name);
  if(file_size <= 0){
    printf("NO SUCH FILE EXIST\n");
    return false; 
  }
  // if file exist then file pointer size to first byte of file data.

  FILE *ptr = fopen(file_name, "w");
  if(ptr == NULL){
    printf("INTERNAL ERROR UNABLE TO CREATE FILE\n");
    return false;
  }
  char buff[1];
  while(file_size > 0){
    fread(buff, 1, sizeof(char), disk.vd);
    fwrite(buff, 1, sizeof(char), ptr);
    file_size--;
  }  
  return true;
}