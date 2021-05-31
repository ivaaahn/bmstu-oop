cmake_minimum_required(VERSION 3.19)
project(drawer)

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME}
        drawer.hpp
        qt/factory/qt_drawer_factory.cpp
        qt/factory/qt_drawer_factory.hpp
        qt/qt_drawer.cpp
        qt/qt_drawer.hpp
        )

target_include_directories(${PROJECT_NAME} PUBLIC ../../implementation)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})
find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)