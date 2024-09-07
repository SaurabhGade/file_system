#include "../../include/disk_utils.h"
size_t encode(void *res, size_t rnmemb, void *src, size_t snmemb){

  assert(res != NULL);
  assert(src != NULL);
  if(seq.counter == 0){
    printf("struct seq is not set\n");
    return 0;
  }
  long long counter = -1;
  size_t i = 0;           

  size_t size;
  size_t val;
  while(i < seq.counter){
    size = seq.arr[i];
    val = seq.arr[i + 1];
    rv_endiannes(&val, sizeof(val));
    lft_shift(&val, sizeof(val), (sizeof(val) * BYTE_SIZE) - size % (sizeof(val) * BYTE_SIZE));
    for (size_t j = 0; j < size % (sizeof(val) * BYTE_SIZE); j++){
      counter += 1;
      is_bit_set(&val, sizeof(val), FROM_MSB(sizeof(val), j))?
        set_bit(res, rnmemb, FROM_MSB(rnmemb, counter)):
        clr_bit(res, rnmemb, FROM_MSB(rnmemb, counter));
    }
    counter += 1;
    clr_bit(res, rnmemb, FROM_MSB(rnmemb, counter));        //intermidate bit separating size = 0
    i++;
  }
  set_bit(res, rnmemb, FROM_MSB(rnmemb, counter));            //intermimdate bit separating data = 1
  i = 0; 
  while(i < snmemb*BYTE_SIZE){
    counter += 1;
    is_bit_set(src, snmemb, FROM_MSB(snmemb, i))?
      set_bit(res, rnmemb, FROM_MSB(rnmemb, counter)):
      clr_bit(res, rnmemb, FROM_MSB(rnmemb, counter));
    i+=1;
  }
  return rnmemb;
}
