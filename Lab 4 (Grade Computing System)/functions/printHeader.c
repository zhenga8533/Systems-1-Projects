#include <stdio.h>
#include "../lab4.h"

void printHeader(char *Category_Names[4]) {
	printf("\nStudent Name\t     Student ID#      \t%s\t\t\t\t%s\t\t\t%s\t\t\t%s\t\t\t\tCurrent\tFinal\n", Category_Names[0], Category_Names[1], Category_Names[2], Category_Names[3]);
	printf("\t\t\t\t  1       2       3      Cum\t   1       2       3      Cum\t    1       2       3      Cum\t     1       2       3      Cum\t\tGrade\tGrade\n");
}

