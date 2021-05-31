cmake_minimum_required(VERSION 3.19)
project(exceptions)


add_executable(${PROJECT_NAME}
        base_exception.hpp
        load_exceptions.hpp
        model_exceptions.hpp
        ui_exceptions.hpp
        )

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)