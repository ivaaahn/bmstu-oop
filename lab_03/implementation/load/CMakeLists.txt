cmake_minimum_required(VERSION 3.19)
project(load)


add_subdirectory(./builders)
add_subdirectory(directors)
add_subdirectory(./solutions)
add_subdirectory(./source_loaders)

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)