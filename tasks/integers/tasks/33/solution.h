#pragma once

#include <stdint.h>
#include <stdio.h>


int32_t BASE = 2;


int Task() {

    int32_t number;
    int32_t count = 0;

    scanf("%d", &number);


    while (number > 0) {
        count += (number % BASE ? 1 : -1);
        number /= BASE;
    }


    if (count == 0) {
        printf("Число содержит равные количества нулей и сдиниц в двоичном виде\n");
    } else {
        printf("Число не содержит равные количества нулей и сдиниц в двоичном виде\n");
    }
    
    return 0;
}
