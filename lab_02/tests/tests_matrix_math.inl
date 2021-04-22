#ifndef __TESTS_MATRIX_MATH_INL__
#define __TESTS_MATRIX_MATH_INL__

#include <gtest/gtest.h>

#include "matrix.hpp"

TEST(MatrixMathTests, Determinant1x1)
{
    Matrix<double> a = {{1}};

    EXPECT_EQ(a.calcDeterminant(), 1.0);
}

TEST(MatrixMathTests, Determinant2x2)
{
    Matrix<double> a = {{1, 2}, {3, 4}};

    EXPECT_EQ(a.calcDeterminant(), -2.0);
}

TEST(MatrixMathTests, DeterminantBig)
{
    Matrix<double> a(4, 4);

    int k = 1;
    for (auto &item : a)
        item = k++;

    EXPECT_EQ(a.calcDeterminant(), 0.0);
}

TEST(MatrixMathTests, Determinant0x0)
{
    Matrix<double> a{};

    EXPECT_EQ(a.calcDeterminant(), 1.0);
}

TEST(MatrixMathTests, NonSquare)
{
    Matrix<double> a = {{1, 2, 3}, {4, 5, 6}};

    EXPECT_THROW(a.calcDeterminant(), InvalidDimensions);
}

TEST(MatrixMathTests, Transpose0x0)
{
    Matrix<double> a{};
    Matrix<double> reference{};

    EXPECT_EQ(a.getTransposed(), reference);
}

TEST(MatrixMathTests, Transpose1x1)
{
    Matrix<double> a = {{1}};
    Matrix<double> reference = {{1}};

    EXPECT_EQ(a.getTransposed(), reference);
}

TEST(MatrixMathTests, TransposeDefault)
{
    Matrix<double> a = {{1, 2, 3}, {4, 5, 6}};
    Matrix<double> reference = {{1, 4}, {2, 5}, {3, 6}};

    EXPECT_EQ(a.getTransposed(), reference);
}

TEST(MatrixMathTests, Inverse0x0)
{
    Matrix<double> a{};
    Matrix<double> reference{};

    EXPECT_EQ(a.getInversed(), reference);
}

TEST(MatrixMathTests, Inverse1x1)
{
    Matrix<double> a = {{2.0}};
    Matrix<double> reference = {{0.5}};

    EXPECT_EQ(a.getInversed(), reference);
}

TEST(MatrixMathTests, Inverse2x2)
{
    Matrix<double> a = {{1.0, 2.0}, {3.0, 4.0}};
    Matrix<double> reference = {{-2.0, 1.0}, {1.5, -0.5}};

    EXPECT_EQ(a.getInversed(), reference);
}

TEST(MatrixMathTests, InverseNonSquare)
{
    Matrix<double> a = {{1, 2, 3}, {4, 5, 6}};

    EXPECT_THROW(a.getInversed(), InvalidDimensions);
}

TEST(MatrixMathTests, InverseSingular)
{
    Matrix<double> a = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    EXPECT_THROW(a.getInversed(), SingularMatrix);
}

TEST(MatrixMathTests, Minor)
{
    Matrix<double> a = {{1, 2}, {3, 4}};
    EXPECT_EQ(a.calcMinor(0, 0), 4);
}

TEST(MatrixMathTests, MinorNonSquare)
{
    Matrix<double> a = {{1, 2, 3}, {4, 5, 6}};
    EXPECT_THROW(a.calcMinor(0, 0), InvalidDimensions);
}

#endif // __TEST_MATRIX_MATH_INL__