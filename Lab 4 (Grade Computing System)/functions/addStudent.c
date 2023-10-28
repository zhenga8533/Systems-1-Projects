#include <stdio.h>
#include "../lab4.h"

void addStudent(char *categories[4], Node *head) {
	struct Data StudentData;
	StudentData.finalGrade = -1;
	struct CatGrade *CatGrades[4] = {&StudentData.Cat1, &StudentData.Cat2, &StudentData.Cat3, &StudentData.Cat4};
	
	// Get student name and id from user input
	printf("Enter the Student's Name (lastName, firstName): ");
	scanf("%40[^\n]", StudentData.studentName);
	printf("Enter the Student's ID Number: ");
	scanf("%d", &StudentData.studentID);
	
	// Check if ID is already in linked list
	if (findID(head, StudentData.studentID) != NULL) {
		printf("ERROR: Student ID# %d is already in use.\n", StudentData.studentID);
		return;
	}
	
	// Get the 3 scores for the 4 categories from user input
	for (int i = 0; i < 4; i++) {
		printf("Enter first %s score (use -1 if there is no score): ", categories[i]);
		scanf("%f", &CatGrades[i]->score1);
		printf("Enter second %s score (use -1 if there is no score): ", categories[i]);
		scanf("%f", &CatGrades[i]->score2);
		printf("Enter third %s score (use -1 if there is no score): ", categories[i]);
		scanf("%f", &CatGrades[i]->score3);
		
		// Set cumulative score for category
		CatGrades[i]->cumulative = calcCumulative(CatGrades[i]->score1, CatGrades[i]->score2, CatGrades[i]->score3, 0);
	}
	StudentData.currentGrade = calcFinal(CatGrades[0]->cumulative, CatGrades[1]->cumulative, CatGrades[2]->cumulative, CatGrades[3]->cumulative, 0);
	
	// Add new student to end of linked list
	insertNode(&head, StudentData);
	
	// Print confirmation and data to user
	printf("%s, Student ID# %d has been added with the following information:\n", StudentData.studentName, StudentData.studentID);
	printHeader(categories);
	printLine(StudentData);
}
