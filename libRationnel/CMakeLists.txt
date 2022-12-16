cmake_minimum_required(VERSION 3.13)

# give a name to the project
project(IMAC_MathsInfoRatio)

# file to compile and name of the executable
add_executable(IMAC_MathsInfoRatio include/Ratio.hpp src/Ratio.cpp)
#file(GLOB_RECURSE source_files src/*.cpp)
#file(GLOB_RECURSE header_files include/*.hpp)

# Instructions to compile a library (no main() inside)
#add_library(Rationnal ${source_files} ${header_files})

# include directory
target_include_directories(IMAC_MathsInfoRatio PRIVATE "include")

#set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# compilation options
target_compile_features(IMAC_MathsInfoRatio PRIVATE cxx_std_11) # use at least c++ 11
target_compile_options(IMAC_MathsInfoRatio PRIVATE -Wall -O2)   # specify some compilation flags
