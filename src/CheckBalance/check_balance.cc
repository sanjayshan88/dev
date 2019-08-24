#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;

int checkBalance(string code)
{
	stack<char> s;
	for (int i=0; i<code.length(); i++)
	{
		if (code[i] == '(' || code[i] == '{')
		{
			s.push(code[i]);
		}
		if (code[i] == ')')
		{
			if (!s.empty())
			{
				if (s.top() != '(')
				{
					return i;
				}
				else
				{
					s.pop();
				}
			}
			else
			{
				return i;
			}
		}
        if (code[i] == '}')
        {
            if (!s.empty())
            {
                if (s.top() != '{')
                {
                    return i;
                }
				else
				{
					s.pop();
				}
            }
			else
			{
				return i;
			}
		}
	}

	if (s.empty())
		return -1;

	return code.length();
}

void test()
{
	int res = -1;

	// Test 1
    res = checkBalance("if (a(4) > 9) { foo(a(2)); }"); // returns -1
	if (res != -1) {cout << "FAIL" << endl;} else {cout << "PASS" << endl;}

	// Test 2
    res = checkBalance("for (i=0;i<a(3};i++) { foo{); }"); // returns 14
	if (res != 14) {cout << "FAIL" << endl;} else {cout << "PASS" << endl;}

	// Test 3
    res = checkBalance("while (true) foo(); }{ ()"); // returns 20
	if (res != 20) {cout << "FAIL: " << endl;} else {cout << "PASS" << endl;}

	// Test 4
    res = checkBalance("if (x) {"); // returns 8
	if (res != 8) {cout << "FAIL" << endl;} else {cout << "PASS" << endl;}
}

int main()
{
	test();
	return 0;
}
