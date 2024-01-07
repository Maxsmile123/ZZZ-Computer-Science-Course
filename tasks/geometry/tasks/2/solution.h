#pragma once

#include <stdio.h>

const int INITIAL_VALUE_I = 0;
const int INITIAL_VALUE_J = -3;
const int INITIAL_VALUE_L = -7;
const int MAX_ITERATIONS = 50;
const int FOURTY = 40;
const int ZERO = 0;
const int THREE = 3;
const int ONE = 1;

int Abs(int a) {
    return (a >= 0) ? a : -a;
}

int Max(int a, int b) {
    return (a >= b) ? a : b;
}

int Sign(int n) {
    if (n) {
        return (n > 0) ? 1 : -1;
    }
    return 0;
}

int Mod(int a, int b) {
    if (b != 0) {
        return (Abs(a % b));
    } else {
        printf("Error: you can't divide by zero");
        return 0;
    }
}

int Pow(int number, unsigned int p) {
    int result = 1;
    while (p--) {
        result *= number;
    }
    return result;
}

typedef struct {
    int x;
    int y;
} Point;

int CheckZone(Point p) {
    return ((Pow((p.x - 10), 2) + Pow((p.y - 10), 2) <= 100) && (Pow((p.x - 10), 2) + Pow((p.y - 10), 2) >= 25));
}

int Task() {
    int i = INITIAL_VALUE_I;
    int j = INITIAL_VALUE_J;
    int l = INITIAL_VALUE_L;
    int point_inside = ZERO;
    Point p;
    p.x = i;
    p.y = j;
    for (int k = 1; k <= MAX_ITERATIONS; ++k) {
        p.x = ((Abs(p.x - p.y + l) / (THREE - Sign(p.x - p.y + k)))) + 10;
        p.y = ((Abs(p.x + p.y - l) / (THREE - Sign(p.y - p.x + k)))) + 10;
        l = Mod(Max(p.x * p.y, p.y * l) * (k + ONE), FOURTY);
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
