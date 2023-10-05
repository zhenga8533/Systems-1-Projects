/**
 * BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF THE
 * WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN THIS
 * FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE INSTRUCTOR
 * OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE TENURES OF THE
 * OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include "lab3.h"

void populateTitles(char **titles[], int *numTitles) {
	// Get user book amount and allocate memory
	printf("Input the amount of library book titles you plan to enter: ");
	scanf("%i", numTitles);
	*titles = (char **) malloc(*numTitles * sizeof(char *));
	
	// Get user book titles
	printf("\nInput the %i book titles:\n", *numTitles);
	for (int i = 0; i < *numTitles; i++) {
		(*titles)[i] = (char *) malloc(61 * sizeof(char));
		printf("%i. ", i + 1);
		scanf("%s", (*titles)[i]);
	}
}

void populateFavorites(int *favorites[], int *numFavorites, int numTitles) {
	// Get user favorite amount and allocate memory
	printf("\nOf those %i books, how many do you plan to put on your favorites list? ", numTitles);
	scanf("%i", numFavorites);
	*favorites = (int *) malloc(*numFavorites * sizeof(int));
	
	// Get user's favorite titles
	if (*numFavorites > 0) {
		printf("Enter the number of each book title you want on your favorites list (seperated by spaces): ");
		for (int i = 0; i < *numFavorites; i++) {
			scanf("%i", &((*favorites)[i]));
		};
	}
}

void saveBooks(char **titles[], int numTitles, int *favorites[], int numFavorites) {
	int save;

	printf("Do you want to save them (1=yes, 2=no): ");
	scanf("%i", &save);
	
	if (save) {
		// Get file name
		char fileName[256];
		printf("What file name do you want to use? ");
		scanf("%s", fileName);
		
		// Open, write, and save to file
		FILE *out = fopen(fileName, "w");
		
		fputs("Books I've Read:\n", out);
		for (int i = 0; i < numTitles; i++) {
			fprintf(out, "%s\n", (*titles)[i]);
		}
		
		fputs("\nMy Favorites are:\n", out);
		for (int i = 0; i < numFavorites; i++) {
			fprintf(out, "%s\n", (*titles)[(*favorites)[i] - 1]);
		}
		
		fclose(out);
		
		// Confirmation message
		printf("Your booklist and favorites have been saved to the file %s", fileName);
	}
}

int main() {
	char **titles[1];
	int numTitles;
	int *favorites[1];
	int numFavorites;
	
	// Populate titles using user input and output titles
	populateTitles(titles, &numTitles);
	
	printf("\nYou've entered:\n");
	for (int i = 0; i < numTitles; i++) {
		printf("%i. %s\n", i + 1, (*titles)[i]);
	}
	
	// Populate favorites using user input and output titles
	populateFavorites(favorites, &numFavorites, numTitles);
	
	if (numFavorites > 0) {
		printf("\nThe books on your favorites list are:\n");
		for (int i = 0; i < numFavorites; i++) {
			printf("%i. %s\n", i + 1, (*titles)[(*favorites)[i] - 1]);
		}
	}
	
	// Prompt user for save books to file
	saveBooks(titles, numTitles, favorites, numFavorites);
	
	// Goodbye, World! (and free memory)
	printf("\nThank you for using my program, goodbye!\n");
	for (int i = 0; i < numTitles; i++) {
		free((*titles)[i]);
	}
	free(*titles);
	free(*favorites);
}

