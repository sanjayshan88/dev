#ifndef MAXSTACK_HPP
#define MAXSTACK_HPP

#include <stack>
using namespace std;

#define SUCCESS 0
#define FAILURE 1

class maxStack {
public:
    void push(int item);
    void pop();
    int peek(int &status);
    int max(int &status);

private:
    stack<int> s;
    stack<int> ms;
};

#endif