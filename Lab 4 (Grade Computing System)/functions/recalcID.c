#include <stdio.h>
#include "../lab4.h"

void recalcID(char *categories[4], Node *head) {
	Node *body;
	int studentID;

	// Get wanted student ID
	printf("Please enter the Student ID number to recalculate (1- 20000): ");
	scanf("%d", &studentID);
	body = findID(head, studentID);
	if (body == NULL) {
		printf("ERROR: could not locate Student ID# \"%d\".\n", studentID);
		return;
	}
	
	// Recalculate cumulative scores
	recalcScore(body);
	
	// Print scores after recalculation
	printHeader(categories);
	printLine(body->Student);
}

