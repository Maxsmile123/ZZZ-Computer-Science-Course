#pragma once

#include <stdio.h>

const int ITERATIONS = 50;
const int START_I = 10;
const int START_J = 20;
const int START_L = -1;
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
    if (n) {
        return (n > 0) ? 1 : -1;
    }
    return 0;
}

int Mod(int x, int y) {
    if (x != 0 and y != 0) {
        return Sign(x) == Sign(y) ? x % y : y + (x % y);
    }
    return 0;
}

int Task() {
    int is_inside = 0;
    int flag = 1;
    int i = 0;
    int j = 0;
    Point p;
    p.x = START_I;
    p.y = START_J;
    int l = START_L;
    for (int k = 1; k <= ITERATIONS; ++k) {
        i = Mod((Abs(Max(p.x * (k + FOUR), p.y * (k + FIVE))) - Abs(Min(p.y * (k + SIX), l * (k + SEVEN)))), TWENTY);
        j = Mod(((THREE - Sign(p.x - p.y)) * Abs(Min(p.x * l + FIVE, Min(p.y * l - THREE, p.x * p.y + SIX)))),
                TWENTY_FIVE) -
            SEVEN;
        l = Mod(p.x, TEN) + Mod(p.y, TEN) + Mod(l, TEN);
        p.x = i;
        p.y = j;
        is_inside = CheckZone(p);
        if (is_inside) {
            printf("x = %d, y = %d, l = %d, result = %d, iteration = %d\n", p.x, p.y, l, is_inside, k);
            flag = 0;
        } else {
            printf("x = %d, y = %d, l = %d, result = %d\n", p.x, p.y, l, is_inside);
        }
    }
    if (flag) {
        printf("The point never hit the area");
    }
    return 0;
}