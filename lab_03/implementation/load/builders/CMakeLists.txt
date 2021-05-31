cmake_minimum_required(VERSION 3.19)
project(builders)


add_executable(${PROJECT_NAME}
        ./camera/camera_builder.cpp
        ./camera/camera_builder.hpp
        ./model/model_builder.cpp
        ./model/model_builder.hpp
        scene/scene_builder.hpp
        scene/scene_builder.cpp
        )

target_include_directories(${PROJECT_NAME} PUBLIC ../../../implementation)

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)