#include <iostream>
using namespace std;

/*
 * Weight of a non-negative integer is the number of bits
 * that are set to 1 in its binary representation
 */
unsigned long closestIntSameWeight(unsigned long n)
{
    const int k_num_bits = 64;

    for (int i=0; i<k_num_bits-1; i++) {
        if (((n >> i) & 1) != ((n >> (i+1)) & 1)) {
            // swap bits i and i+1
            n ^= (1UL << i) | (1UL << (i+1));
            return n;
        }
    }
    throw invalid_argument("All bits are 0 or 1");
}

int main()
{
    unsigned long n = 6;
    cout << closestIntSameWeight(n) << endl;
    n = 92;
    cout << closestIntSameWeight(n) << endl;
    return 0;
}