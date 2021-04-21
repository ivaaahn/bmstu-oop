#ifndef __MATRIX_ITERATOR_TESTS_HPP__
#define __MATRIX_ITERATOR_TESTS_HPP__

#include <gtest/gtest.h>

#include "matrix.hpp"


TEST(MatrixIterTests, ForwardPassOutput)
{
    Matrix<int> a = { {1, 2}, {3, 4} };

    int reference[4] = {1, 2, 3, 4};

    size_t i = 0;
    for (auto it = a.begin(); it != a.end(); ++it)
    {
        EXPECT_EQ(*it, reference[i]);
        EXPECT_EQ(it.current(), reference[i]);
        ++i;
    }
}


TEST(MatrixIterTests, ForwardPassOutputConst)
{
    Matrix<int> a = { {1, 2}, {3, 4} };

    int reference[4] = {1, 2, 3, 4};

    size_t i = 0;
    for (auto it = a.cbegin(); it != a.cend(); ++it)
    {
        EXPECT_EQ(*it, reference[i]);
        EXPECT_EQ(it.current(), reference[i]);
        ++i;
    }
}

TEST(MatrixIterTests, ReversePassOutput)
{
    Matrix<int> a = { {1, 2}, {3, 4} };

    int reference[4] = {1, 2, 3, 4};

    size_t i = 3;
    for (auto it = a.end(); it != a.begin(); )
    {   
        --it;
        EXPECT_EQ(*it, reference[i]);
        EXPECT_EQ(it.current(), reference[i]);
        --i;
    }
}

TEST(MatrixIterTests, ReversePassOutputConst)
{
    Matrix<int> a = { {1, 2}, {3, 4} };

    int reference[4] = {1, 2, 3, 4};

    size_t i = 3;
    for (auto it = a.cend(); it != a.cbegin(); )
    {   
        --it;
        EXPECT_EQ(*it, reference[i]);
        EXPECT_EQ(it.current(), reference[i]);
        --i;
    }
}


TEST(MatrixIterTests, ForwardPassInput)
{
    Matrix<int> a;

    int reference[4] = {1, 2, 3, 4};

    size_t i = 0;
    for (auto it = a.begin(); it != a.end(); ++it)
    {   
        *it = reference[i];
        EXPECT_EQ(*it, reference[i]);
        EXPECT_EQ(it.current(), reference[i]);
        ++i;
    }
}



TEST(MatrixIterTests, ReversePassInput)
{
    Matrix<int> a;

    int reference[4] = {1, 2, 3, 4};

    size_t i = 3;
    for (auto it = a.end(); it != a.begin(); )
    {   
        --it;
        *it = reference[i];
        EXPECT_EQ(*it, reference[i]);
        EXPECT_EQ(it.current(), reference[i]);
        --i;
    }
}


TEST(MatrixIterTests, IteratorIsBegin)
{
    Matrix<int> a = { {1, 2}, {3, 4} };
    auto it = a.begin();
    auto itConst = a.cbegin();

    EXPECT_EQ(it.isBegin(), true);
    EXPECT_EQ(itConst.isBegin(), true);
}


TEST(MatrixIterTests, IteratorIsEnd)
{
    Matrix<int> a = { {1, 2}, {3, 4} };
    auto it = a.end();
    auto itConst = a.cend();

    EXPECT_EQ(it.isEnd(), true);
    EXPECT_EQ(itConst.isEnd(), true);
}

TEST(MatrixIterTests, BoolAndIsValid)
{
    Matrix<int> a = { {1, 2}, {3, 4} };
    auto it = a.begin();
    auto itConst = a.cbegin();

    EXPECT_EQ(bool(it), true);
    EXPECT_EQ(it.isValid(), true);

    EXPECT_EQ(bool(itConst), true);
    EXPECT_EQ(itConst.isValid(), true);


    a = Matrix<int>(1, 2);

    EXPECT_EQ(bool(it), false);
    EXPECT_EQ(it.isValid(), false);    

    EXPECT_EQ(bool(itConst), false);
    EXPECT_EQ(itConst.isValid(), false);    
}

TEST(MatrixIterTests, CopyIterator)
{
    Matrix<int> a = { {1, 2}, {3, 4} };
    
    auto it = a.begin();

    int reference[4] = {1, 2, 3, 4};

    size_t i = 0;
    for (auto it2 = it; it2 != a.end(); ++it2)
        EXPECT_EQ(*it2, reference[i++]);
}


#endif // __MATRIX_ITERATOR_TESTS_HPP__