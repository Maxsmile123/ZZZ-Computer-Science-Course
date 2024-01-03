#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "fsm_realization.h"

int Task() {
    FILE* file = fopen("../tasks/finite_state_machine/tasks/26/input.txt", "r");
    StateMachine* sm = MakeStateMachine();

    bool is_result = true;
    while (is_result) {
        is_result = Step(sm, (char)fgetc(file));
    }
    DeleteStateMachine(sm);
    fclose(file);
    return 0;
}