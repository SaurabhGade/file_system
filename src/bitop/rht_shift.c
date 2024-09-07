#include "../../include/bitop.h"
void rht_shift(void *buff, int nmemb,  int shift_count){
  if(shift_count == 0)      // No any shift required.
    return;
  
  unsigned char *arr = (unsigned char*)buff;
  unsigned char carry ;
  unsigned char new_carry; 

  for(int shift = 0; shift < shift_count; shift++){
    carry = 0;
    for(int i = 0; i < nmemb; i++){
      new_carry = (arr[i] & 0x1)? 0x80: 0;   // save the previous carry, i.e. LSB of the current byte.
      arr[i] = (arr[i] >> 1) | carry;     // shift current byte by 1 and place carry at the end.kk 
      carry = new_carry;
    }
  }
}
