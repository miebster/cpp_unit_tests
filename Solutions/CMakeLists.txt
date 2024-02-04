project(Solutions)

set(HEADER_FILES
        solution_1.h
        solution_2.h
        solution_3.h
)

set(SOURCE_FILES
        solution_1.cpp
        solution_2.cpp
        solution_3.cpp
)

add_library(Solutions STATIC ${SOURCE_FILES} ${HEADER_FILES})