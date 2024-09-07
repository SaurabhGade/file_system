#include "../../include/disk_utils.h"

struct sequence seq;
void set_seq(size_t num){
    if(num < 4){
        seq.arr[0] = 2;
        seq.arr[1] = 3;
        seq.bit_count += 6;
        seq.counter = 1;
        return;
    }
    set_seq(log2(num)+1);
    seq.counter += 1;
    seq.bit_count += num+LIMITER;
    seq.arr[seq.counter] = num;
    return;
}
