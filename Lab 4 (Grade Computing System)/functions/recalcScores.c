#include <stdio.h>
#include "../lab4.h"

void recalcScores(char *categories[4], Node *head) {
	Node *body = head;
	
	// Loop through linked list and set final grades
	while (body != NULL) {
		// Recalculate all grades
		recalcScore(body);
		
		// Go to next node
		body = body->next;
	}
	
	// Call function to print scores with final
	printScores(categories, head);
}

