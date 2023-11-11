#pragma once
#include <stdio.h>

const int MAX_ITERATIONS = 50;
const int NUM_20 = 20;
const int NUM_35 = 30;
const int NUM_10 = 10;
const int NUM_5 = 5;
const int I_1 = -24;
const int J_1 = 4;
const int L_1 = -3;

typedef struct {
    int x;
    int y;
} Point;

int CheckZone(Point p) {
    int x_p = 0;
    int y_p = 0;

    x_p = (p.x - NUM_20) * (p.x - NUM_20);
    y_p = p.y * p.y;
    return (((x_p) * (NUM_5) + ((y_p) * (NUM_5))) <= (NUM_5 * NUM_10));
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
        return y - Abs(x);
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
    if (x == 0) {
        return 0;
    }
    if (x < 0) {
        return -1;
    }

    return 0;
}

int Task() {
    int i = I_1;
    int j = J_1;
    int l = L_1;
    int flag = 0;
    int ik = 0;
    int jk = 0;
    int lk = 0;
    Point p;

    for (int k = 0; k < MAX_ITERATIONS; ++k) {
        p.x = i;
        p.y = j;

        if (CheckZone(p) == 1) {
            printf("x = %d, y = %d, k = %d \n", i, j, k);
            flag = 1;
            break;
        }

        ik = Mod(((Abs(i + k)) * (j + (2 * k)) * (l + (3 * k))), NUM_35);
        jk = (Sign(Max(i, j))) * (Min(Mod(i + k, NUM_20), Mod(j + l, NUM_20)));
        lk = (i / 3) - ((Abs(i - k)) * (Sign(l - j)));
        i = ik;
        j = jk;
        l = lk;
    }

    if (flag == 0) {
        printf("No occurrence in 50 iterations");
    }

    return 0;
}
