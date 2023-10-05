#pragma once

#include <stdio.h>

typedef struct {
    int x;
    int y;
} Point;

int CheckZone(Point p) {
    // Write a code here that checks whether a point belongs to a given area
    
    float abs(float n){
        if (n >= 0){
            return n;
        } 
        return -n;
    }
    
    float mod(float a, float b){
        float res = 0;
        if (a >= 0){
            while (a >= b){
                a = a - b;
            }
            res = a;
        } else{
            while (a <= res){
                res = res - abs(b);
            }
            res = a - res;
        }
        return res;
    }
    
    float min(float a, float b){
        if (a <= b){
            return a;
        }
        return b;
    }
    
    float max(float a, float b){
        if (a >= b){
            return a;
        }
        return b;
    }
    
    float sign(float a){
        if (a >= 0){
            return 1.0;
        } else{
            return -1.0;
        }
    }
    
    int main(){
        float x = -12;
        float y = -22;
        float l = 11;
        int success = 0;
        for (int i = 0; i < 50; ++i){
            if (y >= x + 10 && y <= -1 * x + 10 && x >= -10){
                printf("%f %f\n", x, y);
                success = 1;
            }
            x = max(mod(min(x - y, y - l), 20), mod(min(x - l, y - i), 20)) + 10;
            y = sign(x - y) * min(mod(x, 20), mod(y, 20)) - mod(max(abs(x - l), abs(i - 20)), 20) + 20;
            l = mod(x, 10) * mod(y, 10) + mod(l, 10);
        }
        if (success == 0){
            printf("%s", "Точка не попала в указанную область.");
        }
    }
    return 0;
}

int Task() {
    // write main code here
    return 0;
}
