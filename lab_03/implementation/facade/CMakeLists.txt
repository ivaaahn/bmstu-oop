cmake_minimum_required(VERSION 3.19)
project(facade)


add_executable(${PROJECT_NAME}
        ./facade.cpp
        ./facade.hpp
        )
find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)