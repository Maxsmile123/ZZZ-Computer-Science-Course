#pragma once

#include <stdbool.h>
#include <stdio.h>

#include "fsm.c"

int Task() {
    // "/\*([^*]|[\n\r]|(\*+([^*/]|[\n\r])))*\*+/"  regex
    StateMachine* sm = MakeStateMachine();
    char ch = 0;
    int res = 0;
    FILE* file = fopen("../tasks/finite_state_machine/tasks/2/file.txt", "r");
    while (true) {
        fscanf(file, "%c", &ch);
        if (ch == EOF) {
            break;
        }
        res = Step(sm, ch);
        if (res) {
            printf("Finish \n");
            break;
        }
    }
    printf("RESULT COUNT  WORDS %d", sm->count_words);
    DeleteStateMachine(sm);
    return 0;
}