#ifndef __BITOP_H_
#define __BITOP_H_

#include "/usr/include/assert.h"
#include "/usr/include/printf.h"
#include "/usr/include/malloc.h"
#include "/usr/include/string.h"
#include "/usr/include/math.h"


//map (0 - memb*8-1) -> (nmemb*8-1 - 0);
#define FROM_MSB(byte_count, counter) (byte_count)*(8)-(counter+1)

typedef enum {
  false , true
} bool;

void memprint(void* buff, unsigned int nmemb);
void rv_endiannes(void* buff, unsigned int nmemb);
void lft_shift(void* buff, int nmemb, int shift_count);
void rht_shift(void* buff, int nmemb, int shift_count);
void set_bit(void *bit_vec, unsigned int nmemb, unsigned int i);
void clr_bit(void *bit_vec, unsigned int nmemb, unsigned int i);
bool is_bit_set(void *bit_vec, unsigned int nmemb, unsigned int i);



#endif //__BITOP_H_
