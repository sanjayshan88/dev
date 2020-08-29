
#include <iostream>
#include "ll.h"

using namespace std;

/* trivial solution */
Node* kthToLast(Node* head, int k)
{
    if (head == nullptr) {
        return head;
    }
    int count = 0;
    Node* curr = head;
    while (curr != NULL) {
        count++;
        curr = curr->next;
    }

    curr = head;
    int i = 0;
    while (curr != NULL) {
        if (i == count - k) {
            return curr;
        }
        i++;
        curr = curr->next;
    }
    return NULL;
}

/* Iterative:
 * Use two pointers
 * Move first pointer k places.
 * Now move second pointer(from start) and first pointer (from k+1) simultanously.
 * When second pointer would have reached end, first pointer would be at kth node.
 */
Node* kthToLastIterative(Node* head, int k)
{
    if (head == nullptr) {
        return head;
    }
    Node* ptr1 = head;
    Node* ptr2 = head;
    int count = 0;
    while (ptr1 != NULL) {
        count++;
        if (count > k) {
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    return ptr2;
}

Node* kthToLastRecursiveHelper(Node* head, int k, int& count)
{
    if (head == nullptr) {
        return nullptr;
    }
    
    Node* result = kthToLastRecursiveHelper(head->next, k, count);
    count++;
    return count == k ? head : result;
}

Node* kthToLastRecursive(Node* head, int k)
{
    int count = 0;
    return kthToLastRecursiveHelper(head, k, count);   
}

int main()
{
    Node* head = new Node(10);
    head = insertNode(head, 20);
    head = insertNode(head, 30);
    head = insertNode(head, 40);

    // 40->30->20->10
    Node* kth = kthToLast(head, 2);
    cout << "kth to last: " << kth->info << endl;

    kth = kthToLastIterative(head, 4);
    cout << "kth to last iterative: " << kth->info << endl;

    kth = kthToLastRecursive(head, 3);
    cout << "kth to last recursive: " << kth->info << endl;

    head = nullptr;
    for ( int i = 7; i > 0; i-- ) {
        head = insertNode(head, i);
    }
    cout << "List: ";
    printList(head);

    cout << "4th node from last (Recursive) : ";
    Node *node4 = kthToLastRecursive(head, 4);
    if ( node4 != nullptr ) {
        cout << node4->info << endl;
    } else {
        cout << "NULL NODE\n";
    }

    cout << "4th node from last (Iterative) : ";
    node4 = kthToLastIterative(head, 4);
    if ( node4 != nullptr ) {
        cout << node4->info << endl;
    } else {
        cout << "NULL NODE\n";
    }

    deleteList(head);

    return 0;
}