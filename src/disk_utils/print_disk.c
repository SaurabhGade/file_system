#include "../../include/disk_utils.h"

void print_disk_info(vdisk disk){
    if(disk.vd == NULL){
        perror("UNMOUNTED DISK\n");
        return;
    }
    float mb = 1024*1024; 
    printf("DISK CAPACITY     = %0.2f MB\n"     , (float)  disk.capacity/ mb);
    printf("AVAILABLE STORAGE = %0.2f MB\n"     , (float)  disk.free/     mb);
    printf("OCCUPIED STORAGE  = %0.2f MB\n"     , (float)  disk.occupied/ mb);
    printf("CURR FILE COUNT   = %zu\n"          , (size_t) disk.file_count  );
    printf("LOGICALLY DELETED FILES = %zu\n"    , (size_t) disk.deleted     );

    // printf("\nADDITIONAL INFO\n");
    // printf("CURR SIZE BLOCK NUMBER = %lXh\n", disk.curr_size_block_number);
    // printf("CURR DATA BLOCK NUMBER = %lXh\n", disk.curr_data_block_number);
}