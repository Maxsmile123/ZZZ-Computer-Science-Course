#pragma once

#include <stdio.h>

typedef struct {
    int x;
    int y;
} Point;

int CheckZone(Point p) {
    // Write a code here that checks whether a point belongs to a given area
    return (p.x + p.y + 10 <= 0) && (p.x + p.y + 20 >= 0);
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

long long POW(int number, int p) {
    long long result = 1;
    while (p--) {
        result *= number;
    }
    return result;
}

int Task() {
    // start coordinates
    Point dot = {-3, -4};
    int parameter = 12;

    for (int step = 1; step <= 50; ++step) {
        int i = ABS(dot.x - parameter) + MIN(dot.y % 10, (parameter * step) % 10) - 20;
        int j = MAX(step - dot.x, MIN(dot.y, MAX(dot.x - parameter, dot.y - parameter))) % 30;
        parameter = POW(parameter, 2) % 20 - MAX(dot.x, dot.y) % (step + 1);
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
