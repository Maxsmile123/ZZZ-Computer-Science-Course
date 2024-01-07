#pragma once

#include <stdio.h>

int Min(int a, int b) {
    if (a < b) {
        return a;
    }
    return b;
}

int Abs(int num) {
    if (num >= 0) {
        return num;
    }
    return -num;
}

int Sign(int a) {
    if (a < 0) {
        return -1;
    }
    if (a > 0) {
        return 1;
    }
    return 0;
}

int Mod(int a, int b) {
    if (b != 0) {
        return a % b;
    }
    return 0;
}

typedef struct {
    int x;
    int y;
} Point;

int CheckZone(Point p) {
    // Write a code here that checks whether a point belongs to a given area
    if (5 <= p.x && 15 >= p.x && 5 <= p.y && 15 >= p.y) {
        return 1;
    }
    return 0;
}

int Task() {
    // write main code here
    int i = -11;
    int j = -6;
    int l = -5;
    Point p;
    p.x = i;
    p.y = j;
    int l_new = l;
    for (int k = 1; k <= 50; k++) {
        p.x = (i + j + l) * (k + 1) % 25 - i * j * l * (k + 2) % 10 + 10;
        p.y = Min((i + j + k) * (k + 3) % 25, i * j * l * (k + 4) % 25) + 10;
        l_new = 2 * Sign(l) * Abs((i + j + l) * (k + 5) % 10 - i * j * l * (k + 6) % 25);
        i = p.x;
        j = p.y;
        l = l_new;
        if (CheckZone(p)) {
            printf("Точка попадает в указанную область: %d, %d, %d; итерация: %d\n", i, j, l, k);
            break;
        }
    }
    if (!CheckZone(p)) {
        printf("Точка не попадает в указанную область\n");
    }
    return 0;
}
