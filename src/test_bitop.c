#include "../include/bitop.h"
#include <stdio.h>
#include <stddef.h>
int main(int argc, char const *argv[]){
  size_t k = 0xfffffffffffffffe;
  rv_endiannes(&k, sizeof(k));
  memprint(&k, sizeof(k));
  printf("EVERYTHING WORKING IN BITOP\n"); 
  return 0;
}
