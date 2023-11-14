#pragma once

#include <stdio.h>
int Sign(int x){
    if (x > 0) {
        return 1;
    } else if  (x < 0) {
        return -1;
    } else {
        return 0;
    }
}

int Mod(int x, int y) {
    if (y != 0)  {
        return x % y;
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

int Abs(int x) {
    if (x < 0) {
        return (-1) * x;
    } else {
        return x;
    }
}

int Square_degree(int a) {
    return a * a;
}

const int X_0 = 20;
const int Y_0 = 0;
const int I_0 = -1;
const int J_0 = 2;
const int L_0 = -1;
const int ITERATION_COUNT = 50;
const int THIRTYFIVE = 35;
const int THIRTY = 30;
const int TWENTY = 20;
const int TWENTYFIVE = 25;
const int ONE = 1;
const int SEMI_MAJOR_AXIS = 10;
const int SEMI_MINOR_AXIS = 5;



typedef struct {
    int x;
    int y;
} Point;

int CheckZone(Point p) {
    // Write a code here that checks whether a point belongs to a given area
    return ((p.x - X_0) / Square_degree(SEMI_MAJOR_AXIS)) + ((p.y - Y_0) / Square_degree(SEMI_MINOR_AXIS)) == ONE;
    return 0;
}

int Task() {
    // write main code here
    int i = I_0;
    int j = J_0;
    int l = L_0;
    Point p;
    p.x = i;
    p.y = j;

    int owned_point_counter = 0;
    
    
    for (int k = ONE; k <= ITERATION_COUNT; ++k) {
        i = Mod((Sign(p.x - k) * l - Sign(p.y - l) * p.x + Sign(p.x - l) * p.y - k), THIRTYFIVE);
        j = Max((p.x * Max(p.y, l)), THIRTY) + Mod((p.y * Min(p.x, l)),TWENTY) - k;
        l = Mod(((p.x + k) * (p.y - k) * (l + k)), TWENTYFIVE); 
        p.x = i;
        p.y = j;
        printf("k = %d, x = %d, y = %d, l = %d belong %d \n", k, p.x, p.y, l, Check_Zone(p));
    
        if (Check_Zone(p)) {
            owned_point_counter++;
        }
    }
    
    printf("Number of points belonging to the area: %d\n", owned_point_counter);
    return 0;
}
