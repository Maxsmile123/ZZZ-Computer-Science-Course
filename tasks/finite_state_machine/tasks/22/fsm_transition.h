

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>


#include "fsm_structs.h"

int Conditional(const char* word) {
    int count_char = 0;
    int is_word = 0;
    for (int i = 0; i < strlen(word); i++) {
        if (!isspace(word[i]) && !is_word) {
            is_word = 1;
            count_char++;
        } else if (isspace(word[i])) {
            is_word = 0;
        }
    }
    return count_char;
}

void Transition(Machine* machine, FILE* file) {
    int32_t count = 0;
    while (machine->current_state != END) {
        char word[255] = {0};
        if (machine->current_state == SCAN) {
            char symbol =
                    ' ';
            char is_eof = 0;
            for (int i = 0; i < 255; ++i) {
                symbol = (char)fgetc(file);
                if (symbol != EOF) {

                    if (symbol == ' ' || symbol == '\n') {

                        break;
                    } else {
                        word[i] = symbol;
                    }

                } else {
                    is_eof = 1;
                    break;
                }
            }
            if (strlen(word)) {
                if (is_eof) {
                    machine->current_state = LAST_CHECK;
                } else {
                    machine->current_state = CHECK;
                }
            } else if (is_eof) {
                machine->current_state = OUTPUT;
            }
        }
        if (machine->current_state == CHECK) {
            if (Conditional(word) >= 3) {
                ++count;
            }
            machine->current_state = SCAN;
            continue;
        }
        if (machine->current_state == LAST_CHECK) {
            if (Conditional(word) >= 3) {
                ++count;
            }
            machine->current_state = OUTPUT;
        }
        if (machine->current_state == OUTPUT) {
            printf("Number of words with at least 3 letters: %d\n", count);
            machine->current_state = END;
        }
    }
}