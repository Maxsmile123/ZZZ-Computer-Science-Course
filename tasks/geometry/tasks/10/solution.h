#pragma once

#include <stdio.h>


const int I = 13;
const int J = 19;
const int L = 14;
const int ITERATIONS = 50;


typedef struct {
    int x;
    int y;
} Point;


int abs(int a) {
    return ((a >= 0) ? a : (a * -1));
}


int sign(int a) {
    return ((a < 0) ? -1 : 1);
}


int max(int a, int b) {
    return ((a > b) ? a : b);
}


int min(int a, int b) {
    return ((a < b) ? a : b);
}


int mod(int a, int x) {

    if (a < 0) return x + (a % x);
    return a % x;
}


int CheckZone(Point p) {
    return ((p.x + p.y + 10 <= 0) && (p.x + p.y + 20 >= 0));
}



int Task() {
   
    Point a;
    a.x = I;
    a.y = J;

    int l = L;
    int count = 0;


    for (int k = 0; k < ITERATIONS; ++k) {

        if (CheckZone(a)){
            count += 1;
        }


        int i = sign(a.x + 1) * abs(abs(k - a.y) - abs(a.x - l));
        int j = mod(a.y, 20) + max(mod(a.x, 20), min(a.y - k, l - k)) - 10;
        int q = mod(k * (a.x + 1) * (a.y + 2) * (l + 3), 20);

        a.x = i;
        a.y = j; 
        l = q;

    }


    printf("Number of points in the zone - %d\n", count);

    return 0;
}






