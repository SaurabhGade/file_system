#include "../../include/bitop.h"
void rv_endiannes(void *buff, unsigned int nmemb){

  unsigned char ptr = 0;
  unsigned char *i = (buff);
  unsigned char *j = (buff+nmemb-1);
  while(i < j){
    memcpy(&ptr, i, 1);
    memcpy(i, j, 1);
    memcpy(j, &ptr, 1);
    i += 1;
    j -= 1;
  }
}
