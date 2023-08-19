project(ZZZ-Course)

cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD             20)
set(CMAKE_MODULE_PATH              "${CMAKE_SOURCE_DIR}/cmake")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
set(CMAKE_EXPORT_COMPILE_COMMANDS  ON)


find_package(Catch REQUIRED)

include(cmake/TestSolution.cmake)
include(cmake/BuildFlags.cmake)

add_subdirectory(tasks)