cmake_minimum_required(VERSION 3.13)

# give a name to the project
project(IMAC_MathsInfoRatio)

# file to compile and name of the executable
add_executable(IMAC_MathsInfoRatio src/main.cpp)

# include directory
target_include_directories(IMAC_MathsInfoRatio PRIVATE "include")

# compilation options
target_compile_features(IMAC_MathsInfoRatio PRIVATE cxx_std_11) # use at least c++ 11
target_compile_options(IMAC_MathsInfoRatio PRIVATE -Wall -O2)   # specify some compilation flags
