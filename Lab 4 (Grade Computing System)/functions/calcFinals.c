#include <stdio.h>
#include "../lab4.h"

void calcFinals(char *categories[4], Node *head) {
	Node *body = head;
	struct Data Student;
	float cum1;
	float cum2;
	float cum3;
	float cum4;
	
	// Loop through linked list and set final grades
	while (body != NULL) {
		Student = body->Student;
		
		// Get all grades as final (-1 scores are automatic 0s)
		cum1 = calcCumulative(Student.Cat1.score1, Student.Cat1.score2, Student.Cat1.score3, 1);
		cum2 = calcCumulative(Student.Cat2.score1, Student.Cat2.score2, Student.Cat2.score3, 1);
		cum3 = calcCumulative(Student.Cat3.score1, Student.Cat3.score2, Student.Cat3.score3, 1);
		cum4 = calcCumulative(Student.Cat4.score1, Student.Cat4.score2, Student.Cat4.score3, 1);
		body->Student.finalGrade = calcFinal(cum1, cum2, cum3, cum4, 1);
		
		// Go to next node
		body = body->next;
	}
	
	// Call function to print scores with final
	printScores(categories, head);
}

