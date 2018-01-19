project(LP_MP-QAP)
cmake_minimum_required(VERSION 2.8.12)

# C++17
add_compile_options(-std=c++17)

# compiler options
add_definitions(-march=native)

include_directories(include)
include_directories(external)
add_subdirectory(external/LP_MP-MRF)
include_directories(external/MCF-SSP)

enable_testing()
#add_subdirectory(test)
add_subdirectory(src)
