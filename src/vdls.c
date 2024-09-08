#include "../include/disk_utils.h" 
int main(int argv , char **argc){
    if(argv <= 1){
        printf("PROVIDE DISK IMAGE\n");
        return -1;
    }
    vdisk dsk = mount_vdisk(argc[1]);
    if(dsk.vd == NULL){
        printf("NO SUCH FILE DIST\n");
        return -2;
    }
    list_file(dsk);
    unmount_disk(&dsk);
    return 0;
}