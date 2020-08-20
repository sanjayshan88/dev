#include <iostream>

using namespace std;

int countBits(int n)
{
    int count = 0;
    while (n) {
        // check if each bit is 1 or 0
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int countBitsOptimized(int n)
{
    int count = 0;
    while (n)
    {
        // clear the rightmost set bit
        n &= n-1;
        count++;
    }
    return count;
}

int main()
{
    cout << countBits(99) << endl;
    cout << countBitsOptimized(99) << endl;

    return 0;
}