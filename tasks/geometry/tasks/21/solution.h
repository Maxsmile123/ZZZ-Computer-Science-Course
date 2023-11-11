#pragma once

#include <stdio.h>
const int MAX_ITERATIONS = 50;

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
    if (b != 0) {
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
    } else {
        return 0;
    }
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
    if (p.y >= p.x + 10 && p.y <= -1 * p.x + 10 && p.x >= -10) {
        printf("Точка с координатами %d %d попадает в область\n", p.x, p.y);
    } else {
        printf("Точка с координатами %d %d НЕ попадает в область\n", p.x, p.y);
    }
    return (p.y >= p.x + 10 && p.y <= -1 * p.x + 10 && p.x >= -10);
}

int Task() {
    // write main code here
    Point p;
    p.x = -12;
    p.y = -22;
    int l = 11;
    int is_success = 0;
    int temp_x = 0;
    int temp_y = 0;
    for (int i = 0; i < MAX_ITERATIONS; ++i) {
        if (CheckZone(p)) {
            is_success = 1;
            break;
        }
        temp_x = p.x;
        temp_y = p.y;
        p.x = Max(Mod(Min(temp_x - temp_y, temp_y - l), 20), Mod(Min(temp_x - l, temp_y - i), 20)) + 10;
        p.y = Sign(temp_x - temp_y) * Min(Mod(temp_x, 20), Mod(temp_y, 20)) -
              Mod(Max(Abs(temp_x - l), Abs(i - 20)), 20) + 20;
        l = Mod(temp_x, 10) * Mod(temp_y, 10) + Mod(l, 10);
    }
    if (!is_success) {
        printf("Точка не попала в область за 50 итераций.\n");
    }
    return 0;
}
