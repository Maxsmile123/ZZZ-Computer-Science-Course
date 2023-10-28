#pragma once

#include <stdio.h>

int Mod(int x, int y) {
    if (y != 0) {
        return x % y;
    } else {
        return 0;
    }
}

int Max(int x, int y) {
    if (x > y) {
        return x;
    } else {
        return y;
    }
}

int Min(int x, int y) {
    if (x < y) {
        return x;
    } else {
        return y;
    }
}

const int X_1 = -10;
const int Y_1 = -10;
const int X_2 = -20;
const int Y_2 = -20;
const int R = 10;
const int I_0 = 7;
const int J_0 = -4;
const int L_0 = -10;
const int MAX_ITERATIONS = 50;
const int FORTY_SEVEN = 47;
const int TWENTYFIVE = 25;
const int THIRTY = 30;
const int FIVE = 5;
const int FIFTEEN = 15;
const int ONE = 1;

typedef struct {
    int x;
    int y;
} Point;

int CheckZone(Point p) {
    // Write a code here that checks whether a point belongs to a given area
    int cord_x = p.x;
    int cord_y = p.y;
    return (((cord_x - X_1) * (cord_x - X_1) + (cord_y - Y_1) * (cord_y - Y_1) <= R * R) &&
            ((cord_x - X_2) * (cord_x - X_2) + (cord_y - Y_2) * (cord_y - Y_2) <= R * R));
}

int Task() {
    // write main code here
    int i = I_0;
    int j = J_0;
    int l = L_0;
    Point p;
    p.x = i;
    p.y = j;

    int count_points_in_zone = 0;  // Счетчик точек, принадлежащих зоне

    for (int k = ONE; k <= MAX_ITERATIONS; k++) {
        i = Max(Mod((FORTY_SEVEN * p.x), TWENTYFIVE),
                Min(Mod((FORTY_SEVEN * p.y), THIRTY), Mod((FORTY_SEVEN * l), THIRTY))) -
            Mod(k, FIFTEEN);
        j = Min(Max(Mod((FORTY_SEVEN * p.x), TWENTYFIVE), Mod((FORTY_SEVEN * p.y), TWENTYFIVE)),
                Mod((FORTY_SEVEN * l), THIRTY)) +
            Mod(k, FIVE);
        l = Mod((FORTY_SEVEN * p.x * p.y * l), TWENTYFIVE) + Mod(k, FIVE);
        p.x = i;
        p.y = j;
        printf("k = %d, x = %d, y = %d, l = %d belong = %d \n", k, p.x, p.y, l, CheckZone(p));

        if (CheckZone(p)) {
            count_points_in_zone++;
        }
    }
    if (count_points_in_zone == 0) {
        printf("The point did not fall into the area beyond 50 iterations\n");
    } else {
        printf("Number of points belonging to the zone: %d\n", count_points_in_zone);
    }
    return 0;
}