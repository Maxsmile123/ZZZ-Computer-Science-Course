#pragma once

#include <stdio.h>

typedef struct {
    int x;
    int y;
} Point;


const int A = 10
const int B = 20;
const int C = 12;
const int D = 50;


int CheckZone(Point p) {
    // Write a code here that checks whether a point belongs to a given area
    return (p.x + p.y + A <= 0) && (p.x + p.y + B >= 0);
}

int ABS(int number) {
    return (number < 0) ? -number : number;
}

int MIN(int num1, int num2) {
    return (num1 < num2) ? num1 : num2;
}

int MAX(int num1, int num2) {
    return (num1 > num2) ? num1 : num2;
}

int POW(int number, int p) {
    int result = 1;
    while (p--) {
        result *= number;
    }
    return result;
}

int Task() {
    // start coordinates
    Point dot = {-3, -4};
    int parameter = C;

    for (int step = 1; step <= D; ++step) {
        int i = ABS(dot.x - parameter) + MIN(dot.y % A, (parameter * step) % A) - B;
        int j = MAX(step - dot.x, MIN(dot.y, MAX(dot.x - parameter, dot.y - parameter))) % (A + B);
        parameter = POW(parameter, B / 10) % B - MAX(dot.x, dot.y) % (step + 1);
        dot.x = i;
        dot.y = j;

        int is_inside = CheckZone(dot);
        printf("%d. x = %d, y = %d and %d\n", step, dot.x, dot.y, is_inside);
        if (is_inside) {
            break;
        }
    }
    return 0;
}
