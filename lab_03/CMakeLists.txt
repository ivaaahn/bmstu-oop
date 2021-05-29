cmake_minimum_required(VERSION 3.19)
project(lab_03)

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME}
        main.cpp
        #        gui
        )


add_subdirectory(./implementation)

target_include_directories(${PROJECT_NAME} PUBLIC
        ./implementation)