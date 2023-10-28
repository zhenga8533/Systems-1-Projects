/**
 * BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF THE
 * WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN THIS
 * FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE INSTRUCTOR
 * OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE TENURES OF THE
 * OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.
 *
 * Author: Allen Zheng
 */
#include <stdio.h>
#include <stdlib.h>
#include "lab4.h"
 
int main(int argc, char *args[]) {
	// Check for and get i/o file names
	if (argc != 3) {
		printf("Usage: ./lab4 <inputFile> <outputFile>\n");
		return 1;
	}
	char *inputFile = args[1];
	char *outputFile = args[2];
	
	// Open input file
	FILE *input = fopen(inputFile, "r");
	if (input == NULL) {
		printf("Could not open file \"%s\"\n", inputFile);
		return 1;
	}
	
	// Populate linked list with student information (start by initializing needed variables)
	Node *head = NULL;
	char title[100];
	char *categories[4] = {"Quizzes", "Midterms", "Homework", "Final"};
	struct Data StudentData;
	struct CatGrade *CatGrades[4] = {&StudentData.Cat1, &StudentData.Cat2, &StudentData.Cat3, &StudentData.Cat4};
	int numStudents = 0;
	printf("Reading student information from file \"%s\"\n", inputFile);
	
	// Save title of input file (first line of file), return if not found
	if (fgets(title, sizeof(title), input) == NULL) {
		printf("Could not read title.\n");
		fclose(input);
		return 1;
	}
	
	// Loop through each line of file to populate linked list
	StudentData.finalGrade = -1;
	while (fscanf(input, "%40[^\n]\n", StudentData.studentName) != EOF) {
		// Get student ID
		fscanf(input, "%d", &StudentData.studentID);
		
		// Loop through each score category to get current grades
		for (int i = 0; i < 4; i++) {
			// Set each categories scores
			fscanf(input, "%f %f %f\n", &CatGrades[i]->score1, &CatGrades[i]->score2, &CatGrades[i]->score3);
			
			// Set cumulative score for category
			CatGrades[i]->cumulative = calcCumulative(CatGrades[i]->score1, CatGrades[i]->score2, CatGrades[i]->score3, 0);
		}
		
		// Calculate student current grade using weights
		StudentData.currentGrade = calcFinal(CatGrades[0]->cumulative, CatGrades[1]->cumulative, CatGrades[2]->cumulative, CatGrades[3]->cumulative, 0);
		
		// Insert node into linked list with current student data
		insertNode(&head, StudentData);
		numStudents++;
	}
	printf("A total of %d student records were read from the file %s\n", numStudents, inputFile);
	
	// Variables to use for user option choices
	void (*options[8]) (char *categories[4], Node *head) = {
		requestID,
		requestName,
		printScores,
		recalcID,
		recalcScores,
		scoreID,
		calcFinals,
		addStudent
	};
	int choice = 0;
	
	// Infinite loop to allow user to edit/view data until selecting "10) Exit Program"
	while (choice != 10) {
		// Print options
		printf("\nThe Ten Commandments:\n");
		printf("1) Print Student Scores by Student ID\n");
		printf("2) Print Student Scores by Last Name\n");
		printf("3) Print Student Scores for All Students\n");
		printf("4) Recalculate Student Scores for a Single Student ID\n");
		printf("5) Recalculate All Student Scores\n");
		printf("6) Insert a Score for a Specific Student ID\n");
		printf("7) Calculate Final Grades\n");
		printf("8) Add a New Student\n");
		printf("9) Delete a Student\n");
		printf("10) Exit Program\n");
		printf("\nPlease enter an option between 1 and 10: ");
		
		// Indexing and switching, batchesting
		scanf("%d", &choice);
		
		// Consume line in case user griefs input ;)
		int c;
		while ((c = getchar()) != '\n');
		
		// Switch case for the function pointer array (1-7) and options 8, 9, and 10
		switch (choice) {
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
				options[choice - 1](categories, head);
				break;
			case 9:
				deleteNode(&head);
				break;
			case 10:
				// Special case for exiting program => close input, open output, and save to output
				fclose(input);
				writeData(head, outputFile, title);
				break;
			default:
				printf("\"%d\" is not a valid option!\n", choice);
				break;
		}
	}
	
	// Free memory and end program
	freeMemory(head);
	printf("Thank you for using my program, goodbye!\n");
	return 0;
}
