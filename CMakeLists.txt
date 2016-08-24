cmake_minimum_required(VERSION 3.5)
project(ex1)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wextra -Wall -Wvla -std=c99")

set(SOURCE_FILES main.c)
add_executable(ex1-test ${SOURCE_FILES})

set(SOURCE_FILES CheckParanthesis.c)
add_executable(ex1-CheckParanthesis ${SOURCE_FILES})

set(SOURCE_FILES ChangeBase.c)
add_executable(ex1-ChageBase ${SOURCE_FILES})

