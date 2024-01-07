#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Task() {
    char filename[50] = {""};
    printf("file name: ");
    scanf("%s", filename);
    FILE *matrix_file = fopen(filename, "r");
    char line[50] = {""};
    int counter = 0;
    char temp = 'a';
    int length = 0;  // только работает если все числа меньше 10 и в конце строк нет пробелов
    while (fgets(line, 50, matrix_file)) {
        while (!(line[length] == line[length + 1])) {
            length += 1;
        }
        length -= 1;
        temp = line[2 * counter];
        line[2 * counter] = line[length - (2 * counter + 1)];
        line[length - (2 * counter + 1)] = temp;
        counter += 1;
        printf("%s", line);
    }
    fclose(matrix_file);
    return 0;
}
