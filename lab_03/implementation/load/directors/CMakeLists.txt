cmake_minimum_required(VERSION 3.19)
project(controllers)


add_executable(${PROJECT_NAME}
        load_director.hpp
        camera/camera_director.cpp
        camera/camera_director.hpp
        model/model_director.cpp
        model/model_director.hpp
        ../../scene/director/scene_director.cpp
        ../../scene/director/scene_director.hpp
        )

target_include_directories(${PROJECT_NAME} PUBLIC ../../../implementation)

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)