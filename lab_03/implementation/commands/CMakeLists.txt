cmake_minimum_required(VERSION 3.19)
project(commands)

add_executable(${PROJECT_NAME}
        ./command.hpp
        )

add_subdirectory(./camera)
add_subdirectory(./model)
add_subdirectory(./scene)
