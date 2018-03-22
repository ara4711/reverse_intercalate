cmake_minimum_required( VERSION 3.9.4 )

#
# the library
#

add_library(task1
    task1.cpp
	task1.hpp
)
target_link_libraries(task1 pg_list ranges)

#
# smoketest app
#
add_executable(app
	app.cpp
)
target_link_libraries(app task1 pg_list ranges) 

#
# the tests
#

add_executable(testsTask1 tests.cpp)
target_link_libraries(testsTask1 task1 gtest_main)
add_test(NAME testsTask1 COMMAND testsTask1)
