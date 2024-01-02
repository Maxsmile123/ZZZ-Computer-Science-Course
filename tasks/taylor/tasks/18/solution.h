#pragma once

#include <float.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

double Func(double x) {
    return ((1 + pow(x, 2)) / 2) * atan(x) - x / 2;
}

double Taylor(double x, int32_t i) {
    return pow(-1, i + 1) * (pow(x, 2 * i + 1) / (4 * pow(i, 2) - 1));
}

void CompareValues(double current_x, int32_t accuracy_factor) {
    double sum_taylor_row = 0.0;
    double function_value = Func(current_x);
    for (int32_t iteration = 1; iteration <= 100; ++iteration) {
        sum_taylor_row += Taylor(current_x, iteration);
        if (fabs(sum_taylor_row - function_value) < DBL_EPSILON * accuracy_factor) {
            printf("|%.3lf| %.15lf| %.15lf| %9d|\n", current_x, sum_taylor_row, function_value, iteration);
            break;
        }
    }
}

void OutputTable(double start_segment, double step_segment, int32_t number_partitions, int32_t accuracy_factor) {
    printf("--------------------------------------------------------\n");
    printf("|  x  |      Taylor      |       Func       | Iteration|\n");
    printf("--------------------------------------------------------\n");
    double current_x = start_segment;
    for (int32_t i = 0; i <= number_partitions; ++i) {
        CompareValues(current_x, accuracy_factor);
        current_x += step_segment;
    }
    printf("--------------------------------------------------------\n");
}

int Task() {
    FILE *file = nullptr;
    file = fopen("../tasks/taylor/tasks/18/example.txt", "r");
    double start_segment = 0.1;
    double end_segment = 0.6;
    int32_t number_partitions = 0;
    int32_t accuracy_factor = 0;
    // Если данные вводятся из консоли. Я буду брать из файла
    // printf("Enter the number you want to split the segment into\n");
    // scanf("%d", &number_partitions);
    // printf("Enter a number - the accuracy factor\n");
    // scanf("%d", &accuracy_factor);
    fscanf(file, "%d", &number_partitions);
    fscanf(file, "%d", &accuracy_factor);
    double step_segment = (end_segment - start_segment) / number_partitions;
    OutputTable(start_segment, step_segment, number_partitions, accuracy_factor);
    fclose(file);
    return 0;
}