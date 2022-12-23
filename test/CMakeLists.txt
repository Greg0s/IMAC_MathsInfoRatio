cmake_minimum_required(VERSION 3.13)

# give a name to the project
project(testRatio)


add_executable(testRatio src/test.cpp ../libRatio/src/Ratio.cpp)

# compilation flags
target_compile_features(testRatio PRIVATE cxx_std_17) # use at least c++ 11
target_compile_options(testRatio PRIVATE -Wall -O2)   # specify some compilation flags