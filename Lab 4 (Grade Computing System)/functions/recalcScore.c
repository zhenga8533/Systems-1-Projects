#include <stdio.h>
#include "../lab4.h"

void recalcScore(Node *body) {
	struct Data Student = body->Student;

	// Recalculate all cumulative grades
	body->Student.Cat1.cumulative = calcCumulative(Student.Cat1.score1, Student.Cat1.score2, Student.Cat1.score3, 0);
	body->Student.Cat2.cumulative = calcCumulative(Student.Cat2.score1, Student.Cat2.score2, Student.Cat2.score3, 0);
	body->Student.Cat3.cumulative = calcCumulative(Student.Cat3.score1, Student.Cat3.score2, Student.Cat3.score3, 0);
	body->Student.Cat4.cumulative = calcCumulative(Student.Cat4.score1, Student.Cat4.score2, Student.Cat4.score3, 0);
	body->Student.currentGrade = calcFinal(body->Student.Cat1.cumulative, body->Student.Cat2.cumulative, body->Student.Cat3.cumulative, body->Student.Cat4.cumulative, 0);
}

