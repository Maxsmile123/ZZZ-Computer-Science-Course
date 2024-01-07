#pragma once

#include <stdbool.h>
#include <stdio.h>

#include "fsm_realization.h"

bool IsFileEmpty(FILE *file) {
    fseek(file, 0, SEEK_END);
    bool is_empty = (ftell(file) == 0);
    rewind(file);
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
}