#pragma once
#include <stdio.h>

int Sign(int x) {
    if (x > 0) {
        return 1;
    } else if (x < 0) {
        return -1;
    } else {
        return 0;
    }
}

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

int Abs(int x) {
    if (x > 0) {
        return x;
    } else {
        return x * (-1);
    }
}

const int MAX_ITERATIONS = 50;
const int I_0 = 18;
const int J_0 = -9;
const int L_0 = 5;
const int X_0 = 10;
const int Y_0 = 10;
const int R_BIG = 10;
const int R_SMALL = 5;
const int THIRTY = 30;
const int TWENTY = 20;
const int TEN = 10;

typedef struct {
    int x;
    int y;
} Point;

int CheckZone(Point p) {
    return (((p.x - X_0) * (p.x - X_0) + (p.y - Y_0) * (p.y - Y_0) <= R_BIG * R_BIG) &&
            ((p.x - X_0) * (p.x - X_0) + (p.y - Y_0) * (p.y - Y_0) >= R_SMALL * R_SMALL));
}

int Task() {
    int i = I_0;
    int j = J_0;
    int l = L_0;
    Point p;
    p.x = i;
    p.y = j;
    int flag = 0;

    for (int k = 1; k <= MAX_ITERATIONS; ++k) {
        if (CheckZone(p)) {
            flag = 1;
            printf("The point with the coordinates '%d', '%d' hit into the zone", p.x, p.y);
            break;
        }

        i = Mod(p.x * Max(p.x, l), THIRTY) + Mod(p.y * Min(p.x, l), TWENTY) + k;
        j = Min(p.x, Max(p.y, Min(l, Max(p.x - l, p.y - l))));
        l = Sign(k - 10) * Abs(p.x - p.y + l - k);
    }

    if (flag == 0) {
        printf("The point did not hit the area in 50 iterations\n");
    }

    return 0;
}
