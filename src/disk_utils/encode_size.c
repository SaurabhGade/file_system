#include "../../include/disk_utils.h"


void* encode_size(size_t num, size_t *enc_seq_size){
  void *buff;
  if(num > 3){
    unsigned int bit_count = 0;
    size_t byte_count = 0;
    unsigned short limiter = 1;
    unsigned int counter = 0;
    unsigned long t = num;
    unsigned char arr[32];
    unsigned char size, val;
    int i = 0;
    while(t > 2){
      bit_count += (log2(t)+1)+limiter;
      t = log2(t)+1;
      arr[i] = t;
      i++;
    }
    byte_count = (bit_count / 8) + !(!bit_count % 8);
    buff = malloc(byte_count);
    *enc_seq_size = byte_count;
    i-=1; 
    while(i > 0){
      size = arr[i];
      val = arr[i-1];
      val <<= 8-size;
      for(int j = 7; j >= 8-size; j--){
        (is_bit_set(&val, 1, j))? 
          set_bit(buff, byte_count, FROM_MSB(byte_count, counter)): 
          clr_bit(buff, byte_count, FROM_MSB(byte_count, counter));
        counter+=1;
      }
      (i == 1)? 
        set_bit(buff, byte_count, FROM_MSB(byte_count, counter)):
        clr_bit(buff, byte_count, FROM_MSB(byte_count, counter));
      counter+=1;
      i-=1;
    }
    i = 0;
    t = num;
    rv_endiannes(&t, sizeof(t));
    lft_shift(&t, sizeof(t), (sizeof(t)*8)-arr[0]);

    for(; i < arr[0] ; i++){
      (is_bit_set(&t, sizeof(t), FROM_MSB(sizeof(t), i)))?
        set_bit(buff, byte_count, FROM_MSB(byte_count, counter)): 
        clr_bit(buff, byte_count, FROM_MSB(byte_count, counter));
      counter+=1;
    }
  }
  else {
    buff = malloc(1);
    //0 -> 01100000
    //1 -> 01110000
    //2 -> 11011000
    //3 -> 10111000
    if(num == 0) *(unsigned char*)buff = 0b01100000;
    else if(num == 1) *(unsigned char*)buff = 0b01110000;
    else if(num == 2) *(unsigned char*)buff = 0b10110000;
    else *(unsigned char*)buff = 0b10111000;
    *enc_seq_size = 1;
  }
  return buff;

}