#include <iostream>

using namespace std;

int main() {
  struct emp {
    string name;
    unsigned int sal;
    void TestDisp() {
      cout << name << " " << sal << endl;
    }
  };
  struct emp e1;
  e1.name = "abcd";
  e1.sal = 100;
  e1.TestDisp();

  return 0;
}