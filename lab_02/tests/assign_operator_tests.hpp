#ifndef __ASSIGN_OPERATOR_TESTS_HPP__
#define __ASSIGN_OPERATOR_TESTS_HPP__

#include <iostream>
#include <gtest/gtest.h>
#include "matrix.hpp"

TEST(AssignOperatorTests, Copy)
{
    Matrix<int> a = {{1,2}, {3,4}};
    Matrix<int> b;

    b = a;

    EXPECT_EQ(a, b);
}

TEST(AssignOperatorTests, Move)
{
    Matrix<int> a = {{1,2}, {3,4}};
    Matrix<int> b;

    b = std::move(a);

    EXPECT_EQ(a, b);
}

TEST(AssignOperatorTests, InitList)
{
    Matrix<int> a;
    a = { {1, 2}, {3, 4} };

    EXPECT_EQ(a, Matrix<int>({ {1, 2}, {3, 4} }));
}



#endif  // __ASSIGN_OPERATOR_TESTS_HPP__