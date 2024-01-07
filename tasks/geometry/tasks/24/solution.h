#pragma once

#include <math.h>
#include <stdio.h>

typedef struct {
    int x;
    int y;
} Point;

int Max(int a, int b) {
    return a > b ? a : b;
}

int Min(int a, int b) {
    return a < b ? a : b;
}

int Sign(int n) {
    if (n < 0) {
        return -1;
    } else if (n > 0) {
        return 1;
    }
    return 0;
}

int CheckZone(Point p) {
    if (p.x <= (p.y - 10) && (p.y <= p.x * (-1) + 10) && (p.x >= -10)) {
        return 1;
    }
    return 0;
}

int Task() {
    int i = 20;
    int j = 0;
    int l = 11;
    int i1 = 0;
    int j1 = 0;
    int l1 = 0;
    for (int k = 0; k < 50; k++) {
        Point p = {i, j};
        if (CheckZone(p) == 1) {
            return 1;
        }
        i1 = ((i - k) * Max(j, l) + (j - k) * Min(i, l) + (l - k) * Max(i, j)) % 23;
        j1 = ((-1) * (i - k) * Min(j, l) + (j - k) * Max(i, l) + (l - k) * Min(i, j)) % 27;
        l1 = abs(i + j - l - k) * Sign(i - j + l - k);
        i = i1;
        j = j1;
        l = l1;
    }
    return 0;
}
