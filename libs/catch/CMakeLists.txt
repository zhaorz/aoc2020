project(catch)

add_library(catch-main STATIC src/main.cxx)
target_include_directories(catch-main PUBLIC include)

# add_catch_tests(<target> sources[...])
function(add_catch_tests name)
  if (NOT name MATCHES "test_")
    message(FATAL_ERROR "Unit test target '${name}' must begin with test_")
  endif()

  cmake_parse_arguments(Catch "" "" "" ${ARGN})

  set(SOURCES ${Catch_UNPARSED_ARGUMENTS})

  add_executable(${name} ${SOURCES})
  target_link_libraries(${name} PUBLIC catch-main)
endfunction()
