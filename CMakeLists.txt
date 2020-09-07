cmake_minimum_required(VERSION 3.1...3.15)

project(gula VERSION 1.0 LANGUAGES C)

include(ExternalProject)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

set(CMAKE_CXX_FLAGS " -std=c++14 -funroll-loops -O3 -march=native")

MESSAGE( [Main] " PROJECT_NAME = ${PROJECT_NAME}")
MESSAGE( [Main] " CMAKE_BINARY_DIR = ${CMAKE_BINARY_DIR}")
MESSAGE( [Main] " CMAKE_SOURCE_DIR = ${CMAKE_SOURCE_DIR}")
MESSAGE( [Main] " PROJECT_SOURCE_DIR = ${PROJECT_SOURCE_DIR}")
MESSAGE( [Main] " CMAKE_CURRENT_BINARY_DIR = ${CMAKE_CURRENT_BINARY_DIR}")

include_directories(${PROJECT_SOURCE_DIR}/thirdparty/jsmn)

set(HEADER_FILES
    src/type.h
    src/ioutil.h
    src/args_parser.h
)

set(SOURCE_FILES 
    src/ioutil.c
    src/args_parser.c
)

# Add definition for library
add_library(core STATIC ${SOURCE_FILES} ${HEADER_FILES})

add_executable(${PROJECT_NAME} src/main.c)
target_link_libraries(${PROJECT_NAME} core)

