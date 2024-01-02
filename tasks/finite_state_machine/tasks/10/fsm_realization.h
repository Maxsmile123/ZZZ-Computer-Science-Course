#pragma once

#include <stdlib.h>

#include "shared_header.h"
#include "state.h"

StateMachine* MakeStateMachine() {
    StateMachine* sm = (StateMachine*)malloc(sizeof(StateMachine));
    sm->pipeline = MakeStates();
    sm->cur_state = START;
    sm->file_out = fopen("../tasks/finite_state_machine/tasks/10/file_out.txt", "w");
    return sm;
}

int Step(StateMachine* sm, char c) {
    StateName next = sm->pipeline[(int)sm->cur_state].action(sm, c);
    if (next == END) {
        return 1;
    }
    sm->cur_state = next;
    return 0;
}

void DeleteStateMachine(StateMachine* sm) {
    DeleteStates(sm->pipeline);
    free(sm);
}