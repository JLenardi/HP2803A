#!/bin/sh

gcc -std=c99 -Wall -Wextra -Wconversion -Werror -pedantic \
    -I app -I services -I system -I hardware -I hardware/a64 -I core -I utils \
    hardware/a64/stdin.c \
    tests/hardware/a64/test_stdin.c \
    -o build/tests/hardware/a64/test_stdin \
    -lm
