#!/bin/bash

stty -icanon -echo min 0 time 0

trap 'stty sane' EXIT

./build/a64/hp2803a

