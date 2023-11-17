#include <stdio.h>
#include "triangleangle.h"
#include <stdlib.h>
#include <math.h>
#define PI 3.1415592654
int CheckSidesFormTriangle(float a, float b, float c) {
	if ((a + b) > c && (b + c) > a && (a + c) > b)
		return 1;
	else
		return 0;
}
void FindAnglesOfTriangle(float a, float b, float c, float Angles[]) {
	//check if triangle
	if (CheckSidesFormTriangle(a, b, c)) {
		// acos() return in radian
		printf("This forms triangle.\n");
		Angles[0] = floor((acos((b * b + c * c - a * a) / (2 * b * c)) * 180 / PI)*100)/100;
		printf("Angle A:%.2f\n", Angles[0]);
		Angles[1] = floor((acos((a * a + c * c - b * b) / (2 * a * c)) * 180 / PI)*100)/100;
		printf("Angle B:%.2f\n", Angles[1]);
		Angles[2] = 180 - Angles[0] - Angles[1];
		printf("Angle C:%.2f\n", Angles[2]);
	}
	else {
		fprintf(stderr, "This does form a triangle.");
		Angles[0] = 0;
		Angles[1] = 0;
		Angles[2] = 0;
		return;
	}
}