#include <iostream>
#include "ll.h"

using namespace std;

Node* partition(Node* head, int val)
{
    Node* curr = head;
    Node* prev = nullptr;

    while (curr && curr->info != val) {
        prev = curr;
        curr = curr->next;
    }

    while (curr != NULL) {
        if (curr->info < val) {
            // insert front
            head = insertNode(head, curr->info);

            // delete
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}

int main()
{
    Node* head = insertNode(NULL, 1);
    head = insertNode(head, 2);
    head = insertNode(head, 10);
    head = insertNode(head, 5);
    head = insertNode(head, 8);
    head = insertNode(head, 5);
    head = insertNode(head, 3);

    cout << "Original list: " << endl;
    printList(head);

    head = partition(head, 5);

    cout << "List after partition: " << endl;
    printList(head);

    return 0;
}