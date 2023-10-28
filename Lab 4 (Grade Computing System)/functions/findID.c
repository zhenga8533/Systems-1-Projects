#include <stdio.h>
#include <stdlib.h>
#include "../lab4.h"

Node *findID(Node *head, int studentID) {
	Node *body = head;
	
	// Loop through node to find student with matching ID
	while (body != NULL && body->Student.studentID != studentID) {
		body = body->next;
	}
	
	// Check if node was found
	if (body != NULL) printf("Student ID# %d, Name: \"%s\" located!\n", studentID, body->Student.studentName);
	
	// Return body
	return body;
}

