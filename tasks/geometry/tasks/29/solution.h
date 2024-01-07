#pragma once

#include <stdio.h>

const int ZERO = 0;
const int MAX_ITERATIONS = 50;
const int THIRTY = 30;
const int ONE = 1;
const int SEMIAXIS_X = 10;
const int SEMIAXIS_Y = 5;
const int I_0 = -7;
const int J_0 = -19;
const int L_0 = 4;

typedef struct {
    int x;
    int y;
} Point;

int Max2(int num1, int num2) {
    if (num1 > num2) {
        return num1;
    } else {
        return num2;
    }
}

int Max3(int num1, int num2, int num3) {
    if ((num1 >= num2) && (num1 >= num3)) {
        return num1;
    } else if ((num2 >= num1) && (num2 >= num3)) {
        return num2;
    } else {
        return num3;
    }
}

int Min(int num1, int num2) {
    if (num1 < num2) {
        return num1;
    } else {
        return num2;
    }
}

int Abs(int num) {
    if (num > 0) {
        return num;
    } else {
        return num * -1;
    }
}

int Mod(int num1, int num2) {
    int res = 0;
    if (num1 >= 0) {
        while (num1 >= num2) {
            num1 = num1 - num2;
        }
        res = num1;
    } else {
        while (num1 <= res) {
            res = res - Abs(num2);
        }
        res = num1 - res;
    }
    return res;
}

int Sign(int num) {
    if (num > 0) {
        return 1;
    } else if (num < 0) {
        return -1;
    } else {
        return 0;
    }
}

int Square(int num) {
    return num * num;
}

int CheckZone(Point p) {
    // Write a code here that checks whether a point belongs to a given area
    if (Square(p.x) / Square(SEMIAXIS_X) + Square(p.y) / Square(SEMIAXIS_Y) <= ONE) {
        printf("Точка с координатами %d %d попадает в область\n", p.x, p.y);
        return 1;
    } else {
        printf("Точка с координатами %d %d не попадает в область\n", p.x, p.y);
        return 0;
    }
}

int Task() {
    // write main code here
    Point p;
    p.x = I_0;
    p.y = J_0;
    int l = L_0;
    int ik = 0;
    int jk = 0;
    int lk = 0;
    int hit = ZERO;
    for (int cnt = ONE; cnt <= MAX_ITERATIONS; ++cnt) {
        if (CheckZone(p)) {
            hit = hit + 1;
        }
        ik = p.x;
        jk = p.y;
        lk = l;
        p.x = Mod(Max3(ik * jk, ik * lk, jk * lk), THIRTY) + cnt;
        p.y = Abs(jk - lk) * Sign(ik) - Abs(ik - lk) * Sign(jk);
        l = Min(jk, Max2(jk, Min(lk, Max2(ik - lk, jk - lk))));
    }

    printf("Точка попала в область %d раз\n", hit);

    return 0;
}
