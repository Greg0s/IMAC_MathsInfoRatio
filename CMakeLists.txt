cmake_minimum_required(VERSION 3.13)

# give a name to the project
project(CMakeGeneral)

# (optional) add a "output" directory in the project binary directory
file(MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/output)

# (optional) put the binary files in this directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

# add libRatio
message(STATUS "libRatio cmake part ..." )
add_subdirectory(libRatio)

# add testRatio
message(STATUS "testRatio cmake part ..." )
add_subdirectory(test)