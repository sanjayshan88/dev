#include <iostream>
#include <cmath>
#include "mySetInt.hpp"

using namespace std;

mySetInt::mySetInt()
{
    capacity = 17; // should be a prime number
    hashTable = new HashNode*[capacity];
}

mySetInt::~mySetInt()
{
    delete[] hashTable;
}

void mySetInt::add(int item)
{
    // prevent duplicates
    if (contains(item)) {
        return;
    }

    int hash = hashCode(item);
    HashNode* newNode = new HashNode(item);
    newNode->next = hashTable[hash];
    hashTable[hash] = newNode;
}

bool mySetInt::contains(int item)
{
    int hash = hashCode(item);
    HashNode* temp = hashTable[hash];
    while (temp != NULL) {
        if (temp->info == item) {
            return true;
        }
        temp = temp->next;
    }

    return false;
}

void mySetInt::remove(int item)
{
    if (!contains(item)) {
        return;
    }
    int hash = hashCode(item);
    HashNode* temp = hashTable[hash];
    // first element in list
    if (temp->info == item) {
        hashTable[hash] = temp->next;
        temp->next = NULL;
        delete temp;
        return;
    }

    HashNode* prev = NULL;
    while (temp != NULL) {
        if (temp->info == item) {
            prev->next = temp->next;
            temp->next = NULL;
            delete temp;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

int mySetInt::hashCode(int item)
{
    return abs(item) % capacity;
}

void mySetInt::printHashTable()
{
    for (int i=0; i<capacity; i++) {
        HashNode *temp = hashTable[i];
        cout << "i: " << i << " | ";
        while (temp != NULL) {
            cout << temp->info << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main() {

    mySetInt s;
    s.add(11);
    s.add(7);
    s.add(54);
    s.add(14);
    s.add(49);
    s.add(11);
    s.add(24);

    s.printHashTable();

    cout << "contains 7: " << s.contains(7) << endl;
    cout << "contains 10: " << s.contains(10) << endl;
  
    s.remove(24);
    s.remove(49);
    s.printHashTable();

    return 0;
}