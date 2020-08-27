#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <bitset>

using namespace std;

// assume ASCII string
#define NUM_ASCII_CHARS 128

/* Is Unique: 
 * Implement an algorithm to determine if a string has all * unique characters. What if you
 * cannot use additional data structures?
 */

/* process each character and store in a set
 * if a character is already in the set, return false
 */
bool isUnique(const string& s)
{
    set <char> set;
    for (char c : s) {
        if (set.find(c) != set.end()) {
            return false;
        }
        set.insert(c);
    }
    return true;
}

/* use a vector of bools to store info about characters
 * that are seen
 * Time complexity - O(n)
 * Space complexity - O(1)
 */
bool isUniqueChars(const string& s)
{
    if (s.length() > NUM_ASCII_CHARS) {
        return false;
    }
    vector <bool> found(NUM_ASCII_CHARS, false);
    for (char c : s) {
        if (found[c - '0']) {
            return false;
        }
        found[c - '0'] = true;
    }
    return true;
}

/* use a bitset to reduce the space usage by a factor of 8
 */
bool isUniqueCharsBitset(const string& s)
{
    bitset<NUM_ASCII_CHARS> bits(0);
    for (char c : s) {
        if (bits.test(c - '0') > 0) {
            return false;
        }
        bits.set(c - '0');
    }
    return true;
}

/* compare every character of the string with every other   * character
 * Time complexity - O(n^2)
 * Space complexity - O(1)
 */
bool isUniqueCharsNoDS(const string& s)
{
    for (int i=0; i<s.length()-1; i++) {
        for (int j=i+1; j<s.length(); j++) {
            if (s[i] == s[j]) {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    string s1 = "abcd";
    string s2 = "abb";

    cout << s1 << ": " << boolalpha << isUnique(s1) <<endl;
    cout << s2 << ": " << boolalpha << isUnique(s2) <<endl << endl;
    
    cout << s1 << ": " << boolalpha << isUniqueChars(s1) <<endl;
    cout << s2 << ": " << boolalpha << isUniqueChars(s2) <<endl << endl;
    
    cout << s1 << ": " << boolalpha << isUniqueCharsBitset(s1) <<endl;
    cout << s2 << ": " << boolalpha << isUniqueCharsBitset(s2) <<endl << endl;
    
    cout << s1 << ": " << boolalpha << isUniqueCharsNoDS(s1) <<endl;
    cout << s2 << ": " << boolalpha << isUniqueCharsNoDS(s2) <<endl << endl;
    
    return 0;
}