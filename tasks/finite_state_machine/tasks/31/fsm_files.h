#pragma once

#include <stdbool.h>
#include <stdio.h>

#include "fsm_realization.h"

bool IsFileEmpty(FILE *file) {
    fseek(file, 0, SEEK_END);            // Перемещаем указатель в конец файла
    bool is_empty = (ftell(file) == 0);  // Проверяем, пуст ли файл
    rewind(file);                        // Возвращаем указатель в начало файла
    return is_empty;
}

bool OpenFile(FILE **file, const char *filename) {
    *file = fopen(filename, "r");
    if (*file == NULL) {
        printf("Error: Unable to open file '%s'.\n", filename);
        return false;
    }
    if (IsFileEmpty(*file)) {
        printf("Error: File '%s' is empty.\n", filename);
        fclose(*file);
        return false;
    }
    return true;
}

void ProcessFile(StateMachine *sm, FILE *file) {
    char c = '\0';
    while ((c = (char)fgetc(file)) != EOF) {
        Step(sm, c);
    }

    if (sm->binary_counter == 0) {
        printf("Error: No binary numbers found in the file.\n");
        sm->cur_state = ERROR_STATE;
    } else if (sm->binary_counter < 3) {
        printf("Error: Insufficient binary numbers found. Found only %d, need at least 3.\n", sm->binary_counter);
        sm->cur_state = ERROR_STATE;
    }
}