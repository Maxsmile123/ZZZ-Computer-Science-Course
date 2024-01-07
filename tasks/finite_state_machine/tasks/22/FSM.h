#pragma once

#include <stdio.h>

#include "fsm_structs.h"
#include "fsm_transition.h"

int Task() {
    FILE *file = fopen("../tasks/finite_state_machine/tasks/22/test.txt", "r");
    Machine my_machine;
    my_machine.current_state = SCAN;
    Transition(&my_machine, file);
    return 0;
}
