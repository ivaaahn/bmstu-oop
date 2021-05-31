cmake_minimum_required(VERSION 3.19)
project(implementation)

add_subdirectory(./commands)
add_subdirectory(./config_manager)
add_subdirectory(./drawer)
add_subdirectory(./exceptions)
add_subdirectory(./facade)
add_subdirectory(./load)
add_subdirectory(./managers)
add_subdirectory(./objects)
add_subdirectory(./scene)
add_subdirectory(./visitor)

set_target_properties(commands PROPERTIES LINKER_LANGUAGE CXX)

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)