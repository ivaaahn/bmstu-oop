cmake_minimum_required(VERSION 3.19)
project(solutions)


add_executable(${PROJECT_NAME}
        ./camera/camera_load_solution.cpp
        ./camera/camera_load_solution.hpp
        ./model/model_load_solution.cpp
        ./model/model_load_solution.hpp
        ./scene/scene_load_solution.cpp
        ./scene/scene_load_solution.hpp
        )
