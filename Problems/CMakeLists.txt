add_executable(tests_run p1/problem_1.cpp)
target_link_libraries(tests_run Solutions)

add_dependencies(tests_run rapidjson)