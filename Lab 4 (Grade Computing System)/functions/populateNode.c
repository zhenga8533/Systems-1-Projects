#include <stdio.h>
#include <stdlib.h>
#include "../lab4.h"

Node* populateNode(struct Data StudentData) {
	// Create and allocate memory for new node
	Node *newNodePtr = malloc(sizeof(Node));
	if (newNodePtr == NULL) {
		printf("Failed to allocate storage to node...");
		exit(1);
	}
	
	newNodePtr->Student = StudentData;
	newNodePtr->next = NULL;
	
	return newNodePtr;
}

