cmake_minimum_required(VERSION 3.10)

project(SheidTheCrypt)

if(MSVC)
    add_compile_options(/utf-8)
    add_compile_definitions(_UTF8_SOURCE)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SRC_FILES
"${PROJECT_SOURCE_DIR}/src/*.cpp")

add_executable(${CMAKE_PROJECT_NAME} ${SRC_FILES})

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include)

target_compile_features(${CMAKE_PROJECT_NAME} PRIVATE cxx_std_17)