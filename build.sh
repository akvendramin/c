#!/bin/bash

SCRIPT_DIR=$(dirname "$(realpath "$0")")

clear

pushd "$SCRIPT_DIR"

rm -rf output
mkdir output

clang -Wall -g -c platform.c -o output/platform.o
ar rcs output/platform.a output/platform.o

clang -Wall -g -I. test/platform.c output/platform.a -o output/platform.out

popd
