#include <iostream>
#include <stdint.h>
#include "reverseBits.h"

using namespace std;

void swapBits(uint8_t& n, int i, int j)
{
    // check if bits i and j differ
    if ((n >> i & 1) != (n >> j & 1)) {
        // toggle both bits
        unsigned long mask = (1 << i) | (1 << j);
        n ^= mask;
    }
}

int main()
{
    uint8_t n = 45;
    cout << "before swap: " << int(n) << endl;
    swapBits(n, 3, 4);
    cout << "after swap: " << int(n) << endl;

    reverse(n);
    cout << "after reverse: " << int(n) << endl;
    return 0;
}