#include <iostream>
using namespace std;

int main() {
  int num[] = {1,2,3,4,5,6};
  int* p1 = num;
  int* p2 = p1 + 5;

  cout << (char*)p2 - (char*)p1 << endl;
  
  return 0;
}