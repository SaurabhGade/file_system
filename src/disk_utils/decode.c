#include "../../include/disk_utils.h"

dec_seq decode(void *src){
    assert(src != NULL);
    size_t size = 2;
    size_t val = 0;
    long long counter = -1;
    bool flag = true;
    
    //compute the size of the data.
    while(flag){
        for(int i = size-1; i >= 0; i--){
            counter += 1;
            if(is_bit_set(src, 0xffff, FROM_MSB(0xffff ,counter)))
                val += pow(2, i);
        }
        size = val;
        val = 0;
        counter += 1;
        flag = is_bit_set(src, 0xffff, FROM_MSB(0xffff, counter))? false : true;
    }
    size_t data_size = size/BYTE_SIZE + !(!size%BYTE_SIZE); 

   dec_seq dec; 
    dec.buff = malloc(data_size);
    dec.size = data_size;
    for(size_t i= 0 ; i < size; i++){           //modify: int-> size_t
        counter += 1;
        is_bit_set(src, 0xffff, FROM_MSB(0xffff, counter))?
        set_bit(dec.buff, data_size, FROM_MSB(data_size, i)):
        clr_bit(dec.buff, data_size, FROM_MSB(data_size, i));
    }
    return dec;
}