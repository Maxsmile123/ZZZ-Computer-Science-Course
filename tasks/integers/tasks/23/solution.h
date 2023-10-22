#pragma once

#include <stdint.h>
#include <stdio.h>

int Task() {
    // write your solution here
    int count_number = 0;
    char c = 0;
    while ((c = getchar()) != EOF) {
        count_number += 1;
        if ((count_number % 2) != 0) {
            printf("%c", c);
        }
    }
    return 0;
}
