cmake_minimum_required(VERSION 3.00.0 FATAL_ERROR)
project(Uebungsblatt2
        LANGUAGES CXX
        VERSION 0.0.1
        DESCRIPTION "Uebungsblatt 2")

set(CMAKE_CXX_STANDARD 11)
add_executable(${PROJECT_NAME} src/main.cpp include/baustein.hpp include/halbaddierer.hpp include/oder2.hpp include/schaltung.hpp include/schnittstelle.hpp include/und2.hpp include/und2.hpp include/volladdierer.hpp include/xor2.hpp)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)