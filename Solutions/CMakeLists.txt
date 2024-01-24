project(Solutions)

set(HEADER_FILES
        solution_1.h
        solution_2.h
)

set(SOURCE_FILES
        solution_1.cpp
        solution_2.cpp
)

add_library(Solutions STATIC ${SOURCE_FILES} ${HEADER_FILES})