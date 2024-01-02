#pragma once

#include "shared_header.h"
#include "state.h"

// Создание конечного автомата
StateMachine *CreateStateMachine() {
    StateMachine *sm = (StateMachine *)malloc(sizeof(StateMachine));
    sm->pipeline = MakeStates();
    sm->cur_state = START;
    sm->binary_counter = 0;
    sm->current_length = 0;
    return sm;
}

// Обработка одного шага конечного автомата
void Step(StateMachine *sm, char c) {
    if (sm->cur_state != END) {
        sm->current_char = c;
        sm->cur_state = sm->pipeline[sm->cur_state].action(sm);
    }
}

// Освобождение ресурсов конечного автомата
void DeleteStateMachine(StateMachine *sm) {
    DeleteStates(sm->pipeline);
    free(sm);
}
