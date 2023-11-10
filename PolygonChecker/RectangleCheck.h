#pragma once
typedef struct points {
    double x;
    double y;
} POINT;
void RectangleCheck(POINT p1, POINT p2, POINT p3, POINT p4);
double DistanceBetweenPoints(POINT p1, POINT p2);