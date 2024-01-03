#pragma once

#include "fsm_realization.h"

int Task() {
    /*
    Regular expression for search: (-?\d*)°C
    Another for floating point numbers: (-?\d+\.?\d*)°C

    EXAMPLE:
    1.  Weekly weather forecast in Moscow:
    2.  =================================
    3.  Monday: -10°C
    4.  Tuesday: -2°C
    5.  Wednesday: 6°C
    6.  Thursday: 1°C
    7.  Friday: 0°C
    8.  Saturday: -3°C
    9.  Sunday: -12°C
    10. =================================
    lines 3-9 will be suitable
    */

    // Enter the file path here:
    FILE* file = fopen("../tasks/finite_state_machine/tasks/18/input_file.txt", "r");
    StateMachine* sm = MakeStateMachine();

    int result = 0;
    while (true) {
        result = Step(sm, (char)fgetc(file));
        if (result) {
            printf("\nFSM has completed its execution\n");
            break;
        }
    }

    DeleteStateMachine(sm);
    fclose(file);
    return 0;
}