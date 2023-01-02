cmake_minimum_required(VERSION 3.13)

# give a name to the project
project(IMAC_LibRatio)

# call the CMakeLists.txt to make the documentation (Doxygen)
find_package(Doxygen OPTIONAL_COMPONENTS QUIET)
if(DOXYGEN_FOUND)
	add_subdirectory(doc)
else()
	message(WARNING "Doxygen not found, skip documentation")
endif()

# Instructions to compile a library (no main() inside)
# default STATIC ??
# SHARED to make a .so instead of a .a
# add_library(ganQ SHARED ${source_files} ${header_files})
add_library(IMAC_LibRatio src/Ratio.cpp)

# include directory
target_include_directories(IMAC_LibRatio PRIVATE "include")

# compilation flags
target_compile_features(IMAC_LibRatio PRIVATE cxx_std_17) # use at least c++ 17
target_compile_options(IMAC_LibRatio PRIVATE -Wall -O2)   # specify some compilation flags