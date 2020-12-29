# ------------------------------------------------------------------------------
# CMake configuration
# ------------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.12)

project(aoc2020)

# Reconfigure output of targets
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Produce a compile_commands.json file
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ------------------------------------------------------------------------------
# C++ and compiler flags
# ------------------------------------------------------------------------------

set(CMAKE_CXX_STANDARD_REQUIRED ON) # No compiler fallback
set(CMAKE_CXX_EXTENSIONS OFF)       # No compiler extensions

add_definitions(-Wall -Werror -Wextra -Wpedantic)

if (CMAKE_BUILD_TYPE MATCHES "Debug")
elseif(CMAKE_BUILD_TYPE MATCHES "Release")
endif()

# ------------------------------------------------------------------------------
# Status printout
# ------------------------------------------------------------------------------

message(STATUS "Build type        : ${CMAKE_BUILD_TYPE}")
message(STATUS "C compiler        : ${CMAKE_C_COMPILER}")
message(STATUS "C++ compiler      : ${CMAKE_CXX_COMPILER}")
message(STATUS "C++ standard      : ${CMAKE_CXX_STANDARD}")
message(STATUS "C++ Debug flags   : ${CMAKE_CXX_FLAGS_DEBUG}")
message(STATUS "C++ Release flags : ${CMAKE_CXX_FLAGS_RELEASE}")

# ------------------------------------------------------------------------------
# Projects
# ------------------------------------------------------------------------------

add_subdirectory(libs)
add_subdirectory(sandbox)

add_subdirectory(aoc)
