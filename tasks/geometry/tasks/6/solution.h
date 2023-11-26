#pragma once

#include <stdio.h>

const int I = 22;
const int J = 10;
const int L = 10;
const int MAX_STEPS = 50;
const int X1 = 5;
const int X2 = 5;
const int X3 = 15;
const int X4 = 15;
const int Y1 = 5;
const int Y2 = 15;
const int Y3 = 15;
const int Y4 = 5;
const int ONE = 1;
const int FIVE = 5;
const int TWO = 2;
const int THREE = 3;
const int SEVEN = 7;
const int TEN = 10;
const int MINUS_THREE = -3;

int Abs(int num) {
    return (num >= 0) ? -num : num;
}

int Sign(int a) {
    if (a > 0) {
        return 1;
    }
    if (a < 0) {
        return -1;
    }
    return 0;
}

int Mod(int a, int b) {
    return (a % b + b) % b;
}

int Max(int num1, int num2) {
    return (num1 >= num2) ? num1 : num2;
}

int Min(int num1, int num2) {
    return (num1 >= num2) ? num2 : num1;
}

typedef struct {
    int x;
    int y;
} Point;

int CheckZone(Point p) {
    return ((p.x >= X1 && p.x <= X3) && (p.y >= Y1 && p.y <= Y2));
}

int Task() {
    int i = I;
    int j = J;
    int l = L;
    Point p;
    p.x = i;
    p.y = j;
    int in_zone = 0;
    for (int k = ONE; k <= MAX_STEPS; ++k) {
        i = Min(Mod(l, FIVE), Mod(p.x * k, FIVE)) + p.y + k / THREE;
        j = Max(MINUS_THREE * p.x, TWO * p.y) / FIVE - Abs(p.y - l);
        l = p.y + Mod(l, SEVEN) + k * Sign(Mod(p.x, TEN));

        if (CheckZone(p)) {
            in_zone += 1;
        }
    }
    if (in_zone == 0) {
        printf("The point didn't fall into the area beyond 50 iterations\n");
    } else {
        printf("Number of points belonging to the zone: %d\n", in_zone);
    }
    return 0;
}