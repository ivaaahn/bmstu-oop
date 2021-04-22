#ifndef __TESTS_MATRIX_ITERATORS_INL__
#define __TESTS_MATRIX_ITERATORS_INL__

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

    EXPECT_TRUE(it.isBegin());
    EXPECT_TRUE(itConst.isBegin());
}


TEST(MatrixIterTests, IteratorIsEnd)
{
    Matrix<int> a = { {1, 2}, {3, 4} };
    auto it = a.end();
    auto itConst = a.cend();

    EXPECT_TRUE(it.isEnd());
    EXPECT_TRUE(itConst.isEnd());
}

TEST(MatrixIterTests, BoolAndIsValid)
{
    Matrix<int> a = { {1, 2}, {3, 4} };
    auto it = a.begin();
    auto itConst = a.cbegin();

    EXPECT_TRUE(bool(it));
    EXPECT_TRUE(it.isValid());

    EXPECT_TRUE(bool(itConst));
    EXPECT_TRUE(itConst.isValid());


    a = Matrix<int>(1, 2);

    EXPECT_FALSE(bool(it));
    EXPECT_FALSE(it.isValid());    

    EXPECT_FALSE(bool(itConst));
    EXPECT_FALSE(itConst.isValid());    
}


TEST(MatrixIterTests, PtrIterator)
{
    Matrix<int> a = { {1, 2}, {3, 4} };

    auto it = a.begin();
    auto *itPtr = &it;

    while(!it.isEnd())
    {
        EXPECT_EQ(itPtr->current(), *it);
        ++it;
    }
}


TEST(MatrixIterTests, PtrIteratorConst)
{
    Matrix<int> a = { {1, 2}, {3, 4} };

    auto itConst = a.cbegin();
    auto *itConstPtr = &itConst;

    while(!itConst.isEnd())
    {
        EXPECT_EQ(itConstPtr->current(), *itConst);
        ++itConst;
    }
}

TEST(MatrixIterTests, PrevNextMethods)
{
    Matrix<int> a = { {1, 2}, {3, 4} };

    auto it = a.begin();
    auto it2 = a.begin();

    EXPECT_EQ(*it2, *it);

    ++it;

    EXPECT_EQ(*it2.next(), *it);

    ++it2;
    --it;

    EXPECT_EQ(*it2.prev(), *it);
}


TEST(MatrixIterTests, PrevNextMethodsConst)
{
    Matrix<int> a = { {1, 2}, {3, 4} };

    auto it = a.cbegin();
    auto it2 = a.cbegin();

    EXPECT_EQ(*it2, *it);

    ++it;

    EXPECT_EQ(*it2.next(), *it);

    ++it2;
    --it;

    EXPECT_EQ(*it2.prev(), *it);
}

TEST(MatrixIterTests, PostPreIncDec)
{
    Matrix<int> a = { {1, 2}, {3, 4} };

    auto it1 = a.begin();
    auto it2 = it1.next();

    EXPECT_EQ(*++it1, *it2++);
    EXPECT_EQ(*it1--, *--it2);
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


#endif // __TESTS_MATRIX_ITERATORS_INL__