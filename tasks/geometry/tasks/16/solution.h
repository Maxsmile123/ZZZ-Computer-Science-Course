#pragma once

#include <stdio.h>

typedef struct Pnt {
    int x;
    int y;
} Point;

int CheckZone(Point p) {
    // Write a code here that checks whether a point belongs to a given area
    const int b1 = 10;
    const int b2 = 20;
    return (p.x + p.y + b1 <= 0) && (p.x + p.y + b2 >= 0);
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

int Pow(int number, unsigned int p) {
    int result = 1;
    while (p--) {
        result *= number;
    }
    return result;
}

int Mod(int number_1, int number_2) {
    int result = number_1 % number_2;
    return (result < 0) ? Abs(number_2) + result : result;
}

const int MAX_ITERATIONS = 50;

const int P1_I = 10;
const int P2_I = -20;
const int P_J = 30;
const int P_L = 20;

const int I0 = -30;
const int J0 = -4;
const int L0 = 12;

int Task() {
    // start coordinates
    Point dot = {I0, J0};
    int l = L0;
    for (int step = 1; step <= MAX_ITERATIONS; ++step) {
        int i = Abs(dot.x - l) + Min(Mod(dot.y, P1_I), Mod(l * step, P1_I)) + P2_I;
        int j = Mod(Max(step - dot.x, Min(dot.y, Max(dot.x - l, dot.y - l))), P_J);
        l = Mod(Pow(l, 2), P_L) - Mod(Max(dot.x, dot.y), step + 1);
        dot = {i, j};
        printf("Step: %d, Dot: (%d, %d)\n", step, dot.x, dot.y);
        if (CheckZone(dot)) {
            printf("In step #%d the dot enter the area.\n", step);
            return 0;
        }
    }
    printf("The dot didn't enter the area within 50 steps.\n");
    return 0;
}
