#include <iostream>
#include "ll.h"

using namespace std;

void deleteMiddle(Node*& node)
{
    node->info = node->next->info;
    Node* next = node->next;
    node->next = node->next->next;
    delete next;
}

int main()
{
    Node* head = insertNode(NULL, 10);
    head = insertNode(head, 20);
    head = insertNode(head, 30);
    head = insertNode(head, 40);
    head = insertNode(head, 50);

    cout << "Original list: " << endl;
    printList(head);

    deleteMiddle(head->next->next);

    cout << "List after delete middle: " << endl;
    printList(head);

    return 0;
}