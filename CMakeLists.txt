cmake_minimum_required(VERSION 3.15)
project(http C)

set(CMAKE_C_STANDARD 11)

# Library
add_library(http
    src/http.c
)

target_include_directories(http PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Tests
add_executable(tests
    tests/test_init.c
)

target_link_libraries(tests PRIVATE http)