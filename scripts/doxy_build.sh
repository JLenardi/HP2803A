#!/bin/bash

# Build Doxygen HTML docs for A64 and AVR targets.
# May be run from any subdirectory within the repo:
#     bash scripts/doxy_build.sh
# or
#     ./scripts/doxy_build.sh
# Requires doxygen installed and script run inside a Git working tree.
# Outputs to:
#     docs/a64/html/
#     docs/avr/html/

REPO_ROOT="$(git rev-parse --show-toplevel)"
cd "$REPO_ROOT"

doxygen docs/doxygen/Doxyfile_a64
doxygen docs/doxygen/Doxyfile_avr

