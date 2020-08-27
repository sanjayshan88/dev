#include <iostream>

using namespace std;

void URLify(char *str, int len)
{
    int new_len = 0;
    for (int i=0; i<len; i++) {
        if (str[i] == ' ') {
            new_len += 3;
        } else {
            new_len++;
        }
    }
    int i = len-1;
    int j = new_len-1;
    while (i >= 0 && j >= 0) {
        if (str[i] == ' ') {
            str[j--] = '0';
            str[j--] = '2';
            str[j--] = '%';
        } else {
            str[j--] = str[i];
        }
        i--;
    }
}

int main()
{
    char str[] = "Mr John Smith    ";
    cout << "Original string: " << str << endl;
    URLify(str, 13);
    cout << "URLified string: " << str << endl;

    return 0;
}