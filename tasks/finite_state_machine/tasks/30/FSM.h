#pragma once

#include "fsm_realisation.h"

int Task() {
    /*
    Regular expression for decimal numbers: ^[0-9]+$
    Test: Only one of the numbers 99 and 23 will be in the output. -> 23
    */
    FILE* file = fopen("../tasks/finite_state_machine/tasks/30/input.txt", "r");
    StateMachine* sm = MakeStateMachine();
    printf("START\n");
    int k = 0;
    while (true) {
        k = Step(sm, (char)fgetc(file));
        if (k) {
            printf("\nEND\n");
            break;
        }
    }
    fclose(file);
    DeleteStateMachine(sm);
    return 0;
}
