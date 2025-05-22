#!/bin/bash

SRC_DIR="$(pwd)/src"
INCLUDE_DIR="$(pwd)/include"
BUILD_DIR="$(pwd)/build"
MAIN_CPP="$(pwd)/main.cpp"

WATCHED_FILES=$(find "$SRC_DIR" -name "*.cpp"; echo "$MAIN_CPP")

RUN_COMMAND=$(cat <<EOF
FILES=\$(find "$SRC_DIR" -name "*.cpp"; echo "$MAIN_CPP")
echo "Compiling..."
g++ -I"$INCLUDE_DIR" -o "$BUILD_DIR/program" \$FILES &&
echo "Running..." &&
"$BUILD_DIR/program"
EOF
)

echo "$WATCHED_FILES" | entr -c bash -c "$RUN_COMMAND"
