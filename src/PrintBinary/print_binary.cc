#include <iostream>
#include <string>
using namespace std;

/*
pB(3)
 0 + pB(2)
	  0 + pB(1)
	  1 + pB(1)
		   0 + pB(0)
		   1 + pB(0)
 1 + pB(2)

000
001
010
011

100
101
110
111
*/

void printBinaryHelper(int numDigits, string output)
{

	if (numDigits == 0) {
		cout << output << endl;
		return;
	}

	printBinaryHelper(numDigits - 1, output + "0");
	printBinaryHelper(numDigits - 1, output + "1");
}

void printBinary(int numDigits)
{

	printBinaryHelper(numDigits, "");	
}

int main()
{

	printBinary(3);

	return 0;
}
