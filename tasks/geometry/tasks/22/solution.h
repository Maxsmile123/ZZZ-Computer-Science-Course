#pragma once

#include <stdio.h>

const int MINUS_TEN = -10;
const int TEN = 10;
const int TWENTY = 20;
const int INITIAL_I = 8;
const int INITIAL_J = 15;
const int INITIAL_L = 10;
const int Y_0 = 10;
const int X_0 = -10;
const int MAX_ITERATIONS = 50;
const int ONE = 1;
const int MINUS_ONE = -1;
const int THITRY = 30;
const int TWO = 2;

// Function return mod of numbers
int Mod(int num1, int num2) {
    if (num2 != 0) {
        if (num1 * num2 > 0) {
            return num1 % num2;
        } else {
            return num2 + (num1 % num2);
        }
    } else {
        return 0;
    }
}

// Function of return sign of numbers
int Sign(int num) {
    if (num > 0) {
        return 1;
    } else if (num < 0) {
        return -1;
    } else {
        return 0;
    }
}

int Max(int num1, int num2) {
    return (num1 >= num2) ? num1 : num2;
}

int Min(int num1, int num2) {
    return (num1 >= num2) ? num2 : num1;
}

int Module(int num) {
    return (num >= 0) ? num : num * MINUS_ONE;
}

typedef struct {
    int x;
    int y;
} Point;

int CheckZone(Point p) {
    return ((p.x + Y_0 <= p.y) && ((MINUS_ONE * p.x) + Y_0 >= p.y) && (p.x >= X_0));
}

int Task() {
    int i = INITIAL_I;
    int j = INITIAL_J;
    int l = INITIAL_L;
    Point p;
    p.x = i;
    p.y = j;
    int in_zone_counter = 0;
    for (int k = ONE; k <= MAX_ITERATIONS; ++k) {
        i = Mod(Mod((p.x + p.y), ((Module(Min(p.y - l, l - k)) + ONE) - k)), TWENTY) + TEN;
        j = Max((p.x + p.y) / (TWO + Sign((p.y * l) - (p.x * k))), (p.y + l) / (TWO + Sign((p.x * p.y) - (l * k)))) -
            TEN;
        l = Mod(Max(p.x, p.y) * Min(p.x, l), THITRY);
        p.x = i;
        p.y = j;
        if (CheckZone(p)) {
            ++in_zone_counter;
        }
        printf("k = %d, x = %d, y = %d, l = %d passed = %d \n", k, p.x, p.y, l, CheckZone(p));
    }
    if (in_zone_counter == 0) {
        printf("The point did not fall into the area beyond 50 iterations\n");
    } else {
        printf("Number of points belonging to the zone: %d\n", in_zone_counter);
    }
    return 0;
}
