#pragma once

#include <stdbool.h>
#include <stdio.h>

#include "fsm_realization.h"

int Task() {
    FILE* file = fopen("../tasks/finite_state_machine/tasks/10/text.txt", "r");
    StateMachine* sm = MakeStateMachine();
    int res = 0;
    while (true) {
        res = Step(sm, (char)fgetc(file));
        if (res) {
            printf("Program has finished its execution\n");
            break;
        }
    }
    fclose(file);
    DeleteStateMachine(sm);
    return 0;
}