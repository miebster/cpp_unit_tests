cmake_minimum_required(VERSION 3.26)
project(cpp_unit_tests)

set(CMAKE_CXX_STANDARD 17)

include(ExternalProject)

include_directories(Solutions)
add_subdirectory(Solutions)



include("${CMAKE_SOURCE_DIR}/vendor/rapidjson.cmake")
include_directories(${RAPIDJSON_INCLUDE_DIR})


add_subdirectory(Problems/p1)
add_subdirectory(Problems/p2)
add_subdirectory(Problems/p3)
