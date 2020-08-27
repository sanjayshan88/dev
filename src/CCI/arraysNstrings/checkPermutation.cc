#include <iostream>
#include <string>
#include <vector>

using namespace std;

// assume ASCII string
#define NUM_ASCI_CHARS 128

bool checkPermutation(const string& s1, const string& s2)
{
    vector<int> count(NUM_ASCI_CHARS, 0);
    for (char c : s1) {
        count[c - '0']++;
    }
    for (char c : s2) {
        count[c - '0']--;
    }

    for (int i=0; i<NUM_ASCI_CHARS; i++) {
        if (count[i] != 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    string s1 = "abcd";
    string s2 = "cabd";
    string s3 = "efgh";

    cout << boolalpha << checkPermutation(s1, s2) << endl;
    cout << boolalpha << checkPermutation(s2, s3) << endl;

    return 0;
}