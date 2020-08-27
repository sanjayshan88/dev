#include <iostream>
#include <string>

using namespace std;

bool isPermutationPalindrome(string& s)
{
    int bit_vector = 0;
    int pos = 0;
    for (char c : s) {
        if (!isalpha(c))
            continue;
        pos = tolower(c) - 'a';
        int mask = (1 << pos);
        bit_vector ^= mask;
    }
    return ((bit_vector & (bit_vector - 1)) == 0);
}

int main()
{
    string s = "abab";
    cout << boolalpha << isPermutationPalindrome(s) << endl;
    s = "ab c";
    cout << boolalpha << isPermutationPalindrome(s) << endl;
    s = "Rats live on no evil star";
    cout << boolalpha << isPermutationPalindrome(s) << endl;
    s = "Tact Coa";
    cout << boolalpha << isPermutationPalindrome(s) << endl;
    
    return 0;
}