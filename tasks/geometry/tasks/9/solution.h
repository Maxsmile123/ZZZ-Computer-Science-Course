#pragma once

#include <stdio.h>

const int ITERATIONS = 50;
const int ZERO_ITERATION_I = 10;
const int ZERO_ITERATION_J = 20;
const int ZERO_ITERATION_L = -1;
const int LEFT_AND_BOTTOM_FACES = 5;
const int RIGHT_AND_HIGH_FACES = 15;
const int THREE = 3;
const int FOUR = 4;
const int FIVE = 5;
const int SIX = 6;
const int SEVEN = 7;
const int TEN = 10;
const int TWENTY = 20;
const int TWENTY_FIVE = 25;

typedef struct {
    int x;
    int y;
} Point;

int Abs(int x) {
    return (x >= 0) ? x : -x;
}

int CheckZone(Point p) {
    return (LEFT_AND_BOTTOM_FACES <= p.x && p.x <= RIGHT_AND_HIGH_FACES && LEFT_AND_BOTTOM_FACES <= p.y &&
            p.y <= RIGHT_AND_HIGH_FACES);
}

int Max(int x, int y) {
    return (x > y) ? x : y;
}

int Min(int x, int y) {
    return (x < y) ? x : y;
}

int Sign(int n) {
    if (n >= 0) {
        return (n == 0) ? 0 : 1;
    }
    return -1;
}

int Task() {
    int i = ZERO_ITERATION_I;
    int j = ZERO_ITERATION_J;
    int l = ZERO_ITERATION_L;
    Point p;
    p.x = i;
    p.y = j;
    for (int k = 1; k <= ITERATIONS; ++k) {
        i = (Abs(Max(p.x * (k + FOUR), p.y * (k + FIVE))) - Abs(Min(p.y * (k + SIX), l * (k + SEVEN)))) % TWENTY;
        j = ((THREE - Sign(p.x - p.y)) * Abs(Min(p.x * l + FIVE, Min(p.y * l - THREE, p.x * p.y + SIX)))) %
                TWENTY_FIVE -
            SEVEN;
        l = p.x % TEN + p.y % TEN + l % TEN;
        p.x = i;
        p.y = j;
        int is_inside = CheckZone(p);
        if (is_inside) {
            printf("x = %d, y = %d, l = %d, result = %d\n", p.x, p.y, l, is_inside);
        } else {
            printf("x = %d, y = %d, l = %d, result = %d, iteration = %d\n", p.x, p.y, l, is_inside, k);
        }
    }
    return 0;
}