#pragma once

#include <stdint.h>
#include <stdio.h>

typedef enum {
    START,
    OPEN_FILE,
    READ_FILE,
    CHECK,
    PRINT,
    CLOSE_FILE,
    END
    // struct with states for your KA
} State;

int Task() {
    // write your solution here
    State state = START;
    FILE* file = nullptr;
    const char* path = "../tasks/finite_state_machine/tasks/23/file.txt";
    int64_t lim = 65535;
    int64_t number = 0;
    int64_t count = 0;
    while (state != END) {
        switch (state) {
            case START:
                state = OPEN_FILE;
                break;
            case OPEN_FILE:
                file = fopen(path, "r");
                state = READ_FILE;
                break;
            case READ_FILE:
                if (feof(file) != 1) {
                    fscanf(file, "%ld", &number);
                    state = CHECK;
                    break;
                }
                state = PRINT;
                break;
            case CHECK:
                if (number > 0 && number < lim) {
                    count++;
                }
                state = READ_FILE;
                break;
            case PRINT:
                printf("%ld\n", count);
                state = CLOSE_FILE;
                break;
            case CLOSE_FILE:
                fclose(file);
                state = END;
                break;
            case END:
                break;
        }
    }
    return 0;
}
