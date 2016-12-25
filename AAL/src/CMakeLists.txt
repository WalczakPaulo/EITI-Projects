cmake_minimum_required(VERSION 3.6)

set(SOURCE_FILES QuickSorter.cpp QuickSorter.h Menu.cpp Menu.h Bruteforce.cpp Bruteforce.h Combinations.cpp Combinations.h OptimalAlgorithm.cpp OptimalAlgorithm.h)

add_library(src ${SOURCE_FILES})

