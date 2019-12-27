#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct myStack {
	struct myStack *next;
	void *data;	
} node;

node *newNode()
{
	node *temp = (node *)malloc(sizeof(node));
	if (temp == NULL) {
		return NULL;
	}
	temp->next = NULL;
	return temp;
}

bool push(node **head, void* value)
{
	// insert front, since stack is
	// LIFO - Last In First Out
	node *temp = newNode();
	if (temp == NULL) {
		return false;
	}
	temp->data = value;
	temp->next = *head;
	*head = temp;
	cout << "pushed: " << *(int *)((*head)->data) << endl;
	
	return true;
}

bool pop(node **head, void** data)
{
	if (*head == NULL) {
		cout << "Stack is empty!" << endl;
		return false;
	}

	node *temp = *head;
	*head = temp->next;

	*data = temp->data;
	free(temp);
	
	return true;
}

int main()
{

	node *head = NULL;
	bool ret = false;
	
	// push 3 elements
	int a = 10;
	int b = 20;
	int c = 30;
	
	ret = push(&head, &a);
	if (ret != true) {
		cout << "ERR: Failed to push to the stack" << endl;
		return 1;
	}
	
	ret = push(&head, &b);
	if (ret != true) {
		cout << "ERR: Failed to push to the stack" << endl;
		return 1;
	}
	
	ret = push(&head, &c);
	if (ret != true) {
		cout << "ERR: Failed to push to the stack" << endl;
		return 1;
	}
	
	int d = 0;
	void *p = &d;
	
	// pop 3 elements
	ret = pop(&head, &p);
	if (ret != true) {
		cout << "ERR: Failed to pop from the stack" << endl;
		return 1;
	}
	cout << "popped: " << *((int *)p) << endl;
	
	ret = pop(&head, &p);
	if (ret != true) {
		cout << "ERR: Failed to pop from the stack" << endl;
		return 1;
	}
	cout << "popped: " << *((int *)p) << endl;
	
	ret = pop(&head, &p);
	if (ret != true) {
		cout << "ERR: Failed to pop from the stack" << endl;
		return 1;
	}
	cout << "popped: " << *((int *)p) << endl;
	
	// stack empty
	ret = pop(&head, &p);
	if (ret != true) {
		cout << "ERR: Failed to pop from the stack" << endl;
	}
	
	return 0;
}
