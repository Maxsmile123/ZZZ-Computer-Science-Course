#pragma once

#include "fsm_files.h"

int Task() {
    // regex \b[01]+\b -> \b для того, чтобы искало двоичное полноценно и не читало "10v",
    //+ чтобы считывалось все число, а не первая успешно найденная цифра
    FILE *file = nullptr;
    const char *file_path = "../tasks/finite_state_machine/tasks/31/test31.txt";

    if (!OpenFile(&file, file_path)) {
        return 1;  // Выход из функции, если файл не открылся
    }

    StateMachine *sm = CreateStateMachine();
    ProcessFile(sm, file);
    fclose(file);
    DeleteStateMachine(sm);
    return 0;
}
