cmake_minimum_required(VERSION 2.8)
project(Kstd)

set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")
include_directories(${PROJECT_SOURCE_DIR}/include)
set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES src/klist.c src/kmap.c include/kmap.h include/klist.h include/klinkedlist.h include/kstack.h include/kqueue.h include/kset.h src/kset.c src/klinkedlist.c src/kqueue.c src/kstack.c)
add_library(Kstd SHARED ${SOURCE_FILES})