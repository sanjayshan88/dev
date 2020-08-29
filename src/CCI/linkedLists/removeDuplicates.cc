#include <iostream>
#include <unordered_set>
#include "ll.h"

using namespace std;

Node* removeDuplicates(Node* head)
{
    unordered_set<int> set;
    Node* temp = head;
    Node* prev = NULL;
    while (temp != NULL) {
        int val = temp->info;
        if (set.find(val) == set.end()) {
            set.insert(val);
            prev = temp;
            temp = temp->next;
        } else {
            prev->next = temp->next;
            delete temp;
            temp = prev->next;
        }
    }
    return head;
}

Node* removeDuplicatesNoBuffer(Node* head)
{
    Node* curr = head;
    while (curr != NULL) {
        Node* prev = curr;
        Node* runner = curr->next;
        while (runner != NULL) {
            if (curr->info == runner->info) {
                prev->next = runner->next;
                delete runner;
                runner = prev->next;
            } else {
                prev = runner;
                runner = runner->next;
            }
        }
        curr = curr->next;
    }
    return head;
}

int main()
{
    Node* head = new Node(10);
    head = insertNode(head, 20);
    head = insertNode(head, 30);
    head = insertNode(head, 20);

    cout << "Original list: " << endl;
    printList(head);

    head = removeDuplicates(head);
    cout << "After removing duplicates: " << endl;
    printList(head);

    head = insertNode(head, 20);
    cout << "After removing duplicates with no buffer: " << endl;
    head = removeDuplicatesNoBuffer(head);
    printList(head);

    deleteList(head);

    return 0;
}