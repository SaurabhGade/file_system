/*
  FILE *vd;         // file pointer pointing to the disk image.
  size_t capacity;  // read first 8 byte from the disk which indicate disk capacity.
  size_t free;      // next 8 byte stores the number of free bytes in the disk.
  size_t occupied ; // next 8 byte stores the number of occupied block in the disk.
  size_t curr_size_block_number;    //contain block index which is currently free to store size
  size_t curr_data_block_number;    //contain block index which is currently free to store data.
  size_t file_count;              //number of file currently in the disk.

*/

#include "../../include/disk_utils.h"

/*
    create virtual disk 
    perems:
      char array path, disk size.
    return:
      returns true if disk creation success else return false.
*/
bool create_vdisk(char *path, size_t ndiskb){
    assert(path != NULL);
    FILE *vd = fopen(path, "w");
    size_t temp = ndiskb;

    if(vd == NULL){
        return false;
    }
    while(temp){
        fprintf(vd, "%c", 0);
        temp--;
    }
    
    rewind(vd);  // Move file pointer at the starting of the vdisk.

    // Initial capacity of the disk.      first 8 bytes.
    temp = ndiskb;
    fwrite(&temp, sizeof(size_t), 1, vd);

    // Initila free space in the disk.    next 8 bytes.
    temp = ndiskb-48; 
    fwrite(&temp, sizeof(size_t), 1, vd);

    // Initila occupied space in the disk.
    temp = 48;
    fwrite(&temp, sizeof(size_t), 1, vd); 

    // Initial file count in the disk.
    temp = 0;
    fwrite(&temp, sizeof(size_t), 1, vd); 

    // curr_size_block_number
    temp = 48; 
    fwrite(&temp, sizeof(size_t), 1, vd); 

    // curr_data_block_number
    temp = ndiskb-1; 
    fwrite(&temp, sizeof(size_t), 1, vd); 

    fclose(vd);
    return true;
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
