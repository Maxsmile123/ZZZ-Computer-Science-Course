#pragma once

#include <stdio.h>

const int STEPS = 50;

int Mod(int x, int y) {
    if (y != 0) {
        return x % y;
    } else {
        return 0;
    }
}

int Square(int x) {
    int result = x * x;
    return result;
}

int Sign(int x) {
    if (x > 0) {
        return 1;
    } else if (x < 0) {
        return -1;
    } else {
        return 0;
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

typedef struct {
    int x;
    int y;
} Point;

int CheckZone(Point p) {
    return (p.x + p.y >= -10 && p.x + p.y <= -20);
}

int Task() {
    int points_in_zone = 0;
    int i = -22;
    int j = 14;
    int l = -14;
    Point p;
    p.x = i;
    p.y = j;
    for (int k = 1; k <= STEPS; ++k) {
        if (CheckZone(p)) {
            points_in_zone += 1;
        }
        i = Mod((p.x * Min(p.y, l) + p.y * Min(p.x, l) + Square(k)), 20);
        j = Mod((Mod(p.x, 10 - k) * (Mod(p.y, 10 + k)) * (Mod(l, 10 - k))), 25);
        l = Max(Mod(Min(p.x + p.y, p.x + l), 25), Mod(Max(p.x + l, p.y + k), 20)) + 10;
        p.x = i;
        p.y = j;
    }
    if (points_in_zone > 0) {
        printf("Number of points belonging to the zone: %d\n", points_in_zone);
    } else {
        printf("The point didn't fall into the area beyond 50 iterations\n");
    }
    return 0;
}
