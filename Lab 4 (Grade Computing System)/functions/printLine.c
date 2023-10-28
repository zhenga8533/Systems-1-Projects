#include <stdio.h>
#include "../lab4.h"

void printLine(struct Data StudentData) {
	struct CatGrade Cats[4] = {
		StudentData.Cat1,
		StudentData.Cat2,
		StudentData.Cat3,
		StudentData.Cat4
	};
	
	// Print student name and ID
	if (StudentData.studentID < 1 || StudentData.studentID > 20000) printf("%-20s\t     ", StudentData.studentName);
	else printf("%-20s\t%5d", StudentData.studentName, StudentData.studentID);
	
	// Print category 1 scores
	for (int i = 0; i < 4; i++) {
		// Check if each of the 4 scores equals -1 to print "n/a" otherwise print score to fixed 2 decimal places
		if (Cats[i].score1 == -1) printf("    n/a ");
		else printf("  %6.2f", Cats[i].score1);
		
		if (Cats[i].score2 == -1) printf("    n/a ");
		else printf("  %6.2f", Cats[i].score2);
		
		if (Cats[i].score3 == -1) printf("    n/a ");
		else printf("  %6.2f", Cats[i].score3);
		
		if (Cats[i].cumulative == -1) printf("    n/a  ");
		else printf("  %6.2f ", Cats[i].cumulative);
	}
	
	// Check current and final grade for -1 to print "n/a" otherwise print score to fixed 2 decimal places
	if (StudentData.currentGrade == -1) printf("        n/a ");
	else printf("      %6.2f", StudentData.currentGrade);
	
	if (StudentData.finalGrade == -1) printf("    n/a\n");
	else printf("  %6.2f\n", StudentData.finalGrade);
}

