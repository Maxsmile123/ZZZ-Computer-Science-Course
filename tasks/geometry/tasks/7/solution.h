#pragma once

#include <stdbool.h>
#include <stdio.h>

const int INITIAL_VALUE_I = 11;
const int INITIAL_VALUE_J = 13;
const int INITIAL_VALUE_L = 10;
const int MAX_ITERATIONS = 50;
const int SQUARE_CENTER_X = 10;
const int SQUARE_CENTER_Y = 10;
const int SQUARE_EDGE = 10;
const int EIGHT = 8;
const int FIFTEEN = 15;
const int FIVE = 5;
const int FOURTEEN = 14;
const int TEN = 10;
const int THREE = 3;
const int TWENTY = 20;

typedef struct {
    int x;
    int y;
} Point;

int Abs(int n) {
    if (n < 0) {
        return -n;
    } else {
        return n;
    }
}

int Max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int Min(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

int Mod(int a, int b) {
    return (b + a % b) % b;
}

int CheckZone(Point p) {
    return ((p.x >= (SQUARE_CENTER_X - SQUARE_EDGE / 2)) && (p.x <= (SQUARE_CENTER_X + SQUARE_EDGE / 2)) &&
            (p.y >= (SQUARE_CENTER_Y - SQUARE_EDGE / 2)) && (p.y <= (SQUARE_CENTER_Y + SQUARE_EDGE / 2)));
}

int Task() {
    int i = INITIAL_VALUE_I;
    int j = INITIAL_VALUE_J;
    int l = INITIAL_VALUE_L;
    int hit_counter = 0;
    Point p;
    p.x = i;
    p.y = j;
    for (int k = 1; k <= MAX_ITERATIONS; ++k) {
        p.x = Abs(k - FIFTEEN) - Min(i / THREE, Mod(j + l, TEN)) - TWENTY;
        p.y = -(j + k) / FIVE + Abs(Mod(i * l, EIGHT));
        l = Max(Mod(i + j, FIFTEEN), Mod(l + k, FOURTEEN));
        if (CheckZone(p)) {
            ++hit_counter;
        }
        i = p.x;
        j = p.y;
        printf("p.x:%d, p.y:%d, l:%d, hit count:%d\n", p.x, p.y, l, hit_counter);
    }
    if (hit_counter == 0) {
        printf("No points hit square for 50 iterations\n");
    } else {
        printf("Points hit counter:%d\n", hit_counter);
    }
    return 0;
}