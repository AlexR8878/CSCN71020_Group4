#include <stdio.h>
#include <math.h>
#include "RectangleCheck.h"


double DistanceBetweenPoints(POINT p1, POINT p2) {
    double distance = sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
    return distance;
}

void RectangleCheck(POINT p1, POINT p2, POINT p3, POINT p4) {
    double dist1 = DistanceBetweenPoints(p1, p2);
    double dist2 = DistanceBetweenPoints(p2, p1);
    double dist3 = DistanceBetweenPoints(p3, p4);
    double dist4 = DistanceBetweenPoints(p4, p3);

    if (dist1 == dist2 && dist2 == dist3 && dist3 == dist4) {
        printf("The four points form a rectangle.\n");
        double FindPerimeter;
        FindPerimeter = dist1 + dist2 + dist3 + dist4;
        double Findarea;
        Findarea = dist1 * dist2;
        printf("The perimter is: %lf\nThe area is: %lf\n", FindPerimeter, Findarea);
    }
    else {
        printf("The four points do not form a rectangle.\n");
    }
}
int main(void) {
    POINT p1 = { -3.0, 5.0 };       //All hardcode
    POINT p2 = { 4.0, 5.0 };
    POINT p3 = { -3.0, 2.0 };
    POINT p4 = { 4.0, 2.0 };
    RectangleCheck(p1, p2, p3, p4);
    return 0;
}
