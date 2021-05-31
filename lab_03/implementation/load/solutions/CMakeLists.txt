cmake_minimum_required(VERSION 3.19)
project(solutions)


add_executable(${PROJECT_NAME}
        ./camera/camera_load_solution.cpp
        ./camera/camera_load_solution.hpp
        ./model/model_load_solution.cpp
        ./model/model_load_solution.hpp
        )

target_include_directories(${PROJECT_NAME} PUBLIC ../../../implementation)

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)