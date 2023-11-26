#pragma once

#include <stdio.h>

const int MAX_ITEREATIONS = 50;
const int CORD_X1 = -10;
const int CORD_X2 = 0;
const int CORD_Y1 = 0;
const int CORD_Y2 = 10;
const int CORD_X3 = -10;
const int CORD_Y3 = 20;
const int MOD_20 = 20;
const int MOD_30 = 30;

typedef struct {
    int x;
    int y;
} Point;

int CheckZone(Point p) {
    return ((p.y) >= ((p.x) + CORD_Y2)) && ((p.y) <= ((-1) * (p.x) + CORD_Y2)) && (((p.x) > CORD_X3));
}

int Abs(int x) {
    if (x > 0) {
        return x;
    } else {
        return x * -1;
    }
}

int Mod(int x, int y) {
    if (y > 0) {
        return x % y;
    } else {
        return Abs(x) - Abs(y) * (x / y);
    }
}

int Sign(int x) {
    if (x > 0) {
        return 1;
    }

    if (x < 0) {
        return -1;
    } else {
        return 0;
    }
}

int Max(int x, int y) {
    if (x > y) {
        return x;
    } else {
        return y;
    }
}

int Min(int x, int y) {
    if (x < y) {
        return x;
    } else {
        return y;
    }
}

int Task() {
    const int i_start = -8;
    const int j_start = -5;
    const int l_start = 12;
    int i_0 = i_start;
    int j_0 = j_start;
    int l_0 = l_start;
    Point p;
    int i_1 = 0;
    int j_1 = 0;
    int l_1 = 0;
    bool flag = false;
    for (int i = 0; i < MAX_ITEREATIONS; ++i) {
        p.x = i_0;
        p.y = j_0;
        if (CheckZone(p)) {
            printf("x=%d, y=%d k=%d\n", i_0, j_0, i);
            flag = true;
        }
        i_1 = Mod((i_0 ^ 2) / (Abs(j_0 - l_0) + i + 1) - (j_0 ^ 2) / (Abs(i_0 - l_0) + i + 1), MOD_30);
        j_1 = Sign(l_0 * Min(i_0, j_0)) - Sign(j_0 * Max(i_0, l_0)) + i;
        l_1 = Mod((i_0 - j_0) * (j_0 - l_0) * (l_0 - i_0), MOD_20);
        i_0 = i_1;
        j_0 = j_1;
        l_0 = l_1;
    }
    if (flag == false) {
        printf("Таких точек нет");
    }
    return 0;
}
