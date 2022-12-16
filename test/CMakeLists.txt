cmake_minimum_required(VERSION 3.13)

# give a name to the project
projectt(testRatio)

# file to compile and name of the executable
add_executable(testRatio include/Ratio.hpp src/Ratio.cpp)



# include directory
target_include_directories(testRatio PRIVATE "include")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# compilation options
target_compile_features(testRatio PRIVATE cxx_std_11) # use at least c++ 11
target_compile_options(testRatio PRIVATE -Wall -O2)   # specify some compilation flags