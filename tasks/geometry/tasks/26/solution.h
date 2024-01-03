#pragma once

#include <stdio.h>

const int INITIAL_VALUE_I = -10;
const int INITIAL_VALUE_J = -10;
const int INITIAL_VALUE_L = 6;
const int CENTER_COORDINATES_Y = 0;
const int CENTER_COORDINATES_X = 20;
const int COORDINATES_A_X = 10;
const int COORDINATES_B_X = 30;
const int COORDINATES_C_Y = 5;
const int COORDINATES_D_Y = -5;
const int MAX_ITERATIONS = 50;
const int THIRTY = 30;
const int TWENTY_FIVE = 25;
const int TEN = 10;
const int THIRTY_FIVE = 35;

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
    return (((p.x - CENTER_COORDINATES_X) * (p.x - CENTER_COORDINATES_X)) /
                    ((CENTER_COORDINATES_X - COORDINATES_A_X) * (CENTER_COORDINATES_X - COORDINATES_A_X)) +
                ((p.y - CENTER_COORDINATES_Y) * (p.y - CENTER_COORDINATES_Y)) /
                    ((CENTER_COORDINATES_Y - COORDINATES_D_Y) * (CENTER_COORDINATES_Y - COORDINATES_D_Y)) <=
            1);
}

int Task() {
    int i = INITIAL_VALUE_I;
    int j = INITIAL_VALUE_J;
    int l = INITIAL_VALUE_L;
    int is_point_inside = 0;
    Point p;
    p.x = i;
    p.y = j;
    for (int k = 1; k <= MAX_ITERATIONS; ++k) {
        p.x = Abs(Max(Mod(Min(p.x + p.y, p.x + l), THIRTY), Mod(Max(p.x + l, p.y + k), TWENTY_FIVE)));
        p.y = Mod(Abs(p.x + k), TEN) + Mod(Abs(p.y + k), TEN) + Mod(Abs(l + k), TEN);
        l = Mod(p.x * p.x * p.x + p.y * p.y * p.y + l * l * l - k, THIRTY_FIVE);
        if (CheckZone(p)) {
            printf("x = %d, y = %d, l = %d, result = YES, number of iteration = %d\n", p.x, p.y, l, k);
            is_point_inside = 1;
        } else {
            printf("x = %d, y = %d, l = %d, result = NO\n", p.x, p.y, l);
        }
    }
    if (!is_point_inside) {
        printf("50 iterations have elapsed and the point has not entered the zone");
    }
    return 0;
}
