#pragma once
#include <stdint.h>
#include <stdio.h>

int64_t Sign(int64_t x) {
    if (x > 0) {
        return 1;
    } else if (x < 0) {
        return -1;
    } else {
        return 0;
    }
}

int64_t Mod(int64_t x, int64_t y) {
    if (y != 0) {
        return x % y;
    } else {
        return 0;
    }
}

int64_t Max(int64_t x, int64_t y) {
    if (x > y) {
        return x;
    } else {
        return y;
    }
}

int64_t Min(int64_t x, int64_t y) {
    if (x < y) {
        return x;
    } else {
        return y;
    }
}

int64_t Abs(int64_t x) {
    if (x < 0) {
        return (-1) * x;
    } else {
        return x;
    }
}

int64_t SquareDegree(int64_t a) {
    return a * a;
}

const int X_0 = 20;
const int Y_0 = 0;
const int I_0 = -1;
const int J_0 = 2;
const int L_0 = -1;
const int ITERATION_COUNT = 50;
const int THIRTYFIVE = 35;
const int THIRTY = 30;
const int TWENTY = 20;
const int TWENTYFIVE = 25;
const int ONE = 1;
const int SEMI_MAJOR_AXIS = 10;
const int SEMI_MINOR_AXIS = 5;

typedef struct {
    int64_t x;
    int64_t y;
} Point;

int CheckZone(Point p) {
    return ((p.x - X_0) / SquareDegree(SEMI_MAJOR_AXIS)) + ((p.y - Y_0) / SquareDegree(SEMI_MINOR_AXIS)) == ONE;
}

int Task() {
    int64_t i = I_0;
    int64_t j = J_0;
    int64_t l = L_0;
    Point p;
    p.x = i;
    p.y = j;
    int owned_point_counter = 0;
    for (int k = ONE; k <= ITERATION_COUNT; ++k) {
        i = Mod((Sign(p.x - k) * l - Sign(p.y - l) * p.x + Sign(p.x - l) * p.y - k), THIRTYFIVE);
        j = Max((p.x * Max(p.y, l)), THIRTY) + Mod((p.y * Min(p.x, l)), TWENTY) - k;
        l = Mod(((p.x + k) * (p.y - k) * (l + k)), TWENTYFIVE);
        p.x = i;
        p.y = j;
        printf("k = %d, x = %lu, y = %lu, l = %lu belong %d \n", k, p.x, p.y, l, CheckZone(p));
        if (CheckZone(p)) {
            owned_point_counter++;
        }
    }
    printf("Number of points belonging to the area: %d\n", owned_point_counter);
    return 0;
}