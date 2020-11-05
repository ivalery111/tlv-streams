cmake_minimum_required(VERSION 3.15)

project(stream C)

set(C_STANDARD 11)

include(cmake/CompilerFlags.cmake)
include(cmake/EnableTests.cmake)
include(cmake/BuildType.cmake)

add_library(stream)
add_library(net::stream ALIAS stream)

target_sources(stream PRIVATE
    src/stream.c
)

target_include_directories(stream PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_compile_options(stream PUBLIC ${COMPILER_FLAGS})