cmake_minimum_required(VERSION 3.19)
project(builders)


add_executable(${PROJECT_NAME}
        ./camera/camera_build_director.hpp
        ./camera/camera_build_director.cpp
        ./camera/camera_builder.cpp
        ./camera/camera_builder.hpp
        ./model/model_build_director.cpp
        ./model/model_build_director.hpp
        ./model/model_builder.cpp
        ./model/model_builder.hpp
        ./scene/scene_build_director.cpp
        ./scene/scene_build_director.hpp
        ./scene/scene_builder.hpp
        ./scene/scene_builder.cpp
        )

target_include_directories(${PROJECT_NAME} PUBLIC ../../../implementation)

