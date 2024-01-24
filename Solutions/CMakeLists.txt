project(Solutions)

set(HEADER_FILES
        solution_1.h
)

set(SOURCE_FILES
        solution_1.cpp
)

add_library(Solutions STATIC ${SOURCE_FILES} ${HEADER_FILES})