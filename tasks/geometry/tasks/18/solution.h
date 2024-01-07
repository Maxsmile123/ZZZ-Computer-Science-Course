#pragma once

#include <stdio.h>
const int INITIAL_VALUE_I = 12;
const int INITIAL_VALUE_J = 4;
const int INITIAL_VALUE_L = 3;
const int MAX_ITERATIONS = 50;
const int THIRTY = 30;
const int TWENTY = 20;
const int ZERO = 0;
const int ONE = 1;

int Abs(int a) {
    return (a >= 0) ? a : -a;
}

int Max(int a, int b) {
    return (a >= b) ? a : b;
}

int Min(int a, int b) {
    return (a >= b) ? b : a;
}

int Mod(int a, int b) {
    if (b != 0) {
        return (Abs(a % b));
    } else {
        printf("Error: you can't divide by zero");
        return 0;
    }
}
typedef struct {
    int x;
    int y;
} Point;

int CheckZone(Point p) {
    // Write a code here that checks whether a point belongs to a given area
    return ((p.x + p.y + 10 < 0) && (p.x + p.y + 20 > 0));
}

int Task() {
    // write main code here
    int i = INITIAL_VALUE_I;
    int j = INITIAL_VALUE_J;
    int l = INITIAL_VALUE_L;
    int point_inside = ZERO;
    Point p;
    p.x = i;
    p.y = j;
    for (int k = 1; k <= MAX_ITERATIONS; ++k) {
        p.x = Mod((p.x * p.y) / (Abs(l) + 1) + (p.y * l) / (Abs(p.x) + 1) + (p.x * l) / (Abs(p.y)), THIRTY);
        p.y = Mod(p.x * Max(p.y, l), TWENTY) + Mod(p.y * Max(p.x, l), THIRTY) - k;
        l = Mod(Max(p.x * p.y, Max(p.x * l, p.y * l)), THIRTY) + 20;
        if (CheckZone(p)) {
            printf("x = %d, y = %d, l = %d, result = YES, number of iteration = %d\n", p.x, p.y, l, k);
            point_inside = ONE;
        } else {
            printf("x = %d, y = %d, l = %d, result = NO\n", p.x, p.y, l);
        }
    }
    if (point_inside == ZERO) {
        printf("50 iterations have elapsed and the point has not entered the zone");
    }
    return 0;
}
