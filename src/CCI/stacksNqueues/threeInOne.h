#pragma once

class MultiStack
{
public:
    MultiStack(int capacity);
    ~MultiStack();
    void push(int stack_num, int val);
    void pop(int stack_num);
    int top(int stack_num) const;
    bool isFull(int stack_num) const;
    bool isEmpty(int stack_num) const;
private:
    // number of stacks
    int num_stacks = 3;
    // capacity of each stack
    int m_capacity;
    // pointer to multi stack
    int *s;
    // pointer to top of stacks
    int *tos;
};