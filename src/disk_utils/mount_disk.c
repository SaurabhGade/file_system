#include "../../include/disk_utils.h"

vdisk mount_vdisk(char *path){
    assert(path != NULL);
    vdisk dsk = {.vd = NULL, .capacity = 0, .free = 0, .occupied = 0, .curr_data_block_number = 0,
            .curr_size_block_number = 0, .file_count = 0};
    dsk.vd = fopen(path, "r+");
    if(dsk.vd == NULL){
        perror("NO SUCH FILE OR DIRECTORY...DISK CANNOT BE MOUNTED\nABORTED\n");
        assert(dsk.vd != NULL);        
    }
    size_t disk_info;

    // read disk capacity;
    fread(&disk_info, sizeof(disk_info), 1, dsk.vd); 
    dsk.capacity = disk_info;

    // read free bytes in the disk.
    fread(&disk_info, sizeof(disk_info), 1, dsk.vd); 
    dsk.free = disk_info;

    // read occupied bytes in the disk.
    fread(&disk_info, sizeof(disk_info), 1, dsk.vd); 
    dsk.occupied = disk_info;

    // read file_count in the disk.
    fread(&disk_info, sizeof(disk_info), 1, dsk.vd); 
    dsk.file_count = disk_info;

    // read logically deleted files in the disk.
    fread(&disk_info, sizeof(size_t), 1, dsk.vd); 
    dsk.deleted = disk_info;

    // read curr_size_block_number
    fread(&disk_info, sizeof(disk_info), 1, dsk.vd); 
    dsk.curr_size_block_number = disk_info;

    // read curr_data_block_number
    fread(&disk_info, sizeof(disk_info), 1, dsk.vd); 
    dsk.curr_data_block_number = disk_info;

    // file pointer pointing to the first size_block_number.ss
    rewind(dsk.vd);
    fseek(dsk.vd, dsk.curr_size_block_number, SEEK_SET);

    if(dsk.curr_size_block_number > dsk.curr_data_block_number){
      printf("BROKEN FILE SYSTEM\nFORMET AND TRY AGAIN\n");
      unmount_disk(&dsk);
      exit(0);
    }
    return dsk;
    
}
/*
  *** note : first 48 bytes contain essential info. about disk.  
  ***      : i.e capacity , free, occupied, file_count, current size block and curr data block. 

  FILE *vd;         // file pointer pointing to the disk image.
  size_t capacity;  // read first 8 byte from the disk which indicate disk capacity.
  size_t free;      // next 8 byte stores the number of free bytes in the disk.
  size_t occupied ; // next 8 byte stores the number of occupied block in the disk.
  size_t file_count;              //number of file currently in the disk.
  size_t curr_size_block_number;    //contain block index which is currently free to store size
  size_t curr_data_block_number;    //contain block index which is currently free to store data.

*/
