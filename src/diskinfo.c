#include "../include/disk_utils.h"
int main(int argv, char **argc){
    if(argv <= 1){
        printf("PROVIDE PATH OF THE VD IMAGE\n");
        return -1;
    }
    vdisk dsk = mount_vdisk(argc[1]);
    print_disk_info(dsk);

    unmount_disk(&dsk);
    return 0;
}