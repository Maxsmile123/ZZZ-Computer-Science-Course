#pragma once

#include "fsm_realization.h"

int Task() {

    // Refular for search octal number: [0-7]
    // Tests:
    // mama mila ram123u 7629 -> 123 762
    FILE* file = fopen("../tasks/finite_state_machine/tasks/40/input_file.txt", "r");
    StateMachine* sm = MakeStateMachine();
    printf("Finite State Machine has started its execution:\n\n");

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
