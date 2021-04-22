#ifndef __TESTS__MATRIX_ASSIGN_OPERATOR_INL__
#define __TESTS__MATRIX_ASSIGN_OPERATOR_INL__

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


TEST(AssignOperatorTests, BadInitList)
{
    Matrix<int> a;
    EXPECT_THROW((a = { {1, 2}, {3, 4, 5} }), InvalidArgument);
}



#endif  // __TESTS__MATRIX_ASSIGN_OPERATOR_INL__