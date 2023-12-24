#pragma once

#include <stdbool.h>
#include <stdlib.h>

typedef enum {
    START = 0,
    CODE,
    ADD,
    COMMIT,
    PUSH,
    MAKEPR,
    TRYGETAPPROVE,
    DEFEND,
    STATECOUNT,  // DO NOT USE LIKE NAME. Нужно для определения кол-ва состояний
    END          // Означает состояние, когда можно завершать программу
} StateName;

typedef struct State State;

typedef struct {
    State* pipeline;  // Массив состояний
    StateName cur_state;
    int step;
    bool is_pr_exists;
} StateMachine;

typedef struct State {
    StateName name;
    StateName (*action)(StateMachine*);  // return next state.
    // Храним функцию, которую состояние должно выполнить.
    // Read: https://metanit.com/cpp/tutorial/4.8.php
} State;