cmake_minimum_required(VERSION 3.19)
project(model_commands)

add_executable(${PROJECT_NAME}
        model_command.hpp
        ./add/add_model.cpp
        ./add/add_model.hpp
        ./count/count_models.cpp
        ./count/count_models.hpp
        ./load/load_model.cpp
        ./load/load_model.hpp
        ./move/move_model.cpp
        ./move/move_model.hpp
        ./remove/remove_model.cpp
        ./remove/remove_model.hpp
        ./rotate/rotate_model.cpp
        ./rotate/rotate_model.hpp
        ./scale/scale_model.cpp
        ./scale/scale_model.hpp
        ./transform/transform_model.cpp
        ./transform/transform_model.hpp
)

target_include_directories(${PROJECT_NAME} PUBLIC ../../../implementation)

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)