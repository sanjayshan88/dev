#include <stdint.h>
#include "swapBits.h"

void reverse(uint8_t& n)
{
    int i=0, j=7;
    while (i < j) {
        swapBits(n, i, j);
        i++;
        j--;
    }
}