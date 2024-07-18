#!/bin/sh
SOURCE_FILES="main.cpp BST.cpp"
PROGRAM_NAME=MockDraft

# This is a script because the build is easy
# It should probably be a Makefile, or a CMakeLists.txt file to work on Windows, Linux, and Mac

# First, go to the 'src' directory
cd $(dirname $0)/src

# Make the 'output' directory if it's not already there
if [[ ! -d ../out ]] ; then
  mkdir ../out
fi

# Flags to the compiler for a good set of warnings:
# Could add '-Werror' to the list to make the warnings be errors
WARNING_FLAGS="-pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wmissing-declarations -Wmissing-include-dirs -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-overflow=5 -Wswitch-default -Wundef -Wno-unused"
# 'sanitizers' are good for checking for problems in your code. They slow things down, but tend to be better than valgrind
RUNTIME_CHECK_FLAGS="-fsanitize=address"
# Generate debug info, and don't optimize (makes debugging easier)
OPTIMIZATION_FLAGS="-g -O0"
# Specify language-standard/configuration stuff:
LANG_CONFIG_FLAGS="-std=c++17"
# Compile the code with debug info
c++ ${WARNING_FLAGS} ${OPTIMIZATION_FLAGS} ${RUNTIME_CHECK_FLAGS} ${LANG_CONFIG_FLAGS} ${SOURCE_FILES} -o ../out/${PROGRAM_NAME}
