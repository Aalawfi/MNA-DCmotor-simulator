cmake_minimum_required(VERSION 3.10)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
set(CMAKE_CXX_STANDARD 20)

project(Simulator)

enable_testing()

add_subdirectory(Math)
add_subdirectory(Common)
add_subdirectory(Signal)
add_subdirectory(Mna)
add_subdirectory(Hybrid)
add_subdirectory(Simulator)
add_subdirectory(UnitTests)
