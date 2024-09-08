#include "../../include/disk_utils.h"
bool add_all_file(vdisk *dsk, char *path){
    assert(dsk->vd != NULL);
    assert(path != NULL);
    char buff[50] = {0};
    FILE *ptr = fopen(path, "r");
    if(ptr == NULL){
        printf("NO SUCH PATH FILE\n");
        return false; 
    }
    while((fscanf(ptr, "%s", buff)) && !feof(ptr)){
        printf("%s", buff);
        if(add_file(dsk, buff)){
            printf(" INSERTED\n");
        }else{
            printf("NOT INSERTED\n");
        }
    }
    return true;
}