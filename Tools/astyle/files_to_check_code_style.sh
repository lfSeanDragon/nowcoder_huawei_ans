#!/usr/bin/env bash
set -eu

PATTERN="-e ."

if [ $# -gt 0 ]; then
    PATTERN="$1"
fi

exec find C Cpp \
    -type f \( -name "*.c" -o -name "*.cc" -o -name "*.h" \) | grep $PATTERN
