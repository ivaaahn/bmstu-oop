#ifndef __RESTRUCT_TESTS_HPP__
#define __RESTRUCT_TESTS_HPP__

#include <gtest/gtest.h>

#include "matrix.hpp"


TEST(RestructTests, ResizePlus)
{
    Matrix<int> a = { {1, 2}, {3, 4} };
    Matrix<int> reference = { {1, 2, 0, 0}, {3, 4, 0, 0}, {0, 0, 0, 0} };

    a.resize(3, 4, 0);

    EXPECT_EQ(a, reference);
}


TEST(RestructTests, ResizeMinus)
{
    Matrix<int> a = { {1, 2, 3}, {3, 4, 5} };
    Matrix<int> reference = { {1, 2}, {3, 4} };

    a.resize(2, 2);

    EXPECT_EQ(a, reference);
}

TEST(RestructTests, ResizePlusMinus)
{
    Matrix<int> a = { {1, 2, 3}, {3, 4, 5} };
    Matrix<int> reference = { {1, 2}, {3, 4}, {7, 7} };

    a.resize(3, 2, 7);

    EXPECT_EQ(a, reference);
}


TEST(RestructTests, InsertRow)
{
    Matrix<int> a = { {1, 2}, {3, 4}, {5, 6} };
    Matrix<int> reference = { {1, 2}, {7, 7}, {3, 4}, {5, 6} };

    a.insertRow(1, 7);

    EXPECT_EQ(a, reference);
}


// TODO: Нужны тесты на out of bound 




#endif // __RESTRUCT_TESTS_HPP__