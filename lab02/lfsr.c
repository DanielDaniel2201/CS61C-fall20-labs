#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "lfsr.h"
#include "bit_ops.c"

int next_head(uint16_t *reg) {
    unsigned x = get_bit(*reg, 0);
    x ^= get_bit(*reg, 2);
    x ^= get_bit(*reg, 3);
    x ^= get_bit(*reg, 5);
    return x;
}

void lfsr_calculate(uint16_t *reg) {
    /* YOUR CODE HERE */
    int head = next_head(reg);
    // right shift the reg and MSB is now 0
    (*reg) = (*reg) >> 1;
    // plug in the rightmost bit of head to the leftmost position of reg
    (*reg) = (*reg) | (head << 15);
}


