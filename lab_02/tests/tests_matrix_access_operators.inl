#ifndef __TESTS_MATRIX_ACCESS_OPERATORS_INL__
#define __TESTS_MATRIX_ACCESS_OPERATORS_INL__

#include <gtest/gtest.h>

#include "matrix.hpp"

TEST(MatrixAccessOperatorsTests, AllOperatorsOK)
{
    Matrix<int> a = {{1, 2}, {3, 4}};

    EXPECT_EQ(a[0][1], 2);
    EXPECT_EQ(a(0, 1), 2);
    EXPECT_EQ(a.at(0, 1), 2);
}

TEST(MatrixAccessOperatorsTests, SetOK)
{
    Matrix<int> a = {{1, 2}, {3, 4}};
    Matrix<int> reference = {{100, 200}, {300, 4}};

    a[0][0] = 100;
    a(0, 1) = 200;
    a.at(1, 0) = 300;

    EXPECT_EQ(a, reference);
}

TEST(MatrixAccessOperatorsTests, AllOperatorsOKConst)
{
    const Matrix<int> a = {{1, 2}, {3, 4}};

    EXPECT_EQ(a[0][1], 2);
    EXPECT_EQ(a(0, 1), 2);
    EXPECT_EQ(a.at(0, 1), 2);
}

TEST(MatrixAccessOperatorsTests, SqBracketsBadRow)
{
    Matrix<int> a = {{1, 2}, {3, 4}};
    EXPECT_THROW(a[2][0], IndexError);
}

TEST(MatrixAccessOperatorsTests, CirBracketsBadRow)
{
    Matrix<int> a = {{1, 2}, {3, 4}};
    EXPECT_THROW(a(2, 0), IndexError);
}

TEST(MatrixAccessOperatorsTests, AtMethodBadRow)
{
    Matrix<int> a = {{1, 2}, {3, 4}};
    EXPECT_THROW(a.at(2, 0), IndexError);
}

TEST(MatrixAccessOperatorsTests, SqBracketsBadCol)
{
    Matrix<int> a = {{1, 2}, {3, 4}};
    EXPECT_THROW(a[0][2], IndexError);
}

TEST(MatrixAccessOperatorsTests, CirBracketsBadCol)
{
    Matrix<int> a = {{1, 2}, {3, 4}};
    EXPECT_THROW(a(0, 2), IndexError);
}

TEST(MatrixAccessOperatorsTests, AtMethodBadCol)
{
    Matrix<int> a = {{1, 2}, {3, 4}};
    EXPECT_THROW(a.at(0, 2), IndexError);
}

TEST(MatrixAccessOperatorsTests, SqBracketsBadRowConst)
{
    const Matrix<int> a = {{1, 2}, {3, 4}};
    EXPECT_THROW(a[2][0], IndexError);
}

TEST(MatrixAccessOperatorsTests, CirBracketsBadRowConst)
{
    const Matrix<int> a = {{1, 2}, {3, 4}};
    EXPECT_THROW(a(2, 0), IndexError);
}

TEST(MatrixAccessOperatorsTests, AtMethodBadRowConst)
{
    const Matrix<int> a = {{1, 2}, {3, 4}};
    EXPECT_THROW(a.at(2, 0), IndexError);
}

TEST(MatrixAccessOperatorsTests, SqBracketsBadColConst)
{
    const Matrix<int> a = {{1, 2}, {3, 4}};
    EXPECT_THROW(a[0][2], IndexError);
}

TEST(MatrixAccessOperatorsTests, CirBracketsBadColConst)
{
    const Matrix<int> a = {{1, 2}, {3, 4}};
    EXPECT_THROW(a(0, 2), IndexError);
}

TEST(MatrixAccessOperatorsTests, AtMethodBadColConst)
{
    const Matrix<int> a = {{1, 2}, {3, 4}};
    EXPECT_THROW(a.at(0, 2), IndexError);
}

#endif // __TESTS_MATRIX_ACCESS_OPERATORS_INL__