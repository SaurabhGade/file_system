#include "../../include/bitop.h"
void clr_bit(void *bit_vec, unsigned int nmemb, unsigned int i){
  assert(i < (nmemb*8));      // i must be less than nmemb*8 , i.e i should be in rang 0 - nmemb*8-1.
  unsigned char *buff = (unsigned char*)bit_vec;
  
  unsigned int kth_byte = (nmemb-1)-(i/8);
  unsigned int kth_bit = 7-(i%8);

  buff += kth_byte;
  *buff &= ~(0x80 >> kth_bit); 
}
