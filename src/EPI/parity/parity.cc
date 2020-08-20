#include <iostream>
using namespace std;

int parity(unsigned long n)
{
    int result = 0;
    while (n) {
        // clear the rightmost set bit
        n &= n-1;
        result ^= 1;
    }
    return result;
}

int main()
{
    cout << parity(10) << endl;
    cout << parity(11) << endl;
    
    int x = 12;
    x &= ~(x-1);
    cout << x << endl;
    return 0;
}