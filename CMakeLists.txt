cmake_minimum_required(VERSION 3.26)
project(testing_test)

set(CMAKE_CXX_STANDARD 17)
include(ExternalProject)

set(SOURCE_FILES main.cpp)
add_executable(Solutions_run ${SOURCE_FILES})

include_directories(Solutions)
add_subdirectory(Solutions)
target_link_libraries(Solutions_run Solutions)

include("${CMAKE_SOURCE_DIR}/vendor/rapidjson.cmake")
include_directories(${RAPIDJSON_INCLUDE_DIR})

add_subdirectory(Problems)
