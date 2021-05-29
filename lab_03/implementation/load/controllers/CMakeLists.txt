cmake_minimum_required(VERSION 3.19)
project(controllers)


add_executable(${PROJECT_NAME}
        ./load_controller.hpp
        ./camera/camera_load_controller.cpp
        ./camera/camera_load_controller.hpp
        ./model/model_load_controller.cpp
        ./model/model_load_controller.hpp
        ./scene/scene_load_controller.cpp
        ./scene/scene_load_controller.hpp
        )
