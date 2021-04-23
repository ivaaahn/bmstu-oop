#ifndef __TESTS_MATRIX_FILLING_INL__
#define __TESTS_MATRIX_FILLING_INL__

#include <gtest/gtest.h>

#include "matrix.hpp"

TEST(FillingTests, FullFill)
{
    Matrix<int> a(2, 3);
    Matrix<int> reference = {{1, 1, 1}, {1, 1, 1}};

    a.fill(a.begin(), a.end(), 1);

    EXPECT_EQ(a, reference);
}

TEST(FillingTests, FullFillDefaultFiller)
{
    Matrix<int> a(2, 3);
    Matrix<int> reference = {{0, 0, 0}, {0, 0, 0}};

    a.fill(a.begin(), a.end());

    EXPECT_EQ(a, reference);
}

TEST(FillingTests, FirstRowFill)
{
    Matrix<int> a = {{1, 2}, {3, 4}};
    Matrix<int> reference = {{0, 0}, {3, 4}};

    auto it_start = a.begin();

    auto it_end = a.begin() + 2;

    a.fill(it_start, it_end, 0);

    EXPECT_EQ(a, reference);
}

TEST(FillingTests, FillFromSource)
{
    Matrix<int> a = {{1, 2}, {3, 4}};
    Matrix<int> b = {{9, 8}, {7, 6}};

    Matrix<int> reference = {{1, 8}, {7, 4}};

    auto it_start = a.begin() + 1;

    auto it_src_start = b.begin() + 1;
    auto it_src_end = b.end() - 1;

    a.fill(it_start, it_src_start, it_src_end);

    EXPECT_EQ(a, reference);
}

TEST(FillingTests, FillFromSourceConst)
{
    Matrix<int> a = {{1, 2}, {3, 4}};
    Matrix<int> b = {{9, 8}, {7, 6}};

    Matrix<int> reference = {{1, 8}, {7, 4}};

    auto it_start = a.begin() + 1;

    auto it_src_start = b.cbegin() + 1;
    auto it_src_end = b.cend() - 1;

    a.fill(it_start, it_src_start, it_src_end);

    EXPECT_EQ(a, reference);
}

TEST(FillingTests, FillFromSourceAnyConst)
{

    const std::array<int, 4> b = {9, 8, 7, 6};
    Matrix<int> a = {{1, 2}, {3, 4}};

    const Matrix<int> reference = {{1, 8}, {7, 4}};

    auto it_start = a.begin() + 1;

    auto it_src_start = b.cbegin() + 1;
    auto it_src_end = b.cend() - 1;

    a.fill(it_start, it_src_start, it_src_end);

    EXPECT_EQ(a, reference);
}

TEST(FillingTests, ZerosFill)
{
    Matrix<int> a(2, 2);
    Matrix<int> reference = {{0, 0}, {0, 0}};

    EXPECT_EQ(a.zeros(), reference);
}

TEST(FillingTests, EyeFillInt)
{
    Matrix<int> a(2, 2);
    Matrix<int> reference = {{1, 0}, {0, 1}};

    EXPECT_EQ(a.eye(), reference);
}

TEST(FillingTests, EyeFillDouble)
{
    Matrix<double> a(2, 2);
    Matrix<double> reference = {{1.0, 0.0}, {0.0, 1.0}};

    EXPECT_EQ(a.eye(), reference);
}

#endif // __TESTS_MATRIX_FILLING_INL__