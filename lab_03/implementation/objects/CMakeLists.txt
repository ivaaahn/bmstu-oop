cmake_minimum_required(VERSION 3.19)
project(objects)

add_executable(${PROJECT_NAME}
        ./object.hpp
        ./camera/camera.cpp
        ./camera/camera.hpp
        ./composite/composite.cpp
        ./composite/composite.hpp
        ./model/model.cpp
        ./model/model.hpp
        ./model/model_details/model_details.cpp
        ./model/model_details/model_details.hpp
)

target_include_directories(${PROJECT_NAME} PUBLIC ../../implementation)

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
