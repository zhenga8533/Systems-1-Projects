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
#include "lab3.h"

void populateTitles(char ***titles, int *numTitles) {
	// Get user book amount and allocate memory
	printf("Input the amount of library book titles you plan to enter: ");
	scanf("%i", numTitles);
	getchar();
	*titles = (char **) malloc(*numTitles * sizeof(char *));

	// Get user book titles
	char **titlePtr = *titles;
	printf("\nInput the %i book titles:\n", *numTitles);
	for (int i = 0; i < *numTitles; i++) {
		(*titles)[i] = (char *) malloc(61 * sizeof(char));
		printf("%i. ", i + 1);
		scanf("%[^\n]", *(titlePtr++));
		getchar();
	}
}

void populateFavorites(char ***titles, int numTitles, char ***favorites, int *numFavorites) {
	// Get user favorite amount and allocate memory
	printf("\nOf those %i books, how many do you plan to put on your favorites list? ", numTitles);
	scanf("%i", numFavorites);
	*favorites = (char **) malloc(*numFavorites * sizeof(char *));

	// Get user's favorite titles
	char **favoritePtr = *favorites;
	if (*numFavorites > 0) {
		int index;
		printf("Enter the number of each book title you want on your favorites list (separated by spaces): ");
		for (int i = 0; i < *numFavorites; i++) {
			scanf("%i", &index);
			*(favoritePtr++) = *(*titles + index - 1);
		};
	}
}

void saveBooks(char ***titles, int numTitles, char ***favorites, int numFavorites) {
	// Check if the player wants to save book titles
	int save;
	printf("\nDo you want to save them (1=yes, 2=no): ");
	scanf("%i", &save);

	if (save == 1) {
		// Get file name
		char fileName[256];
		printf("What file name do you want to use? ");
		scanf("%s", fileName);

		// Open, write, and save to file
		FILE *out = fopen(fileName, "w");

		// Prints all books to file
		char **titlePtr = *titles;
		fputs("Books I've Read:\n", out);
		for (int i = 0; i < numTitles; i++) {
			fprintf(out, "%s\n", *(titlePtr++));
		}

		// Prints favorite books to file
		char **favoritePtr = *favorites;
		fputs("\nMy Favorites are:\n", out);
		for (int i = 0; i < numFavorites; i++) {
			fprintf(out, "%s\n", *(favoritePtr++));
		}

		// Close the file and confirm to the user
		fclose(out);
		printf("Your booklist and favorites have been saved to the file '%s'!\n", fileName);
	}
}

int main() {
	char **titles;
	int numTitles;
	char **favorites;
	int numFavorites;

	// Populate titles using user input and output titles
	populateTitles(&titles, &numTitles);

	if (numTitles > 0) {
		char **titlePtr = titles;
		printf("\nYou've entered:\n");
		for (int i = 0; i < numTitles; i++) {
			printf("%i. %s\n", i + 1, *(titlePtr++));
		}
	}

	// Populate favorites using user input and output titles
	populateFavorites(&titles, numTitles, &favorites, &numFavorites);

	if (numFavorites > 0) {
		char **favoritePtr = favorites;
		printf("\nThe books on your favorites list are:\n");
		for (int i = 0; i < numFavorites; i++) {
			printf("%i. %s\n", i + 1, *(favoritePtr++));
		}
	}

	// Prompt the user to save books to a file
	saveBooks(&titles, numTitles, &favorites, numFavorites);

	// Goodbye, World! (and free memory)
	char **titlePtr = titles;
	for (int i = 0; i < numTitles; i++) {
		free(*(titlePtr++));
	}
	free(titles);
	free(favorites);

	printf("\nThank you for using my program, goodbye!\n");
}

