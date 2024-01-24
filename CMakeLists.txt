cmake_minimum_required(VERSION 3.26)
project(cpp_unit_tests)

set(CMAKE_CXX_STANDARD 17)
include(ExternalProject)

set(SOURCE_FILES main.cpp)
add_executable(solutions_run ${SOURCE_FILES})

include_directories(Solutions)
add_subdirectory(Solutions)
target_link_libraries(solutions_run Solutions)

include("${CMAKE_SOURCE_DIR}/vendor/rapidjson.cmake")
include_directories(${RAPIDJSON_INCLUDE_DIR})

add_subdirectory(Problems)
