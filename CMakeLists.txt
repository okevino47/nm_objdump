cmake_minimum_required(VERSION 3.9)
project(PSU_2017_nmobjdump)

set(CMAKE_CXX_STANDARD 14)

add_executable(PSU_2017_nmobjdump nm tests common objdump/src/main.c
        objdump/includes/objdump.h objdump/src/objdump.c
        common/includes/common.h common/src/check.c common/src/assignation.c objdump/src/display.c)
