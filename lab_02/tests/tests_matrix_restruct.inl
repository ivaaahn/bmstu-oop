#ifndef __TESTS_MATRIX_RESTRUCT_INL__
#define __TESTS_MATRIX_RESTRUCT_INL__

#include <gtest/gtest.h>

#include "matrix.hpp"

TEST(RestructTests, ResizePlus)
{
    Matrix<int> a = {{1, 2}, {3, 4}};
    Matrix<int> reference = {{1, 2, 0, 0}, {3, 4, 0, 0}, {0, 0, 0, 0}};

    a.resize(3, 4, 0);

    EXPECT_EQ(a, reference);
}

TEST(RestructTests, ResizeMinus)
{
    Matrix<int> a = {{1, 2, 3}, {3, 4, 5}};
    Matrix<int> reference = {{1, 2}, {3, 4}};

    a.resize(2, 2);

    EXPECT_EQ(a, reference);
}

TEST(RestructTests, ResizePlusMinus)
{
    Matrix<int> a = {{1, 2, 3}, {3, 4, 5}};
    Matrix<int> reference = {{1, 2}, {3, 4}, {7, 7}};

    a.resize(3, 2, 7);

    EXPECT_EQ(a, reference);
}

TEST(RestructTests, InsertRowOK)
{
    Matrix<int> a = {{1, 2}, {3, 4}, {5, 6}};
    Matrix<int> reference = {{1, 2}, {7, 7}, {3, 4}, {5, 6}};

    a.insertRow(1, 7);

    EXPECT_EQ(a, reference);
}

TEST(RestructTests, InsertRowInitList)
{
    Matrix<int> a = {{1, 2}, {3, 4}, {5, 6}};
    Matrix<int> reference = {{1, 2}, {2, 5}, {3, 4}, {5, 6}};

    a.insertRow(1, {2, 5});

    EXPECT_EQ(a, reference);
}

TEST(RestructTests, InsertRowInitListEmpty)
{
    Matrix<int> a = {{1, 2}, {3, 4}, {5, 6}};
    EXPECT_THROW(a.insertRow(1, {}), InvalidArgument);
}

TEST(RestructTests, InsertColInitListEmpty)
{
    Matrix<int> a = {{1, 2}, {3, 4}, {5, 6}};
    EXPECT_THROW(a.insertCol(2, {}), InvalidArgument);
}

TEST(RestructTests, InsertRowDefaultFill)
{
    Matrix<int> a = {{1, 2}, {3, 4}, {5, 6}};
    Matrix<int> reference = {{1, 2}, {0, 0}, {3, 4}, {5, 6}};

    a.insertRow(1);

    EXPECT_EQ(a, reference);
}

TEST(RestructTests, InsertRowOutOfRangePlus)
{
    Matrix<int> a = {{1, 2}, {3, 4}, {5, 6}};
    EXPECT_THROW(a.insertRow(4, 7), IndexError);
}

TEST(RestructTests, InsertRowOutOfRangeMinus)
{
    Matrix<int> a = {{1, 2}, {3, 4}, {5, 6}};
    EXPECT_THROW(a.insertRow(-1, 7), IndexError);
}

TEST(RestructTests, InsertColOK)
{
    Matrix<int> a = {{1, 2}, {3, 4}, {5, 6}};
    Matrix<int> reference = {{1, 5, 2}, {3, 5, 4}, {5, 5, 6}};

    a.insertCol(1, 5);

    EXPECT_EQ(a, reference);
}

TEST(RestructTests, InsertColInitList)
{
    Matrix<int> a = {{1, 2}, {3, 4}, {5, 6}};
    Matrix<int> reference = {{1, 1, 2}, {3, 2, 4}, {5, 3, 6}};

    a.insertCol(1, {1, 2, 3});

    EXPECT_EQ(a, reference);
}

TEST(RestructTests, InsertColDefaultFill)
{
    Matrix<int> a = {{1, 2}, {3, 4}, {5, 6}};
    Matrix<int> reference = {{1, 0, 2}, {3, 0, 4}, {5, 0, 6}};

    a.insertCol(1);

    EXPECT_EQ(a, reference);
}

TEST(RestructTests, InsertColOutOfRangePlus)
{
    Matrix<int> a = {{1, 2}, {3, 4}, {5, 6}};
    EXPECT_THROW(a.insertCol(3, 7), IndexError);
}

TEST(RestructTests, InsertColOutOfRangeMinus)
{
    Matrix<int> a = {{1, 2}, {3, 4}, {5, 6}};
    EXPECT_THROW(a.insertCol(-3, 7), IndexError);
}

TEST(RestructTests, DeleteRowOK)
{
    Matrix<int> a = {{1, 2}, {3, 4}, {5, 6}};
    Matrix<int> reference = {{1, 2}, {5, 6}};

    a.deleteRow(1);

    EXPECT_EQ(a, reference);
}

TEST(RestructTests, DeleteRowOutOfRangePlus)
{
    Matrix<int> a = {{1, 2}, {3, 4}, {5, 6}};
    EXPECT_THROW(a.deleteRow(3), IndexError);
}

TEST(RestructTests, DeleteRowOutOfRangeMinus)
{
    Matrix<int> a = {{1, 2}, {3, 4}, {5, 6}};
    EXPECT_THROW(a.deleteRow(-1), IndexError);
}

TEST(RestructTests, DeleteColOK)
{
    Matrix<int> a = {{1, 2, 3}, {3, 4, 5}, {5, 6, 7}};
    Matrix<int> reference = {{1, 3}, {3, 5}, {5, 7}};

    a.deleteCol(1);

    EXPECT_EQ(a, reference);
}

TEST(RestructTests, DeleteColOutOfRangePlus)
{
    Matrix<int> a = {{1, 2}, {3, 4}, {5, 6}};
    EXPECT_THROW(a.deleteCol(3), IndexError);
}

TEST(RestructTests, DeleteColOutOfRangeMinus)
{
    Matrix<int> a = {{1, 2}, {3, 4}, {5, 6}};
    EXPECT_THROW(a.deleteCol(-1), IndexError);
}

TEST(RestructTests, IsSquare)
{
    Matrix<double> a(5, 5);
    Matrix<char> b(2, 3);

    EXPECT_TRUE(a.isSquare());
    EXPECT_FALSE(b.isSquare());
}

#endif // __TESTS_MATRIX_RESTRUCT_INL__