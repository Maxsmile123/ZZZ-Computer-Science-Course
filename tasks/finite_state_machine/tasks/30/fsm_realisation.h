#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "shared_header.h"
#include "states.h"

// Function to create a new state machine
StateMachine* MakeStateMachine() {
    StateMachine* sm = (StateMachine*)malloc(sizeof(StateMachine));
    sm->pipeline = MakeStates();
    sm->current_state = FIND_NUMBER;
    sm->current_number = 0;
    return sm;
}

// Function to perform state transitions
int Step(StateMachine* sm, char c) {
    StateName next = sm->pipeline[(int)sm->current_state].action(sm);
    sm->current_char = c;
    if (next == END) {
        return 1;
    }
    sm->current_state = next;
    return 0;
}

// Function to delete the state machine
void DeleteStateMachine(StateMachine* sm) {
    DeleteStates(sm->pipeline);
    free(sm);
}
