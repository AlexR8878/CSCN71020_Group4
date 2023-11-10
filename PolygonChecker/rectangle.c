#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "rectangle.h"
#define _CRT_SECURE_NO_WARNINGS

//A function which gets the area, perimeter, and checks if the points are a rectangle.
int fourPoints(double* area, double* perimeter, bool* isRectangle) {
	//variables
	int length, width;
	int topRight;
	int bottomRight;
	int topLeft;
	int bottomLeft;
	int points[4][2]; //An array that holds 4 points and each point holds 2 values (x,y).

	//Prompt the user to enter the 4 points
	printf("You will be entering 4 points a toal of 4 times.");
	for (int i = 0; i < 4; i++) {
		printf("\nPlease enter a point in x y format, for example; 3 4. ");
		int scanResult = scanf_s("%d %d", &points[i][0], &points[i][1]);

		//if the user enters anything other than a digit the program exits
		if (scanResult == 0) {
			printf("Not a valid number");
			exit(1);
		}
	}

	//Set each point to corner that may be changed in the loop below
	bottomLeft = 0;
	bottomRight = 1;
	topLeft = 2;
	topRight = 3;

	//loops through each point to place each point in the correct corner
	for (int i = 0; i < 4; i++) {
		if (points[i][0] <= points[bottomLeft][0] && points[i][1] <= points[bottomLeft][1]) {
			bottomLeft = i;
		}
		else if (points[i][0] <= points[topLeft][0] && points[i][1] >= points[topLeft][1]) {
			topLeft = i;
		}
		else if (points[i][0] >= points[topRight][0] && points[i][1] >= points[topRight][1]) {
			topRight = i;
		}
		else if (points[i][0] >= points[bottomRight][0] && points[i][1] <= points[bottomRight][1]) {
			bottomRight = i;
		}
	}

	//Checks to see if the points align to make a reactangle
	if (points[bottomLeft][0] != points[topLeft][0] && points[bottomLeft][1] != points[bottomRight][1]) {
		printf("Not a rectangle");
		isRectangle = false;
		exit(1);
	}
	else if (points[topRight][0] != points[bottomRight][0] && points[topRight][1] != points[topLeft][1]) {
		printf("Not a rectangle");
		isRectangle = false;
		exit(1);
	}

	//finds the width, length, area, and perimeter
	width = points[topRight][0] - points[topLeft][0];
	length = points[topRight][1] - points[bottomRight][1];
	*area = width * length;
	*perimeter = width * 2 + length * 2;
	printf("The area is %fcm squared and the perimeter is %fcm", *area, *perimeter);
}