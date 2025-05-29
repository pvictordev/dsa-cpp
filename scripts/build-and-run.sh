#!/bin/bash

STR_DIR="$(pwd)/structures"
# SRC_DIR="$(pwd)/src"
INCLUDE_DIR="$(pwd)/include"
BUILD_DIR="$(pwd)/build"
MAIN_CPP="$(pwd)/main.cpp"

WATCHED_FILES=$(find "$STR_DIR" -name "*.cpp"; echo "$MAIN_CPP")

RUN_COMMAND=$(cat <<EOF
FILES=\$(find "$STR_DIR" -name "*.cpp"; echo "$MAIN_CPP")
g++ -I"$INCLUDE_DIR" -o "$BUILD_DIR/program" \$FILES &&
"$BUILD_DIR/program"
EOF
)

echo "$WATCHED_FILES" | entr -c bash -c "$RUN_COMMAND"
