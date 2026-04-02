#!/bin/bash

stty -icanon -echo min 0 time 0

trap 'stty sane' EXIT

./build/tests/hardware/a64/test_stdin

