#pragma once

#include <stdio.h>
#include <stdlib.h>

#include "fsm_realization.h"

int Task() {
    FILE* file = fopen("../tasks/finite_state_machine/tasks/16/text.txt", "r");
    StateMachine* sm = MakeStateMachine();
    printf("Start!\n\n");

    int result = 1;
    while (result) {
        result = Step(sm, (char)fgetc(file));
    }

    DeleteStateMachine(sm);
    fclose(file);
    return 0;
}