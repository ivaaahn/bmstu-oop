cmake_minimum_required(VERSION 3.19)
project(visitor.hpp)

add_executable(${PROJECT_NAME}
        ./visitor.hpp
)

set_target_properties(visitor.hpp PROPERTIES LINKER_LANGUAGE CXX)
