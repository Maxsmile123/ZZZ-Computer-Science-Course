#pragma once

#include <stdio.h>

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

int Max_2(int a, int b) {
    if (a > b) {
        return a; 
    } else {
        return b; 
    } 
} 
 
int Max_3(int a, int b, int c) {
    if ((a >= b) && (a >= c)) {
        return a; 
    } else if((b >= a) && (b >= c)) {
        return b; 
    } else {
        return c; 
    } 
} 
 
int Min(int a, int b) {
    if (a < b) {
        return a; 
    } else {
        return b; 
    } 
} 
 
int Abs(int a) {
    if (a > 0) {
        return a; 
    } else {
        return a * -1; 
    } 
} 
 
int Mod(int a, int b) {
    int res = 0;
    if (a >= 0) {
        while (a >= b) {
            a = a - b; 
        } 
        res = a; 
    } else {
        while (a <= res) {
            res = res - Abs(b); 
        } 
        res = a - res;
    } 
    return res;
} 
 
int Sign(int a) {
    if (x > 0) {
        return 1;
    } else if (x < 0) {
        return -1;
    } else {
        return 0;
    } 
} 
 
int Square(int a) {
    return a * a;
}

int CheckZone(Point p) {
    // Write a code here that checks whether a point belongs to a given area
    if (Square(p.x) / Square(SEMIAXIS_X) + Square(p.y) / Square(SEMIAXIS_Y) <= ONE) {
        printf("Точка с координатами %d %d попадает в область\n", p.x, p.y);
    } else {
        printf("Точка с координатами %d %d не попадает в область\n", p.x, p.y);
    }

    return 0;
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
    for (int cnt = 0, cnt < MAX_ITERATIONS, ++cnt) {
        CheckZone(p);
        ik = p.x;
        jk = p.y;
        lk = l;
        p.x = Mod(Max_3(ik * jk, ik * lk, jk * lk), THIRTY) + cnt;
        p.y = Abs(jk - lk) * Sign(ik) - Abs(ik - lk) * Sign(jk);
        l = Min(jk, Max_2(jk, Min(lk, Max_2(ik - lk, jk - lk))));
    }

    return 0;
}