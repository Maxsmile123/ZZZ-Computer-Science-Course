#pragma once

#include <stdio.h>

const int ITERATIONS = 50;
const int TEN = 10;
const int FIVE = 5;
const int TWENTY = 20;
const int I_FIRST = -22;
const int J_FIRST = 29;
const int L_FIRST = 4;

typedef struct {
    int x;
    int y;
} Point;

int Min(int num_1, int num_2) {
    if (num_1 < num_2) {
        return num_1;
    }
    return num_2;
}

int Max(int num_1, int num_2) {
    if (num_1 > num_2) {
        return num_1;
    }
    return num_2;
}

int Mod(int num, int base) {
    int remains = num;
    if (remains > 0) {
        while (remains > base) {
            remains -= base;
        }
    } else {
        while (remains < 0) {
            remains += base;
        }
    }
    return remains;
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

int Pow(int num, unsigned int degree) {
    int result = num;
    if (degree == 0) {
        return 1;
    } else {
        while (degree != 1) {
            result *= result;
            degree -= 1;
        }
    }
    return result;
}

int CheckZone(Point p) {
    // Write a code here that checks whether a point belongs to a given area
    return (((Pow(p.x - TEN, 2) + Pow(p.y - TEN, 2)) <= Pow(TEN, 2)) &&
            ((Pow(p.x - TWENTY, 2) + Pow(p.y - TWENTY, 2)) <= Pow(TEN, 2)));
}

int Task() {
    int i = I_FIRST;
    int j = J_FIRST;
    int l = L_FIRST;
    Point p;
    p.x = i;
    p.y = j;
    for (int k = 1; k <= ITERATIONS; ++k) {
        p.x = Sign(Min(p.x, p.y)) * Max(Mod(p.x + k, TWENTY), Mod(p.y + l, TWENTY));
        p.y = Abs(Max(p.x, p.y)) - k * Min(p.y, l);
        l = (k - l) / ((p.x + p.y + l) * Mod(p.x + p.y + l, FIVE) + 1);
        printf("k = %d, x = %d, y = %d, l = %d belong = %d \n", k, p.x, p.y, l, CheckZone(p));
        if (CheckZone(p)) {
            break;
        }
        if (k == ITERATIONS) {
            printf("The point did not fall into the specified area for %d iterations", ITERATIONS);
        }
    }
    return 0;
    // write main code here
}