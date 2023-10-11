#pragma once

#include <stdio.h>

const int ITERATIONS = 50;
const int TEN = 10;
const int FIVE = 5;
const int TWENTY = 20;
const int I_FIRST = -22;
const int J_FIRST = 29;
const int L_FIRST = 4;

using Point = struct {
    int x;
    int y;
};

int Min(int num_1, int num_2) {
    if (num_1 < num_2) {
        return num_1;
    }
    return num_2;
}

int Max(int num_1, int num_2) {
    if (num_1 > num_2) {
        return num_2;
    }
    return num_1;
}

int Mod(int num, int base) {
    if (num > 0) {
        while (num > base) {
            num -= base;
        }
    } else {
        while (num < 0) {
            num += base;
        }
    }
    return num;
}

int Sign(int num) {
    if (num < 0) {
        return -1;
    } else if (num == 0) {
        return 0;
    }
    return 1;
}

int Abs(int num) {
    if (num > 0) {
        return num;
    }
    return -num;
}

int Pow(int num, int degree) {
    while (degree != 1) {
        num *= num;
        degree -= 1;
    }
    return num;
}

int CheckZone(Point p) {
    // Write a code here that checks whether a point belongs to a given area
    if (((Pow(p.x - TEN, 2) + Pow(p.y - TEN, 2)) <= Pow(TEN, 2)) &&
        ((Pow(p.x - TWENTY, 2) + Pow(p.y - TWENTY, 2)) <= Pow(TEN, 2))) {
        return 1;
    } else {
        return 0;
    }
}

int Task() {
    int i = I_FIRST;
    int j = J_FIRST;
    int l = L_FIRST;
    Point p;
    p.x = i;
    p.y = j;
    for (int k = 1; k <= ITERATIONS; ++k) {
        i = Sign(Min(p.x, p.y)) * Max(Mod(p.x + k, TWENTY), Mod(p.y + l, TWENTY));
        j = Abs(Max(p.x, p.y)) - k * Min(p.y, l);
        l = (k - l) / ((p.x + p.y + l) * Mod(p.x + p.y + l, FIVE) + 1);
        p.x = i;
        p.y = j;
        printf("k = %d, x = %d, y = %d, l = %d belong = %d \n", k, p.x, p.y, l, CheckZone(p));
        if (CheckZone(p)) {
            break;
        }
    }
    return 0;
    // write main code here
}