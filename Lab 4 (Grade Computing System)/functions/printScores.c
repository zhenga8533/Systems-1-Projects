#include <stdio.h>
#include "../lab4.h"

void printScores(char *categories[4], Node *head) {
	Node *body = head;
	struct Data Average = {
		"Class Average:",
		0,
		{ 0, 0, 0, 0},
		{ 0, 0, 0, 0},
		{ 0, 0, 0, 0},
		{ 0, 0, 0, 0},
		0,
		0
	};
	struct Data Count = {
		"Count",
		0,
		{ 0, 0, 0, 0},
		{ 0, 0, 0, 0},
		{ 0, 0, 0, 0},
		{ 0, 0, 0, 0},
		0,
		0
	};
	struct CatGrade *AverageGrades[4] = {&Average.Cat1, &Average.Cat2, &Average.Cat3, &Average.Cat4};
	struct CatGrade *CountGrades[4] = {&Count.Cat1, &Count.Cat2, &Count.Cat3, &Count.Cat4};
	struct Data Student;
	
	// Loop through linked list and print
	printHeader(categories);
	
	while (body != NULL) {
		// Add scores to class average
		Student = body->Student;
		struct CatGrade *CatGrades[4] = {&Student.Cat1, &Student.Cat2, &Student.Cat3, &Student.Cat4};
	
		// Check if score is -1 and add if not
		for (int i = 0; i < 4; i++) {
			if (CatGrades[i]->score1 != -1) {
				AverageGrades[i]->score1 += CatGrades[i]->score1;
				CountGrades[i]->score1++;
			}
			if (CatGrades[i]->score2 != -1) {
				AverageGrades[i]->score2 += CatGrades[i]->score2;
				CountGrades[i]->score2++;
			}
			if (CatGrades[i]->score3 != -1) {
				AverageGrades[i]->score3 += CatGrades[i]->score3;
				CountGrades[i]->score3++;
			}
			if (CatGrades[i]->cumulative != -1) {
				AverageGrades[i]->cumulative += CatGrades[i]->cumulative;
				CountGrades[i]->cumulative++;
			}
		}
		
		// Check and add for current and final grades
		if (Student.currentGrade != -1) {
			Average.currentGrade += Student.currentGrade;
			Count.currentGrade++;
		}
		if (Student.finalGrade != -1) {
			Average.finalGrade += Student.finalGrade;
			Count.finalGrade++;
		}
	
		// Print student data
		printLine(Student);
		
		// Get next node in linked list
		body = body->next;
	}
	
	// Divide each score category by count to get average
	for (int i = 0; i < 4; i++) {
		// Average 3 scores for each category and cumulative
		if (CountGrades[i]->score1 == 0) AverageGrades[i]->score1 = -1;
		else AverageGrades[i]->score1 /= CountGrades[i]->score1;
		
		if (CountGrades[i]->score2 == 0) AverageGrades[i]->score2 = -1;
		else AverageGrades[i]->score2 /= CountGrades[i]->score2;
		
		if (CountGrades[i]->score3 == 0) AverageGrades[i]->score3 = -1;
		else AverageGrades[i]->score3 /= CountGrades[i]->score3;
		
		if (CountGrades[i]->cumulative == 0) AverageGrades[i]->cumulative = -1;
		else AverageGrades[i]->cumulative /= CountGrades[i]->cumulative;
	}
	
	// Average current and final grade
	if (Count.currentGrade == 0) Average.currentGrade = -1;
	else Average.currentGrade /= Count.currentGrade;
	
	if (Count.finalGrade == 0) Average.finalGrade = -1;
	else Average.finalGrade /= Count.finalGrade;
	
	// Print average
	Average.studentID = 0;
	printf("\n");
	printLine(Average);
}

