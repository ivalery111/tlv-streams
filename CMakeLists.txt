cmake_minimum_required(VERSION 3.15)

project(stream C)

set(C_STANDARD 11)

include(cmake/CompilerWarnings.cmake)
add_library(project_warnings INTERFACE)
set_project_warnings(project_warnings)

include(cmake/EnableTests.cmake)
include(cmake/BuildType.cmake)

include(cmake/Sanitizers.cmake)
add_library(sanitizers INTERFACE)
set_sanitizers(sanitizers)

add_library(stream)
add_library(net::stream ALIAS stream)

target_sources(stream PRIVATE
    src/stream.c
)

target_include_directories(stream PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(stream
    PRIVATE project_warnings sanitizers
)