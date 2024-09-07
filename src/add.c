#include<stdio.h>
#include "../include/disk_utils.h"

int main(int argv, char ** argc){
    if(argv <= 1){
       printf("PROVIDE DISK AND FILE PATH\n");
       return -1; 
    }else if(argv <= 2){
        printf("PROVIDE FILE PATH\n");
        return -2;
    }

    vdisk disk = mount_vdisk(argc[1]);

    for(int i = 2; i < argv; i++){
        if(add_file(&disk, argc[i])){
            printf("INSERTION SUCCESSFUL\n");
        }else{
            printf("INSERTION FAILED\n");
        }
    }

    unmount_disk(&disk);
    return 0;
}