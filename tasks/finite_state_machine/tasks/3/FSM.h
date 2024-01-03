#pragma once

#include <stdbool.h>
#include <stdio.h>

#include "realization.h"

int Task() {
    StateMachine* sm = MakeStateMachine();
    char ch = 0;
    int res = 0;
    FILE* file = fopen("../tasks/finite_state_machine/tasks/3/data.txt", "r");
    while (true) {
        fscanf(file, "%c", &ch);
        if (ch == EOF) {
            break;
        }
        res = Step(sm, ch);
        if (res) {
            printf("Reached the end \n");
            break;
        }
    }
    printf("The number of the words in the comments equals %d\n", sm->count_words);
    DeleteStateMachine(sm);
    return 0;
}