cmake_minimum_required(VERSION 3.19)
project(visitor)

add_executable(${PROJECT_NAME}
        ./visitor.hpp
        draw_visitor/draw_visitor.cpp
        draw_visitor/draw_visitor.hpp
        )

set_target_properties(visitor PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(${PROJECT_NAME} PUBLIC ../../implementation)

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)