cmake_minimum_required(VERSION 3.16)
project(lab_02)
set(CMAKE_CXX_STANDARD 20)

find_package(GTest REQUIRED)



set (DECL declarations)
set (IMPL implementations)
set (TESTS tests)

set (ITERATORS_SRC 
    ${DECL}/const_iterator.hpp
    ${IMPL}/const_iterator.inl
    ${DECL}/iterator.hpp
    ${IMPL}/iterator.inl)

set (EXCEPTIONS_SRC
    ${DECL}/exceptions.hpp)

set (MATRIX_BASE_SRC
    ${DECL}/matrix_base.hpp)

set (MATRIX_SRC
    ${DECL}/matrix.hpp
    ${IMPL}/matrix_assign_operators.inl
    ${IMPL}/matrix_checkers.inl
    ${IMPL}/matrix_construct.inl
    ${IMPL}/matrix_fill.inl
    ${IMPL}/matrix_iter.inl
    ${IMPL}/matrix_math.inl
    ${IMPL}/matrix_operations.inl
    ${IMPL}/matrix_restruct.inl
    ${IMPL}/matrix_row.inl)


set (TEST_SRC
    ${TESTS}/matrix_tests.hpp
    ${TESTS}/tests_matrix_assign_operaor.inl
    ${TESTS}/tests_matrix_construct.inl
    ${TESTS}/tests_matrix_filling.inl
    ${TESTS}/tests_matrix_iterators.inl
    ${TESTS}/tests_matrix_math.inl
    ${TESTS}/tests_matrix_restruct.inl
)

include_directories(
        ${GTEST_INCLUDE_DIRS}
        ${IMPL}
        ${DECL}
        ${TESTS})


add_executable(lab_02
        main.cpp
        ${ITERATORS_SRC}
        ${EXCEPTIONS_SRC}
        ${MATRIX_BASE_SRC}
        ${MATRIX_SRC}
        ${TESTS_SRC})

target_link_libraries(
    lab_02 ${GTEST_LIBRARIES} Threads::Threads)

enable_testing()
        






