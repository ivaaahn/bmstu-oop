cmake_minimum_required(VERSION 3.19)
project(lab_03)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets)

add_executable(${PROJECT_NAME}
        main.cpp
        gui/qt/mainwindow.cpp
        gui/qt/mainwindow.h
        gui/qt/design.h
        gui/qt/drawer/qt_drawer.cpp
        gui/qt/drawer/qt_drawer.hpp
        gui/qt/drawer/factory/qt_drawer_factory.hpp
        gui/qt/drawer/factory/qt_drawer_factory.cpp
        )


add_subdirectory(./implementation)

target_include_directories(${PROJECT_NAME} PUBLIC
        ./implementation
        ./gui/qt/)


find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED} implementation)