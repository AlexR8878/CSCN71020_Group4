#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "rectangle.h"
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS



//A function which gets the area, perimeter, and checks if the points are a rectangle.
void fourPoints(int points[4][2], double* area, double* perimeter, bool* isRectangle) {
	//variables
	int length, width;
	int topRight;
	int bottomRight;
	int topLeft;
	int bottomLeft;

	
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
		if (points[i][0] <= points[topLeft][0] && points[i][1] >= points[topLeft][1]) {
			topLeft = i;
		}
		if (points[i][0] >= points[topRight][0] && points[i][1] >= points[topRight][1]) {
			topRight = i;
		}
		if (points[i][0] >= points[bottomRight][0] && points[i][1] <= points[bottomRight][1]) {
			bottomRight = i;
		}
	}

	//Checks to see if the points align to make a reactangle
	//When the rectangle is just a singular horizontal line
	if (points[topRight][0] == points[bottomRight][0] && points[topRight][1] == points[bottomRight][1] && points[topLeft][1] == points[bottomLeft][1] && points[topLeft][1] == points[bottomLeft][1]) {
		printf("This does not a rectangle");
		*isRectangle = false;
		return;
	}
	//When the rectangle is just a singular horizontal line
	else if (points[bottomLeft][0] == points[bottomRight][0] && points[bottomLeft][1] == points[bottomRight][1] && points[topLeft][1] == points[topRight][1] && points[topLeft][1] == points[topRight][1]) {
		printf("This does not a rectangle");
		*isRectangle = false;
		return;
	}
	//When bottom left and top left points don't align
	else if (points[bottomLeft][0] != points[topLeft][0] || points[bottomLeft][1] != points[bottomRight][1]) {
		printf("This does not a rectangle");
		*isRectangle = false;
		return;
	}
	//When bottom right and top right points don't align
	else if (points[topRight][0] != points[bottomRight][0] || points[topRight][1] != points[topLeft][1]) {
		printf("This does not a rectangle");
		*isRectangle = false;
		return;
	}

	else {
		//finds the width, length, area, and perimeter
		width = points[topRight][0] - points[topLeft][0];
		length = points[topRight][1] - points[bottomRight][1];
		*area = width * length;
		*perimeter = width * 2 + length * 2;
		printf("This does form a rectangle\n");
		printf("The area is %fcm squared and the perimeter is %fcm", *area, *perimeter);
		*isRectangle = true;
		return;
	}
}