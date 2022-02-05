cmake_minimum_required(VERSION 3.19)
project(stack_use)

set(CMAKE_CXX_STANDARD 17)

add_executable(stack_use main.cpp search_file_c.h search_file_c.cpp stack_use_c.h stack_use_c.cpp print_result_c.cpp print_result_c.h format.h)