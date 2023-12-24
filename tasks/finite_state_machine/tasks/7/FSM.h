#pragma once

#include "fsm_realization.h"

int Task(void) {
    const char* in_file_name = "../tasks/finite_state_machine/tasks/7/in.txt";
    const char* out_file_name = "../tasks/finite_state_machine/tasks/7/out.txt";
    const int32_t shift = 3;
    StateMachine* sm = MakeStateMachine(in_file_name, out_file_name, shift);
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