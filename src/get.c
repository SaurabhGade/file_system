#include "../include/disk_utils.h"
int main(int argv, char ** argc){
    if(argv <= 1){
        printf("PROVIDE VDISK AND FILE NAME\n");
        return -1;
    }
    if(argv <= 2){
        printf("PROVIDE FILE NAME\n");
    }
    vdisk dsk = mount_vdisk(argc[1]);
    if(get_file(dsk, argc[2])){
        printf("FILE EXTRACTED\n");
    }
    return 0;
}
