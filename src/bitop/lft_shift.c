#include "../../include/bitop.h"
void lft_shift(void *buff, int nmemb, int shift_count){
  if (shift_count == 0) return; // No shifting needed

  unsigned char *array = (unsigned char*)buff; 

  for (int shift = 0; shift < shift_count; shift++) {
    unsigned char carry = 0; // To carry the bit that overflows
    for (int i = nmemb - 1; i >= 0; i--) {
      // Save the most significant bit of the current byte
      unsigned char new_carry = (array[i] & 0x80) ? 1 : 0;

      // Shift the current byte to the left and add the carry from the previous byte
      array[i] = (array[i] << 1) | carry;

      // Update the carry
      carry = new_carry;
    }
  }
}

