#ifndef MYSETINT_HPP
#define MYSETINT_HPP

using namespace std;

class HashNode {
public:
    HashNode(int val) {
        info = val;
        next = NULL;
    }
    int info;
    HashNode* next;
};

class mySetInt {
public:
    mySetInt();
    ~mySetInt();
    void add(int item);
    bool contains(int item);
    void remove(int item);
    void printHashTable();
    
private:
    int hashCode(int item);
    HashNode** hashTable;
    int capacity;
};

#endif