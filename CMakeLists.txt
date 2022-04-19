cmake_minimum_required(VERSION 3.00.0 FATAL_ERROR)
project(Uebungsblatt2
        LANGUAGES CXX
        VERSION 0.0.1
        DESCRIPTION "Uebungsblatt 2")

set(CMAKE_CXX_STANDARD 17)
add_executable(${PROJECT_NAME} src/main.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)