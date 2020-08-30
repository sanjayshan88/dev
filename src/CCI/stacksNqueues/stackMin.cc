#include <iostream>
#include <stack>
#include "stackMin.h"

using namespace std;

void StackMin::push(int val)
{
    s1.push(val);
    if (s2.empty() || val <= s2.top()) {
        s2.push(val);
    }
}

void StackMin::pop()
{
    if (s1.empty()) {
        return;
    }
    if (!s2.empty() && s1.top() == s2.top()) {
        s2.pop();
    }
    s1.pop();
}

int StackMin::top() const
{
    if (s1.empty()) {
        throw "ERROR: Stack is empty!";
    }
    return s1.top();
}

int StackMin::min() const
{
    if (s1.empty()) {
        throw "ERROR: Stack is empty!";
    }
    return s2.top();
}

bool StackMin::isEmpty() const
{
    return s1.empty();
}

int main()
{
    StackMin s;
    for (auto v : {5, 10, 4, 9, 3, 3, 8, 2, 2, 7, 6})
    {
        s.push(v);
        cout << "Pushed value: " << v << ", min value: " << s.min() << endl;
    }

    while (!s.isEmpty())
    {
        auto v = s.top();
        s.pop();
        cout << "Popped value: " << v;
        if (s.isEmpty())
            cout << ", stack is empty" << endl;
        else
            cout << ", min value: " << s.min() << endl;
    }
    return 0;
}