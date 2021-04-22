#ifndef __TESTS_MATRIX_ITERATORS_INL__
#define __TESTS_MATRIX_ITERATORS_INL__

#include <gtest/gtest.h>

#include "matrix.hpp"


TEST(MatrixIterTests, ItCopy)
{
    Matrix<int> a = { {1, 2}, {3, 4} };

    auto it1 = a.end();
    auto it2(a.begin());

    EXPECT_EQ(it1, a.end());
    EXPECT_EQ(it2, a.begin());
}

TEST(MatrixIterTests, ItAssign)
{
    Matrix<int> a = { {1, 2}, {3, 4} };

    auto it = a.begin();
    it = a.end();

    EXPECT_EQ(it, a.end());
}

TEST(MatrixIterTests, ItCopyConst)
{
    const Matrix<int> a = { {1, 2}, {3, 4} };

    auto it1 = a.end();
    auto it2(a.begin());

    auto it1C = a.cend();
    auto it2C(a.cbegin());


    EXPECT_EQ(it1, a.end());
    EXPECT_EQ(it2, a.begin());

    EXPECT_EQ(it1C, a.end());
    EXPECT_EQ(it2C, a.begin());
}

TEST(MatrixIterTests, ItAssignConst)
{
    const Matrix<int> a = { {1, 2}, {3, 4} };

    auto it = a.begin();
    auto itC = a.cbegin();

    it = a.end();
    itC = a.cend();

    EXPECT_EQ(it, a.end());
    EXPECT_EQ(itC, a.end());
}


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
    const Matrix<int> a = { {1, 2}, {3, 4} };

    int reference[4] = {1, 2, 3, 4};

    size_t i = 0;
    for (auto it = a.begin(); it != a.end(); ++it)
    {
        EXPECT_EQ(*it, reference[i]);
        EXPECT_EQ(it.current(), reference[i]);
        ++i;
    }

    i = 0;
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
    const Matrix<int> a = { {1, 2}, {3, 4} };

    int reference[4] = {1, 2, 3, 4};

    size_t i = 3;
    for (auto it = a.cend(); it != a.cbegin(); )
    {   
        --it;
        EXPECT_EQ(*it, reference[i]);
        EXPECT_EQ(it.current(), reference[i]);
        --i;
    }

    i = 3;
    for (auto it = a.end(); it != a.begin(); )
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
    const Matrix<int> a = { {1, 2}, {3, 4} };

    auto itConst = a.begin();
    auto *itConstPtr = &itConst;

    while(!itConst.isEnd())
    {
        EXPECT_EQ(itConstPtr->current(), *itConst);
        ++itConst;
    }

    auto itConstC = a.cbegin();
    auto *itConstPtrC = &itConstC;

    while(!itConstC.isEnd())
    {
        EXPECT_EQ(itConstPtrC->current(), *itConstC);
        ++itConstC;
    }

}

TEST(MatrixIterTests, PostPreIncDec)
{
    Matrix<int> a = { {1, 2}, {3, 4} };

    auto it1 = a.begin();
    auto it2 = it1+1;

    EXPECT_EQ(*++it1, *it2++);
    EXPECT_EQ(*it1--, *--it2);
}

TEST(MatrixIterTests, PostPreIncDecConst)
{
    const Matrix<int> a = { {1, 2}, {3, 4} };

    auto it1 = a.begin();
    auto it2 = it1+1;

    EXPECT_EQ(*++it1, *it2++);
    EXPECT_EQ(*it1--, *--it2);


    it1 = a.cbegin();
    it2 = it1+1;

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

TEST(MatrixIterTests, ItPlusValue)
{
    Matrix<int> a = { {1, 2}, {3, 4} };
    
    auto it = a.begin();

    EXPECT_EQ(*(it+2), 3);
    EXPECT_EQ(*(2+it), 3);
    EXPECT_EQ(it[2], 3);

    it += 2;

    EXPECT_EQ(*it, 3);
}


TEST(MatrixIterTests, ItPlusValueConst)
{
    const Matrix<int> a = { {1, 2}, {3, 4} };
    
    auto it = a.begin();

    EXPECT_EQ(*(it+2), 3);
    EXPECT_EQ(*(2+it), 3);
    EXPECT_EQ(it[2], 3);

    it += 2;

    EXPECT_EQ(*it, 3);

    it = a.cbegin();

    EXPECT_EQ(*(it+2), 3);
    EXPECT_EQ(*(2+it), 3);
    EXPECT_EQ(it[2], 3);

    it += 2;

    EXPECT_EQ(*it, 3);

}

TEST(MatrixIterTests, ItMinusValue)
{
    Matrix<int> a = { {1, 2}, {3, 4} };
    
    auto it = a.end();

    EXPECT_EQ(*(it-2), 3);

    it -= 2;

    EXPECT_EQ(*it, 3);
}

TEST(MatrixIterTests, ItMinusValueConst)
{
    const Matrix<int> a = { {1, 2}, {3, 4} };
    
    auto it = a.end();

    EXPECT_EQ(*(it-2), 3);

    it -= 2;

    EXPECT_EQ(*it, 3);



    it = a.cend();

    EXPECT_EQ(*(it-2), 3);

    it -= 2;

    EXPECT_EQ(*it, 3);
}


TEST(MatrixIterTests, ItMinusIt)
{
    Matrix<int> a = { {1, 2}, {3, 4} };
    
    auto it1 = a.begin();
    auto it2 = a.end();

    EXPECT_EQ(it2-it1, 4);
    EXPECT_EQ(it1-it2, -4);
}


TEST(MatrixIterTests, ItMinusItConst)
{
    const Matrix<int> a = { {1, 2}, {3, 4} };
    
    auto it1 = a.begin();
    auto it2 = a.end();

    EXPECT_EQ(it2-it1, 4);
    EXPECT_EQ(it1-it2, -4);


    it1 = a.cbegin();
    it2 = a.cend();

    EXPECT_EQ(it2-it1, 4);
    EXPECT_EQ(it1-it2, -4);
}


TEST(MatrixIterTests, ItCmp)
{
    Matrix<int> a = { {1, 2}, {3, 4} };
    
    auto it1 = a.begin();
    auto it2 = a.end();
    auto it3 = a.begin();
    auto it4 = a.end();

    EXPECT_TRUE(it1 < it2);
    EXPECT_TRUE(it1 <= it3);
    EXPECT_TRUE(it4 > it3);
    EXPECT_TRUE(it4 >= it2);
    EXPECT_TRUE(it1 == it3);
    EXPECT_TRUE(it2 != it3);

    EXPECT_FALSE(it1 >= it2);
    EXPECT_FALSE(it1 > it3);
    EXPECT_FALSE(it4 <= it3);
    EXPECT_FALSE(it4 < it2);
    EXPECT_FALSE(it1 != it3);
    EXPECT_FALSE(it2 == it3);
}


TEST(MatrixIterTests, ItCmpConst)
{
    const Matrix<int> a = { {1, 2}, {3, 4} };
    
    auto it1 = a.begin();
    auto it2 = a.end();
    auto it3 = a.begin();
    auto it4 = a.end();

    EXPECT_TRUE(it1 < it2);
    EXPECT_TRUE(it1 <= it3);
    EXPECT_TRUE(it4 > it3);
    EXPECT_TRUE(it4 >= it2);
    EXPECT_TRUE(it1 == it3);
    EXPECT_TRUE(it2 != it3);

    EXPECT_FALSE(it1 >= it2);
    EXPECT_FALSE(it1 > it3);
    EXPECT_FALSE(it4 <= it3);
    EXPECT_FALSE(it4 < it2);
    EXPECT_FALSE(it1 != it3);
    EXPECT_FALSE(it2 == it3);


    it1 = a.cbegin();
    it2 = a.cend();
    it3 = a.cbegin();
    it4 = a.cend();

    EXPECT_TRUE(it1 < it2);
    EXPECT_TRUE(it1 <= it3);
    EXPECT_TRUE(it4 > it3);
    EXPECT_TRUE(it4 >= it2);
    EXPECT_TRUE(it1 == it3);
    EXPECT_TRUE(it2 != it3);

    EXPECT_FALSE(it1 >= it2);
    EXPECT_FALSE(it1 > it3);
    EXPECT_FALSE(it4 <= it3);
    EXPECT_FALSE(it4 < it2);
    EXPECT_FALSE(it1 != it3);
    EXPECT_FALSE(it2 == it3);
}



TEST(MatrixIterTests, ItSwap)
{
    Matrix<int> a = { {1, 2}, {3, 4} };
    Matrix<int> reference = { {4, 2}, {3, 1} };


    auto it1 = a.begin();
    auto it2 = a.end() - 1;

    it1.swapWith(it2);

    EXPECT_EQ(a, reference);
}


#endif // __TESTS_MATRIX_ITERATORS_INL__