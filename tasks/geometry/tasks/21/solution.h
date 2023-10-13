#pragma once

#include <stdio.h>
const int ELEVEN = 11;
const int MINUS_TWELVE = -12;
const int MINUS_TWENTY_TWO = -22;
const int TWENTY = 20;
const int TEN = 10;


typedef struct {
    int x;
    int y;
} Point;

int Abs(int n) {
    if (n >= 0) {
        return n;
    }
    return -n;
}

int Mod(int a, int b) {
    float res = 0;
    if (a >= 0) {
        while (a >= b) {
            a = a - b;
        }
        res = a;
    } else {
        while (a <= res) {
            res = res - Abs(b);
        }
        res = a - res;
    }
    return res;
}

int Min(int a, int b) {
    if (a <= b) {
        return a;
    }
    return b;
}

int Max(int a, int b) {
    if (a >= b) {
        return a;
    }
    return b;
}

int Sign(int a) {
    if (a >= 0) {
        return 1;
    } else {
        return -1;
    }
}


int CheckZone(Point p) {
    // Write a code here that checks whether a point belongs to a given area
    if (p.y >= p.x + 10 && p.y <= -1 * p.x + 10 && p.x >= -10) {
        printf("Точка с координатами %d %d попадает в область\n", p.x, p.y);
    } else {
        printf("Точка с координатами %d %d НЕ попадает в область\n", p.x, p.y);
    }
    return 0;
}

int Task() {
    // write main code here
    Point p;
    p.x = MINUS_TWELVE;
    p.y = MINUS_TWENTY_TWO;
    int l = ELEVEN;
    for (int i = 0; i < 50; ++i) {
        CheckZone(p);
        p.x = Max(Mod(Min(p.x - p.y, p.y - l), TWENTY), Mod(Min(p.x - l, p.y - i), TWENTY)) + TEN;
        p.y = Sign(p.x - p.y) * Min(Mod(p.x, TWENTY), Mod(p.y, TWENTY)) -
              Mod(Max(Abs(p.x - l), Abs(i - TWENTY)), TWENTY) + TWENTY;
        l = Mod(p.x, TEN) * Mod(p.y, TEN) + Mod(l, TEN);
    }
    return 0;
}
