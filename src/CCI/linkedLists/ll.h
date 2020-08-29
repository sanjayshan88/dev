#pragma once

class Node
{
public:
    int info;
    Node* next;
    Node(int val)
        : info(val),
          next(nullptr)
    {
    }
};

Node* insertNode(Node* head, int val);
void printList(Node* head);
void deleteList(Node* head);