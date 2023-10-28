#include <stdio.h>
#include "../lab4.h"

void insertNode(Node **head, struct Data studentData) {
	// Create and allocate memory for new node
	Node *newNodePtr = populateNode(studentData);
	
	// Add node to end of linked list
	if (*head == NULL) *head = newNodePtr;
	else {
		Node* body = *head;
		while (body->next != NULL) body = body->next;
		body->next = newNodePtr;
	}
}

