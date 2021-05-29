cmake_minimum_required(VERSION 3.19)
project(managers)

add_executable(${PROJECT_NAME}
        ./manager.hpp
        draw/draw_manager.cpp
        draw/draw_manager.hpp
        load/load_manager.cpp
        load/load_manager.hpp
        creator/base_manager_creator.hpp
        creator/base_manager_creator.cpp
        creator/manager_creator.hpp
        scene/scene_manager.cpp
        scene/scene_manager.hpp
        transform/transform_manager.cpp
        transform/transform_manager.hpp
)

target_include_directories(${PROJECT_NAME} PUBLIC ../../implementation)

