#!/bin/bash

# Run from build directory

if [ "$#" -lt 1 ]; then
    echo "Usage: $0 task-name"
    exit 1
fi

TASK_PATH=../$1
CLANG_PATH=../tools/run-clang-format.py

if [ ! -f compile_commands.json ]; then
    echo "Run this script from the build directory"
    exit 1
fi

if [ "$#" -eq 2 ]; then
    TASK_PATH=../../$1
    CLANG_PATH=../../run-clang-format.py
fi

python3 $CLANG_PATH -r $TASK_PATH && clang-tidy $TASK_PATH/*.h