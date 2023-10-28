#include <stdio.h>
#include <stdlib.h>
#include "../lab4.h"

void deleteNode(Node** head) {
	Node *body = *head;
	Node *previous = NULL;
	int studentID;
	
	// Ask user for student ID to delete
	printf("Please enter the Student ID number to delete (1- 20000): ");
	scanf("%d", &studentID);
	
	// Loop through linked list to find node with matching studentID
	while (body != NULL && body->Student.studentID != studentID) {
		previous = body;
		body = body->next;
	}
	
	// Return if no matching studentID was found
	if (body == NULL) {
		printf("ERROR: could not locate Student ID# \"%d\".\n", studentID);
		return;
	}
	
	// Remove node from linked list
	printf("Deleting Student ID# %d, Name: %s from linked list...\n", studentID, body->Student.studentName);
	if (previous == NULL) *head = body->next;
	else previous->next = body->next;
	
	// Free node o7
	free(body);
}

