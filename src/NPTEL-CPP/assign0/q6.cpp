#include <iostream>

using namespace std;

typedef struct node_s {
  char data;
  struct node_s* next;
} node;

void fun(node* start)
{
  if (start == NULL) {
    return;
  }
  cout << start->data << " ";

  if (start->next != NULL) {
    fun(start->next->next);
  }
  cout << start->data << " ";
}

node* insert(node* root, int val) {
  node* curr = (node*)malloc(sizeof(node));
  curr->data = val;

  if (root == NULL) {
    root = curr;
  } else {
    node* temp = root;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = curr;
  }
  return root;
}

int main() {
  node* root;
  root = insert(root, 'I');
  root = insert(root, 'I');
  root = insert(root, 'T');
  root = insert(root, 'K');
  root = insert(root, 'G');
  root = insert(root, 'P');
  
  fun(root);

  return 0;
}