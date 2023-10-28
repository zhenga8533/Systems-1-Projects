#include <stdio.h>
#include <stdlib.h>
#include "../lab4.h"

void freeMemory(Node* head) {
	Node *body;
	
	// Loop through linked list and free each node
	while (head != NULL) {
		body = head;
		head = head->next;
		free(body);
	}
}

