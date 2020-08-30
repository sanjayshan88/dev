#include <iostream>
#include "threeInOne.h"

using namespace std;

MultiStack::MultiStack(int capacity)
        : m_capacity(capacity)
{
    // allocate memory for tos
    tos = new int(num_stacks);
    // initialize tos
    for (int i=0; i<num_stacks; i++) {
        tos[i] = - 1;
    }
    // allocate memory for multi stack
    s = new int(num_stacks * m_capacity);
}

MultiStack::~MultiStack()
{
    delete[] tos;
    delete[] s;
}

void MultiStack::push(int stack_num, int val)
{
    if (isFull(stack_num)) {
        cout << "ERROR: Stack is already full" << endl;
    } else {
        s[++tos[stack_num]] = val;
    }
}

void MultiStack::pop(int stack_num)
{
    if (isEmpty(stack_num)) {
        cout << "ERROR: Stack is already empty" << endl;
    } else {
        s[tos[stack_num]--] = 0;
    }
}

int MultiStack::top(int stack_num) const
{
    if (isEmpty(stack_num)) {
        throw "ERROR: Stack is already empty";
    }
    return s[tos[stack_num]];
}

bool MultiStack::isFull(int stack_num) const
{
    return tos[stack_num] == m_capacity - 1;
}

bool MultiStack::isEmpty(int stack_num) const
{
    return tos[stack_num] == -1;
}

int main()
{
    MultiStack s(4);

    // stack 1
    s.push(0, 1);
    s.push(0, 2);
    cout << s.top(0) << endl;

    // stack 2
    s.push(1, 11);
    s.pop(1);
    cout << boolalpha << s.isEmpty(1) << endl;

    // stack 3
    s.push(2, 21);
    s.push(2, 22);
    s.push(2, 23);
    s.push(2, 24);

    cout << boolalpha << s.isFull(2) << endl;

    return 0;
}