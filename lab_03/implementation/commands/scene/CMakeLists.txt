cmake_minimum_required(VERSION 3.19)
project(scene_commands)

add_executable(${PROJECT_NAME}
        ./scene_command.hpp
        render/render_scene.cpp
        render/render_scene.hpp
        ./load/load_scene.cpp
        ./load/load_scene.hpp
)

target_include_directories(${PROJECT_NAME} PUBLIC ../../../implementation)

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)