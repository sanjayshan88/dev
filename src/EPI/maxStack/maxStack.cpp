#include <iostream>
#include "maxStack.hpp"

using namespace std;

void maxStack::push(int item)
{
    s.push(item);

    // if item >= top of max, push to max
    if (ms.empty() || item >= ms.top()) {
        ms.push(item);
    }
}

void maxStack::pop()
{
    if (s.empty()) {
        return;
    }

    if (ms.top() == s.top()) {
        s.pop();
        ms.pop();
    } else {
        s.pop();
    }
}

int maxStack::peek(int &status)
{
    if (s.empty()) {
        status = FAILURE;
        return -1;
    }

    status = SUCCESS;
    return s.top();
}

int maxStack::max(int &status)
{
    if (s.empty()) {
        status = FAILURE;
        return -1;
    }

    status = SUCCESS;
    return ms.top();
}

int main() {

    maxStack s;
    int status;

    s.push(20);
    s.push(10);
    s.push(30);
    
    cout << "max: " << s.max(status) << " status: " << status << endl;

    s.pop();
    cout << "max: " << s.max(status) << " status: " << status << endl;
    s.pop();
    cout << "max: " << s.max(status) << " status: " << status << endl;
    s.pop();
    cout << "max: " << s.max(status) << " status: " << status << endl;

    return 0;
}