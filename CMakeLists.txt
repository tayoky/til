cmake_minimum_required(VERSION 3.0)

project(til)

#find all sources
file(GLOB_RECURSE lib_src "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c")
file(GLOB_RECURSE app_src "${CMAKE_CURRENT_SOURCE_DIR}/app/*.c")

if (WIN32)
set( CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS True )
endif()

add_library(tili SHARED ${lib_src})
target_include_directories(tili PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(til ${app_src})
target_link_directories(til PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(til PRIVATE tili)
target_include_directories(til PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)