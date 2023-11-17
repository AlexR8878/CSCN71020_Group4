#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>
#include "triangleSolver.h"


void analyzeTriangle(int side1, int side2, int side3, char result[]) {

    if (side1 + side2 > side3 && side1 < side2 + side3 && side1 + side3 > side2) {
        if (side1 == side2 && side1 == side3) {
            strcpy(result, "Equilateral triangle");
        }
        else if ((side1 == side2 && side1 != side3) ||
            (side1 == side3 && side1 != side2)) {
            strcpy(result, "Isosceles triangle");
        }
        else
            strcpy(result, "Scalene triangle");
    }
    else
    strcpy(result, "Not a triangle");
}
