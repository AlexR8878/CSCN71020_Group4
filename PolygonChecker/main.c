#include <stdio.h>
#include <stdbool.h>
#include <stdbool.h>
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
	