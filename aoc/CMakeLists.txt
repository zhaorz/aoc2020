project(aoc)

file(GLOB problems *.cxx)

foreach(problem ${problems})
  get_filename_component(name ${problem} NAME_WE)

  add_executable(${name} ${problem})
  target_link_libraries(${name} PRIVATE util)
endforeach()
