cmake_minimum_required(VERSION 3.19)
project(scene)

add_executable(${PROJECT_NAME}
        scene.cpp
        scene.hpp
        loaders/scene_loader.hpp
        loaders/scene_loader_creator.hpp
        loaders/file/file_scene_loader.cpp
        loaders/file/file_scene_loader.hpp
        loaders/file/file_scene_loader_creator.hpp
        solution/scene_load_solution.hpp
        solution/scene_load_solution.cpp
        )

target_include_directories(${PROJECT_NAME} PUBLIC ../../implementation)


find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)