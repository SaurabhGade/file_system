// this function make virtual disk of given size (in MB)
/*
    parems:
        vd_title size(MB)
    return -1 if disk creation failed.
*/
#include<stdio.h>
#include "../include/disk_utils.h"

int main(int argv, char **argc){
    if(argv <= 1){
        return -1;
    }
    if(argv <= 2){
        return -2;
    }
    size_t size; 
    sscanf(argc[2], "%zu" , &size);
    if(size > 100){ printf("initial size limit = 100MB (ABORTED) \n"); return -3;} 

    if(!create_vdisk(argc[1], size*1024*1024)){
        printf("DISK CREATION FAILED\n");
        return -3;
    }

    printf("DISK CREATED\nSIZE = %zuMB\n", size);
    return 0;    
}
