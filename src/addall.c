#include "../include/disk_utils.h"
int main(int argv, char **argc){
    if(argv <= 1){
        printf("PROVIDE DISK PATH\n");
        return -1;
    }
    if(argv <= 2){
        printf("PROVIDE FILE PATH WHICH CONTAIN FILE PATHS LINE BY LINE\n");
        return -2;
    }
    vdisk dsk = mount_vdisk(argc[1]);
    add_all_file(&dsk, argc[2]); 
    return 0;
}