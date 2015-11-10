cmake_minimum_required(VERSION 2.8)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
option(ARGON_BUILD_TESTS "Build test programs" ON)

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

set(cflags "-std=c11 -pedantic -Wall -Wextra -Wshadow -Wpointer-arith -Wcast-qual -Wstrict-prototypes -Wmissing-prototypes -U__STRICT_ANSI__")

include_directories("./include")
include_directories("../lib/memtrack/include")
include_directories("../lib/minunit/include")
add_library(${lib_name} STATIC ${lib_headers} ${lib_sources})
add_definitions(-D_GNU_SOURCE -DUSE_MEMTRACK)
target_link_libraries(${lib_name} memtrack)
set_target_properties(${lib_name} PROPERTIES COMPILE_FLAGS ${cflags})

if(ARGON_BUILD_TESTS)
    add_executable(test_str_insert src/tests/test_str_insert.c)
    target_link_libraries(test_str_insert ${lib_name})
    set_target_properties(test_str_insert PROPERTIES COMPILE_FLAGS ${cflags})
endif()
