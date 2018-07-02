project(LP_MP-QAP)
cmake_minimum_required(VERSION 2.8.12)

# C++17
add_compile_options(-std=c++17)

# compiler options
add_definitions(-march=native)

add_subdirectory(external/LP_MP-MRF)
add_subdirectory(external/MCF-SSP)

add_library(LP_MP-QAP INTERFACE)
target_include_directories(LP_MP-QAP INTERFACE include)
target_include_directories(LP_MP-QAP INTERFACE external)
target_include_directories(LP_MP-QAP INTERFACE external/MCF-SSP)
target_link_libraries(LP_MP-QAP INTERFACE LP_MP-MRF)
target_link_libraries(LP_MP-QAP INTERFACE LP_MP)
target_link_libraries(LP_MP-QAP INTERFACE DD_ILP)
#target_link_libraries(LP_MP-QAP INTERFACE ../external/LP_MP-MRF/external/LP_MP/external/DD_ILP/external/lingeling/liblgl.a)


enable_testing()
#add_subdirectory(test)
add_subdirectory(src)
