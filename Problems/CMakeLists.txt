add_executable(problems_run p1/problem_1.cpp)
target_link_libraries(problems_run Solutions)

add_dependencies(problems_run rapidjson)