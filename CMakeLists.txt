cmake_minimum_required(VERSION 3.00.0 FATAL_ERROR)
project(Uebungsblatt2
        LANGUAGES CXX
        VERSION 0.0.1
        DESCRIPTION "Uebungsblatt 2")

#making the compiler more strict with error handling
if(MSVC)
        add_compile_options(/W3 /WX /permissive)
else()
        add_compile_options(-Wextra -Wall -Werror -pedantic)
endif(MSVC)

set(CMAKE_CXX_STANDARD 11)
add_executable(${PROJECT_NAME} src/main.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)