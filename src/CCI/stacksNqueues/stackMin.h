#pragma once
#include <stack>

using namespace std;

class StackMin
{
public:
    StackMin() {}
    ~StackMin() {}
    void push(int val);
    void pop();
    int top() const;
    int min() const;
    bool isEmpty() const;
private:
    // stack of all integers
    stack<int> s1;
    // stack of min integers
    stack<int> s2;
};