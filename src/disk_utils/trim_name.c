#include "../../include/disk_utils.h"
void trim_fname(char *dst, char *src){
    assert(dst != NULL);
    assert(src != NULL);
    int start = strlen(src);
    int cnt = 0;
    while(start >= 0 && src[start] != '/'){
        start--;
        cnt++;
    }
    if(cnt > MAX_FILE_NAME_LEN) cnt = MAX_FILE_NAME_LEN;
    strncpy(dst, src+start+1, cnt);
    return;
}