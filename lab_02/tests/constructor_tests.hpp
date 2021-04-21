#ifndef __CONSTRUCTOR_TESTS_HPP__
#define __CONSTRUCTOR_TESTS_HPP__

#include <iostream>
#include <gtest/gtest.h>
#include "matrix.hpp"

TEST(ConstructorTests, Default)
{
    Matrix<int> a;
    EXPECT_EQ(a, Matrix<int>(0, 0));
}

TEST(ConstructorTests, InitList)
{
    Matrix<int> a = {{1,2}, {3,4}};
    EXPECT_EQ(a, Matrix<int>({{1,2}, {3,4}}));
}


TEST(ConstructorTests, Copy)
{
    Matrix<int> a = {{1,2}, {3,4}};
    Matrix<int> b = Matrix<int>(a);

    EXPECT_EQ(b, Matrix<int>({{1,2}, {3,4}}));
}

TEST(ConstructorTests, Move)
{
    Matrix<int> a = {{1,2}, {3,4}};
    Matrix<int> b = std::move(a);

    EXPECT_EQ(b, Matrix<int>({{1,2}, {3,4}}));
}


TEST(ConstructorTests, LargeDimensions)
{
    EXPECT_THROW(Matrix<int> err_m(-1, 2), MemoryError);
}

TEST(ConstructorTests, WithFiller)
{
    Matrix<double> a(2, 2, 1.0);
    EXPECT_EQ(a, Matrix<double>({{1.0, 1.0}, {1.0, 1.0}}));
}

TEST(ConstructorTests, BadDimensionalInitList)
{
    EXPECT_THROW(Matrix<int> a({{1, 2}, {3, 4, 5}}), InvalidArgument);
}

TEST(ConstructorTests, ZeroCols)
{
    Matrix<int> a(1,0);
    EXPECT_EQ(a, Matrix<int>(0,0));
}

TEST(ConstructorTests, ZeroRows)
{
    Matrix<int> a(0,1);
    EXPECT_EQ(a, Matrix<int>(0,0));
}

TEST(ConstructorTests, ZeroColsInitList)
{
    Matrix<int> a({{}, {}});
    EXPECT_EQ(a, Matrix<int>(0,0));
}


TEST(ConstructorTests, ZeroRowsInitList)
{
    Matrix<int> a({});
    EXPECT_EQ(a, Matrix<int>(0,0));
}



#endif  // __CONSTRUCTOR_TESTS_HPP__
