cmake_minimum_required(VERSION 3.19)
project(commands)

add_executable(${PROJECT_NAME}
        ./command.hpp
        )

add_subdirectory(./camera)
add_subdirectory(./model)
add_subdirectory(./scene)

target_include_directories(${PROJECT_NAME} PUBLIC ../../implementation)


find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)