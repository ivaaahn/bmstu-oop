cmake_minimum_required(VERSION 3.19)
project(source_loaders)


add_executable(${PROJECT_NAME}
        ./source_loader.hpp
        ./source_loader_creator.hpp
        ./camera/source_camera_loader.hpp
        ./camera/file_camera_loader/file_camera_loader.cpp
        ./camera/file_camera_loader/file_camera_loader.hpp
        ./model/source_model_loader.hpp
        ./model/file_model_loader/file_model_loader.cpp
        ./model/file_model_loader/file_model_loader.hpp
        ./scene/source_scene_loader.hpp
        ./scene/file_scene_loader/file_scene_loader.cpp
        ./camera/file_camera_loader/file_camera_loader.hpp
        )
