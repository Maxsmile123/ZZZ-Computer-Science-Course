#pragma once

#include <stdio.h>

typedef struct Pnt {
    int i;
    int j;
    int l;
} Point;

int CheckZone(Point p) {
    // Write a code here that checks whether a point belongs to a given area
    const int b1 = 10;
    const int b2 = 20;
    return (p.i + p.j + b1 <= 0) && (p.i + p.j + b2 >= 0);
}

int Abs(int number) {
    return (number < 0) ? -number : number;
}

int Min(int number_1, int number_2) {
    return (number_1 < number_2) ? number_1 : number_2;
}

int Max(int number_1, int number_2) {
    return (number_1 > number_2) ? number_1 : number_2;
}

int Pow(int number, int p) {
    int result = 1;
    while (p--) {
        result *= number;
    }
    return result;
}

int Mod(int number_1, int number_2) {
    int result = number_1 % number_2;
    return (result < 0) ? number_2 + result : result;
}

const int STEPS = 50;

const int P1_I = 10;
const int P2_I = -20;
const int P_J = 30;
const int P_L = 20;

const int I0 = -30;
const int J0 = -4;
const int L0 = 12;

int Task() {
    // start coordinates
    Point dot = {I0, J0, L0};
    for (int step = 1; step <= STEPS; ++step) {
        int i = Abs(dot.i - dot.l) + Min(Mod(dot.j, P1_I), Mod(dot.l * step, P1_I)) + P2_I;
        int j = Mod(Max(step - dot.i, Min(dot.j, Max(dot.i - dot.l, dot.j - dot.l))), P_J);
        int l = Mod(Pow(dot.l, 2), P_L) - Mod(Max(dot.i, dot.j), step + 1);
        dot = {i, j, l};

        printf("Step: %d, Dot: (%d, %d), Is dot in zone: %d\n", step, dot.i, dot.j, CheckZone(dot));
        if (CheckZone(dot)) {
            break;
        }
    }

    return 0;
}
