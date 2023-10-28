#pragma once

#include <stdio.h>
const int ELEVEN = 11;
const int MINUS_TWELVE = -12;
const int MINUS_TWENTY_TWO = -22;
const int TWENTY = 20;
const int TEN = 10;
const int MINUS_TEN = -10;
const int MINUS_ONE = -1;
const int MAX_ITERATION = 50;

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
    int res = 0;
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
    if (a > 0) {
        return 1;
    } else if (a < 0) {
        return -1;
    } else {
        return 0;
    }
}

int CheckZone(Point p) {
    // Write a code here that checks whether a point belongs to a given area
    int is_local_success = 0;
    if (p.y >= p.x + TEN && p.y <= MINUS_ONE * p.x + TEN && p.x >= MINUS_TEN) {
        printf("Tочка с координатами %d %d попадает в область\n", p.x, p.y);
        is_local_success = 1;
    } else {
        printf("Точка с координатами %d %d НЕ попадает в область\n", p.x, p.y);
    }
    return is_local_success;
}

int Task() {
    // write main code here
    Point p;
    p.x = MINUS_TWELVE;
    p.y = MINUS_TWENTY_TWO;
    int l = ELEVEN;
    int is_global_success = 0;
    int temp_x = 0;
    int temp_y = 0;
    int temp_l = 0;
    for (int i = 0; i < MAX_ITERATION; ++i) {
        if (CheckZone(p) == 1) {
            is_global_success = 1;
            break;
        }
        temp_x = p.x;
        temp_y = p.y;
        temp_l = l;
        p.x = Max(Mod(Min(temp_x - temp_y, temp_y - temp_l), TWENTY), Mod(Min(temp_x - temp_l, temp_y - i), TWENTY)) +
              TEN;
        p.y = Sign(temp_x - temp_y) * Min(Mod(temp_x, TWENTY), Mod(temp_y, TWENTY)) -
              Mod(Max(Abs(temp_x - temp_l), Abs(i - TWENTY)), TWENTY) + TWENTY;
        l = Mod(temp_x, TEN) * Mod(temp_y, TEN) + Mod(temp_l, TEN);
    }
    if (!is_global_success) {
        printf("Точка не попала в область за 50 итераций.\n");
    }
    return 0;
}
