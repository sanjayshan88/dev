#include <iostream>
#include "ll.h"

using namespace std;

Node* insertNode(Node* head, int val)
{
    Node* temp = new Node(val);
    temp->next = head;
    head = temp;
    return head;
}

void deleteList(Node* head)
{
    Node* next = head;
    while (head != NULL) {
        next = head->next;
        delete head;
        head = next;
    }
}

void printList(Node* head)
{
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->info << " ";
        temp = temp->next;
    }
    cout << endl;
}