#include <iostream>
using namespace std;

int main() {
  typedef int x[2];
  x myArray[3] = {1,2,3,4};
  cout << sizeof(myArray) << endl;
  cout << myArray[1][0] << endl;
}