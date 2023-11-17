#include <stdio.h>
#include <stdbool.h>
<<<<<<< HEAD
#include <stdlib.h>
=======
#include <stdbool.h>
>>>>>>> 2ce5c0e91dbecf2eba55cbed59a47a34a447a18f
#include "main.h"
#include "triangleangle.h"
#include "triangleSolver.h"

int side = 0;

int main (void) {
  
   bool continueProgram = true;
   while (continueProgram) {
   printWelcome();
   int shapeChoice = printShapeMenu();

        switch (shapeChoice) {
        case 1:
            printf("Triangle selected.\n");

<<<<<<< HEAD
		switch (shapeChoice)
		{
		case 1:
			printf_s("Triangle selected.\n");
			int triangleSides[3] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			//printf_s("! %d\n", triangleSidesPtr[0]);
			char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			printf_s("%s\n", result);
			break;
		case 2:
			printf("Triangle inside angles selected\n");
			getTriangleSides(triangleSides);
			float angle[3];
			FindAnglesOfTriangle(triangleSides[0], triangleSides[1], triangleSides[2], angle);
			break;
		case 3:
			printf("Rectangele selecte.\n");

		case 0:
			continueProgram = false;
			break;
		default:
			printf_s("Invalid value entered.\n");
			break;
		}
	}
	return 0;
=======
            int triangleSides[3] = { 0, 0, 0 };
            int* triangleSidesPtr = getTriangleSides(triangleSides);
            char result[40];
            analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2], result);
            printf("%s\n", result);
            break;
        case 2:
            printf("Triangle inside angles selected\n");
            getTriangleSides(triangleSides);
            FindAnglesOfTriangle(triangleSides[0], triangleSides[1], triangleSides[2]);
            break;
        case 0:
            continueProgram = false;
            break;
        default:
            printf("Invalid value entered.\n");
            break;
        }
    }

    return 0;
>>>>>>> 2ce5c0e91dbecf2eba55cbed59a47a34a447a18f
}

void printWelcome() {
	printf_s("\n");
	printf_s(" **********************\n");
	printf_s("**     Welcome to     **\n");
	printf_s("**   Polygon Checker  **\n");
	printf_s(" **********************\n");
}

int printShapeMenu() {
    printf_s("1. Triangle\n");
    printf_s("2. Triangle inside angle\n");
    printf_s("0. Exit\n");

<<<<<<< HEAD
	int shapeChoice;
	int numberScaned;
	printf_s("Enter number: ");

	numberScaned = scanf_s("%d", &shapeChoice);
	/*if (numberScaned != 1 || 0 < shapeChoice < 3) {

		fprintf(stderr, "Invalid try agai.\n");
		fflush(stdin);
		return 6;
	}*/
=======
    int shapeChoice;

    printf_s("Enter number: ");
    while (scanf_s("%d", &shapeChoice) != 1) {
        // Clear the input buffer in case of invalid input
        while (getchar() != '\n');

        printf("Invalid input, try again:\n\n");
        printf_s("1. Triangle\n");
        printf_s("2. Triangle inside angle\n");
        printf_s("0. Exit\n");
        printf_s("Enter number: ");
       
    }
>>>>>>> 2ce5c0e91dbecf2eba55cbed59a47a34a447a18f
	return shapeChoice;
}

int* getTriangleSides(int* triangleSides) {
	printf ("Enter the three sides of the triangle\n");
	for (int i = 0; i < 3; i++)
	{
        printf("Side %d: ", i+1);
        while (scanf_s("%d", &triangleSides[i]) != 1) {
            // Clear the input buffer in case of invalid input
            while (getchar() != '\n');

            printf("Invalid input, try again:\n");
            printf("Side %d: ", i + 1 && i < 3);
        }
    }
    return triangleSides;
}
	