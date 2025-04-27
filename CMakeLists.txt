cmake_minimum_required(VERSION 3.10.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(
    foo_project
    VERSION 0.1
    DESCRIPTION "foo program"
    LANGUAGES C CXX
)

add_executable(foo)

target_sources(
    foo
    PRIVATE
    ${PROJECT_SOURCE_DIR}/src/main.c
    ${PROJECT_SOURCE_DIR}/src/foo.c
)

target_include_directories(
    foo
    PRIVATE
    ${PROJECT_SOURCE_DIR}/src
)
