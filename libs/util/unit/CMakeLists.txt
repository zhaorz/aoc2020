file(GLOB SOURCES *.cxx)

add_catch_tests(test_util ${SOURCES})
target_link_libraries(test_util PUBLIC util)
