cmake_minimum_required(VERSION 3.19)
project(scene_commands)

add_executable(${PROJECT_NAME}
        ./scene_command.hpp
        ./draw/draw_scene.cpp
        ./draw/draw_scene.hpp
        ./load/load_scene.cpp
        ./load/load_scene.hpp
)
