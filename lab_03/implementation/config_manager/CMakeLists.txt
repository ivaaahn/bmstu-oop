cmake_minimum_required(VERSION 3.19)
project(config_manager)


add_executable(${PROJECT_NAME}
        ./creator/config_manager_creator.hpp
        ./creator/config_manager_creator.cpp
        ./registration/registration_maker.hpp
        ./registration/registration_maker.cpp
        ./solution/solution.hpp
        ./solution/solution.cpp
        ./config_manager.hpp
        ./config_manager.cpp
        )

target_include_directories(${PROJECT_NAME} PUBLIC ../../implementation)


find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)