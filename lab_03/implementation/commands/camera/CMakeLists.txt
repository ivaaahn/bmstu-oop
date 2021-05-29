cmake_minimum_required(VERSION 3.19)
project(camera_commands)

add_executable(${PROJECT_NAME}
        camera_command.hpp
        ./add/add_camera.cpp
        ./add/add_camera.hpp
        ./count/count_cameras.cpp
        ./count/count_cameras.hpp
        ./move/move_camera.cpp
        ./move/move_camera.hpp
        ./remove/remove_camera.cpp
        ./remove/remove_camera.hpp
        ./set/set_camera.cpp
        ./set/set_camera.hpp
)
