#pragma once
#include <stdio.h>

int Mod(int x, int y) {
    if (y != 0) {
        return x % y;
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

int Abs(int x) {
    if (x > 0) {
        return x;
    } else {
        return x * (-1);
    }
}

const int X_0 = 10;
const int Y_0 = 10;
const int R_SMALL = 5;
const int R_BIG = 10;
const int I_0 = -1;
const int J_0 = -1;
const int L_0 = -9;
const int ITERATIONS = 50;
const int TWENTY = 20;
const int TWENTYFIVE = 25;
const int THIRTY = 30;
const int ONE = 1;

typedef struct {
    int x;
    int y;
} Point;

int CheckZone(Point p) {
    int cord_x = p.x;
    int cord_y = p.y;
    if (((cord_x - X_0) * (cord_x - X_0) + (cord_y - Y_0) * (cord_y - Y_0) <= R_BIG * R_BIG) &&
        ((cord_x - X_0) * (cord_x - X_0) + (cord_y - Y_0) * (cord_y - Y_0) >= R_SMALL * R_SMALL)) {
        return 1;
    } else {
        return 0;
    }
}

int Task() {
    int i = I_0;
    int j = J_0;
    int l = L_0;
    Point p;
    p.x = i;
    p.y = j;

    int count_belong = 0;  // Счетчик точек, принадлежащих зоне

    for (int k = ONE; k <= ITERATIONS; ++k) {
        i = Mod(Max(p.y - k, l - k), THIRTY) + Mod(Max(p.x + l, p.y + k), TWENTY);
        j = Mod((Abs(p.x - l) * Sign(p.y + k) + (Abs(p.x - k) * (p.y + k))), TWENTY);
        l = Mod(((p.x + k) * (p.y - k) * (l + k)), TWENTYFIVE);
        p.x = i;
        p.y = j;
        printf("k = %d, x = %d, y = %d, l = %d belong = %d \n", k, p.x, p.y, l, CheckZone(p));

        if (CheckZone(p)) {
            count_belong++;
        }
    }

    printf("Number of points belonging to the zone: %d\n", count_belong);

    return 0;
}
