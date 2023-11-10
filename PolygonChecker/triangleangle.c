#include <stdio.h>
#include "triangleangle.h"
#include <stdlib.h>
#include <math.h>
#define PI 3.1415592654
void FindAnglesOfTriangle(float a, float b, float c) {
	//check if triangle
	if ((a + b) > c && (b + c) > a && (a + c) > b) {
		// acos() return in radian
		printf("This forms triangle.\n");
		float AngleC = acos((a * a + b * b - c * c) / (2 * a * b)) * 180 / PI;
		printf("Angle C:%.2f\n", AngleC);
		float AngleB = acos((a * a + c * c - b * b) / (2 * a * c)) * 180 / PI;
		printf("Angle B:%.2f\n", AngleB);
		printf("Angle A:%.2f\n", 180 - AngleB - AngleC);
	}
	//exit if not triangle
	else {
		fprintf(stderr, "This does form a triangle.");
		exit(0);
	}
}