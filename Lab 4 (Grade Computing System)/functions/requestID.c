#include <stdio.h>
#include "../lab4.h"

void requestID(char *categories[4], Node *head) {
	Node *body;
	int studentID;
	
	// Get wanted student ID
	printf("Please enter the wanted Student ID number (1- 20000): ");
	scanf("%d", &studentID);
	
	// Check if valid number, return if not
	if (studentID < 1 || studentID > 20000) {
		printf("ERROR: \"%d\" is not a valid Student ID #.", studentID);
		return;
	}
	
	// Loop through linked list to find node with matching studentID
	body = findID(head, studentID);
	
	// Output error if no matching ID was found other output the formatted data
	if (body == NULL) printf("ERROR: could not locate Student ID# \"%d\".\n", studentID);
	else {
		printHeader(categories);
		printLine(body->Student);
	}
}

