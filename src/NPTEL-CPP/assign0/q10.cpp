#include <iostream>
using namespace std;

void func(int a) {
  cout << "val of a is: " << a << endl;
}

int main() {
  void (*fun_ptr1)(int) = func;
  void (*fun_ptr2)(int) = &func;
  /* incorrect way to declare */
  //void (*fun_ptr3) = func;
  /* incorrect way to declare */
  //void (*fun_ptr4) = &func;

  return 0;
}