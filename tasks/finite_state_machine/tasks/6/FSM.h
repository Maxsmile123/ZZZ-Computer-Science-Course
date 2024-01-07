#pragma once

#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fsm_structs.h"
#include "fsm_transition.h"

int Task() {
    // regex_t regex;
    // int value = regcomp(&regex, "^[a-zA-Z_][a-zA-Z0-9_]*$", 0);
    // if (value == 0) {
    //     printf("Process successful");
    // } else {
    //     printf("Process failed");
    // }

    FILE* file = fopen("../tasks/finite_state_machine/tasks/6/test.txt", "r");
    Machine my_machine;
    my_machine.current_state = SCAN;
    Transition(&my_machine, file);
    return 0;
}