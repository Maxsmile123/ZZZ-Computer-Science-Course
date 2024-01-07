#pragma once

#include <stdint.h>

enum State {
    CHECK_FIRST_CHAR,
    CHECK_NUMBER17_69,
    CHECK_NUMBER70_77,
};

struct Machine {
    enum State current_state;
    int32_t data;
};