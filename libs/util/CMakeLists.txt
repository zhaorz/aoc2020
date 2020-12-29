file(GLOB SOURCES src/*.cxx)

add_library(util STATIC ${SOURCES})
target_include_directories(util PUBLIC include)

add_subdirectory(unit)
