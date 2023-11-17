#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "main.h"
#include "triangleangle.h"
#include "triangleSolver.h"

int side = 0;

int main() {
	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

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
	int numberScaned;
	printf_s("Enter number: ");

	numberScaned = scanf_s("%d", &shapeChoice);
	/*if (numberScaned != 1 || 0 < shapeChoice < 3) {

		fprintf(stderr, "Invalid try agai.\n");
		fflush(stdin);
		return 6;
	}*/
	return shapeChoice;
}

int* getTriangleSides(int* triangleSides) {
	printf_s("Enter the three sides of the triangle: ");
	for (int i = 0; i < 3; i++)
	{
		scanf_s("%d", &triangleSides[i]);
	}
	return triangleSides;
}