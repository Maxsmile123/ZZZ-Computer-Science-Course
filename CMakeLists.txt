cmake_minimum_required(VERSION 3.8)

project(ZZZ-Course)

set(CMAKE_CXX_STANDARD             20)
set(CMAKE_C_STANDARD             11)
set(CMAKE_MODULE_PATH              "${CMAKE_SOURCE_DIR}/cmake")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
set(CMAKE_EXPORT_COMPILE_COMMANDS  ON)

include_directories(contrib/catch)

include(Cmake/TestSolution.cmake)
include(Cmake/BuildFlags.cmake)

add_subdirectory(tasks)
include(Cmake/FindCatch.cmake)