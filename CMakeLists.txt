cmake_minimum_required(VERSION 2.8)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

set(lib_name "argon-base")

set(lib_headers
    include/base/pjw.h
    include/base/vector.h
    include/base/stack.h
    include/base/list.h
    include/base/math_ext.h
    include/base/intersection.h
    include/base/str_replace.h
    include/base/str_insert.h
    include/base/memory_blocks_pool.h
    include/base/objects_pool.h
)

set(lib_sources
    src/base/pjw.c
    src/base/vector.c
    src/base/stack.c
    src/base/list.c
    src/base/math_ext.c
    src/base/intersection.c
    src/base/str_replace.c
    src/base/str_insert.c
    src/base/memory_blocks_pool.c
    src/base/objects_pool.c
)

if(WIN32)
list(APPEND lib_sources src/base/memmem.c)
endif()

include_directories("./include")
include_directories("../lib/memtrack/include")
add_library(${lib_name} STATIC ${lib_headers} ${lib_sources})
add_definitions(-D_GNU_SOURCE -DUSE_MEMTRACK)

target_link_libraries(${lib_name} memtrack)
set_target_properties(${lib_name} PROPERTIES COMPILE_FLAGS "-std=c11 -pedantic -Wall -Wextra -Wshadow -Wpointer-arith -Wcast-qual -Wstrict-prototypes -Wmissing-prototypes -U__STRICT_ANSI__")
