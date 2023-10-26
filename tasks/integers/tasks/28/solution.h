#include <stdint.h>
#include <stdio.h>

const int TEN = 10;

int Task() {
    // write your solution here
    int32_t number_in_10d = 0;
    int64_t number_in_2d = 0;
    int64_t multyplier = 1;
    scanf("%d", &number_in_10d);
    if (number_in_10d < 0) {
        number_in_10d *= -1;
        printf("-");
    }
    while (number_in_10d > 0) {
        number_in_2d += (number_in_10d % 2) * multyplier;
        number_in_10d /= 2;
        multyplier *= TEN;
    }
    printf("%ld\n", number_in_2d);
    return 0;
}