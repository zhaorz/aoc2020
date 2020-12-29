project(sandbox)

file(GLOB SOURCES *.cxx)
add_executable(${PROJECT_NAME} ${SOURCES})
