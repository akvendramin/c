#!/bin/bash

SCRIPT_DIR=$(dirname "$(realpath "$0")")

clear

pushd "$SCRIPT_DIR"

rm -rf output
mkdir output

clang -Wall -g -c platform.c -o output/platform.o
ar rcs output/platform.a output/platform.o

clang -Wall -g -c string.c -o output/string.o
ar rcs output/string.a output/string.o

clang -Wall -g -I. test/platform.c output/platform.a output/string.a -o output/platform.out

clang -Wall -g -I. test/string.c output/string.a -o output/string.out

popd
