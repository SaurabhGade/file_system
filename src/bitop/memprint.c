#include "../../include/bitop.h"
void memprint(void *ptr, unsigned int nmemb){
  assert(ptr != NULL);
  unsigned char *p = (unsigned char*)ptr;
  unsigned char k; 
  unsigned int i;     ///letest chang (ing) -> (unsigned int)
  for (i=0; i < nmemb; i++) {
    k = 0b10000000;
    while(k >= 1){
      (*(p+i)&k)?printf("%d",1):printf("%d",0);
      k = (k >> 1);
    }
    printf(" ");
  }
  printf("\n");
  return;
}
