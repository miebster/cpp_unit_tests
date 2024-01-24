cmake_minimum_required(VERSION 3.26)
project(testing_test)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp)
add_executable(Solutions_run ${SOURCE_FILES})

include_directories(Solutions)
add_subdirectory(Solutions)

target_link_libraries(Solutions_run Solutions)

add_subdirectory(Tests)
