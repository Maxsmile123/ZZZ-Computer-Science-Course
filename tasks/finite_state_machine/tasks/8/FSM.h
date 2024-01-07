#pragma once

#include "fsm_realization.h"

int Task(void) {
    const char* in_file_name = "../tasks/finite_state_machine/tasks/8/in.txt";
    const char* out_file_name = "../tasks/finite_state_machine/tasks/8/out.txt";
    StateMachine* sm = MakeStateMachine(in_file_name, out_file_name);
    int result = 0;
    while (true) {
        result = Step(sm);
        if (result) {
            break;
        }
    }
    DeleteStateMachine(sm);
    return 0;
}