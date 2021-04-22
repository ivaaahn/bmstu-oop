#ifndef __TESTS_MATRIX_OPERATIONS_INL__
#define __TESTS_MATRIX_OPERATIONS_INL__

#include <gtest/gtest.h>

#include "matrix.hpp"


TEST(MatrixOperations, MPlusM)
{
    Matrix<int> a = { {1,2}, {3,4} };
    Matrix<int> b = { {1,1}, {1,1} };

    Matrix<int> reference = { {2,3}, {4,5} };


    EXPECT_EQ(a+b, reference);
    EXPECT_EQ(b+a, reference);
    EXPECT_EQ(a.addMatr(b), reference);
    EXPECT_EQ(b.addMatr(a), reference);
}

TEST(MatrixOperations, MPlusMConst)
{
    const Matrix<int> a = { {1,2}, {3,4} };
    const Matrix<int> b = { {1,1}, {1,1} };

    const Matrix<int> reference = { {2,3}, {4,5} };


    EXPECT_EQ(a+b, reference);
    EXPECT_EQ(b+a, reference);
    EXPECT_EQ(a.addMatr(b), reference);
    EXPECT_EQ(b.addMatr(a), reference);
}



TEST(MatrixOperations, MPlusEquM)
{
    Matrix<int> reference = { {2,3}, {4,5} };

    Matrix<int> a = { {1,2}, {3,4} };
    Matrix<int> b = { {1,1}, {1,1} };
    EXPECT_EQ(a+=b, reference);

    a = { {1,2}, {3,4} };
    EXPECT_EQ(b+=a, reference);

    b = { {1,1}, {1,1} };
    EXPECT_EQ(a.addEqMatr(b), reference);

    a = { {1,2}, {3,4} };
    EXPECT_EQ(b.addEqMatr(a), reference);
}



TEST(MatrixOperations, MMinusM)
{
    Matrix<int> a = { {3,4}, {5,6} };
    Matrix<int> b = { {1,1}, {1,1} };

    Matrix<int> reference = { {2,3}, {4,5} };

    EXPECT_EQ(a-b, reference);
    EXPECT_EQ(a.subMatr(b), reference);
}

TEST(MatrixOperations, MMinusMConst)
{
    const Matrix<int> a = { {3,4}, {5,6} };
    const Matrix<int> b = { {1,1}, {1,1} };

    const Matrix<int> reference = { {2,3}, {4,5} };


    EXPECT_EQ(a-b, reference);
    EXPECT_EQ(a.subMatr(b), reference);
}




TEST(MatrixOperations, MMinusEquM)
{
    Matrix<int> reference = { {2,3}, {4,5} };

    Matrix<int> a = { {3,4}, {5,6} };
    Matrix<int> b = { {1,1}, {1,1} };
    EXPECT_EQ(a-=b, reference);

    a = { {3,4}, {5,6} };
    EXPECT_EQ(b-=a, -reference);

    b = { {1,1}, {1,1} };
    EXPECT_EQ(a.subEqMatr(b), reference);

    a = { {3,4}, {5,6} };
    EXPECT_EQ(b.subEqMatr(a), -reference);
}




TEST(MatrixOperations, MMulM)
{
    Matrix<int> a = { {1,2}, {3,4} };
    Matrix<int> b = { {1,1}, {1,1} };

    Matrix<int> reference1 = { {3,3}, {7,7} };
    Matrix<int> reference2 = { {4,6}, {4,6} };


    EXPECT_EQ(a*b, reference1);
    EXPECT_EQ(a.mulMatr(b), reference1);

    EXPECT_EQ(b*a, reference2);
    EXPECT_EQ(b.mulMatr(a), reference2);
}

TEST(MatrixOperations, MMulEye)
{
    Matrix<int> a = { {1,2}, {3,4} };
    Matrix<int> b = { {1,0}, {0,1} };

    Matrix<int> reference = { {1,2}, {3,4} };


    EXPECT_EQ(a*b, reference);
    EXPECT_EQ(a.mulMatr(b), reference);

    EXPECT_EQ(b*a, reference);
    EXPECT_EQ(b.mulMatr(a), reference);
}

TEST(MatrixOperations, MMulMConst)
{
    const Matrix<int> a = { {1,2}, {3,4} };
    const Matrix<int> b = { {1,1}, {1,1} };

    const Matrix<int> reference1 = { {3,3}, {7,7} };
    const Matrix<int> reference2 = { {4,6}, {4,6} };


    EXPECT_EQ(a*b, reference1);
    EXPECT_EQ(a.mulMatr(b), reference1);

    EXPECT_EQ(b*a, reference2);
    EXPECT_EQ(b.mulMatr(a), reference2);
}


TEST(MatrixOperations, MMulEyeConst)
{
    const Matrix<int> a = { {1,2}, {3,4} };
    const Matrix<int> b = { {1,0}, {0,1} };

    const Matrix<int> reference = { {1,2}, {3,4} };


    EXPECT_EQ(a*b, reference);
    EXPECT_EQ(a.mulMatr(b), reference);

    EXPECT_EQ(b*a, reference);
    EXPECT_EQ(b.mulMatr(a), reference);
}


TEST(MatrixOperations, MMulEl)
{
    int el = 2;
    Matrix<int> a = { {1,2}, {3,4} };

    Matrix<int> reference = { {2,4}, {6,8} };


    EXPECT_EQ(a*el, reference);
    EXPECT_EQ(el*a, reference);
    EXPECT_EQ(a.mulElem(el), reference);
}

TEST(MatrixOperations, MMulOne)
{
    int el = 1;
    Matrix<int> a = { {1,2}, {3,4} };

    Matrix<int> reference = { {1,2}, {3,4} };


    EXPECT_EQ(a*el, reference);
    EXPECT_EQ(el*a, reference);
    EXPECT_EQ(a.mulElem(el), reference);
}

TEST(MatrixOperations, MMulZero)
{
    int el = 0;
    Matrix<int> a = { {1,2}, {3,4} };

    Matrix<int> reference = { {0,0}, {0,0} };


    EXPECT_EQ(a*el, reference);
    EXPECT_EQ(el*a, reference);
    EXPECT_EQ(a.mulElem(el), reference);
}


TEST(MatrixOperations, MMulElConst)
{
    const int el = 2;
    const Matrix<int> a = { {1,2}, {3,4} };

    const Matrix<int> reference = { {2,4}, {6,8} };


    EXPECT_EQ(a*el, reference);
    EXPECT_EQ(el*a, reference);
    EXPECT_EQ(a.mulElem(el), reference);
}

TEST(MatrixOperations, MMulOneConst)
{
    const int el = 1;
    const Matrix<int> a = { {1,2}, {3,4} };

    const Matrix<int> reference = { {1,2}, {3,4} };


    EXPECT_EQ(a*el, reference);
    EXPECT_EQ(el*a, reference);
    EXPECT_EQ(a.mulElem(el), reference);
}

TEST(MatrixOperations, MMulZeroConst)
{
    const int el = 0;
    const Matrix<int> a = { {1,2}, {3,4} };

    const Matrix<int> reference = { {0,0}, {0,0} };


    EXPECT_EQ(a*el, reference);
    EXPECT_EQ(el*a, reference);
    EXPECT_EQ(a.mulElem(el), reference);
}


TEST(MatrixOperations, MMulEquM)
{
    Matrix<int> reference1 = { {3,3}, {7,7} };
    Matrix<int> reference2 = { {4,6}, {4,6} };

    Matrix<int> a = { {1,2}, {3,4} };
    Matrix<int> b = { {1,1}, {1,1} };
    EXPECT_EQ(a*=b, reference1);

    a = { {1,2}, {3,4} };
    EXPECT_EQ(b*=a, reference2);

    b = { {1,1}, {1,1} };
    EXPECT_EQ(a.mulEqMatr(b), reference1);

    a = { {1,2}, {3,4} };
    EXPECT_EQ(b.mulEqMatr(a), reference2);
}

TEST(MatrixOperations, MMulEquEye)
{
    Matrix<int> reference = { {1,2}, {3,4} };

    Matrix<int> a = { {1,2}, {3,4} };
    Matrix<int> b = { {1,0}, {0,1} };
    EXPECT_EQ(a*=b, reference);

    a = { {1,2}, {3,4} };
    EXPECT_EQ(b*=a, reference);

    b = { {1,0}, {0,1} };
    EXPECT_EQ(a.mulEqMatr(b), reference);

    a = { {1,2}, {3,4} };
    EXPECT_EQ(b.mulEqMatr(a), reference);
}


TEST(MatrixOperations, MMulEquEl)
{
    Matrix<int> reference = { {2,4}, {6,8} };

    Matrix<int> a = { {1,2}, {3,4} };
    int b = 2;
    EXPECT_EQ(a*=b, reference);


    a = { {1,2}, {3,4} };
    EXPECT_EQ(a.mulEqElem(b), reference);
}


TEST(MatrixOperations, MMulEquOne)
{
    Matrix<int> reference = { {1,2}, {3,4} };

    Matrix<int> a = { {1,2}, {3,4} };
    int b = 1;
    EXPECT_EQ(a*=b, reference);


    a = { {1,2}, {3,4} };
    EXPECT_EQ(a.mulEqElem(b), reference);
}

TEST(MatrixOperations, MMulEquZero)
{
    Matrix<int> reference = { {0,0}, {0,0} };

    Matrix<int> a = { {1,2}, {3,4} };
    int b = 0;
    EXPECT_EQ(a*=b, reference);


    a = { {1,2}, {3,4} };
    EXPECT_EQ(a.mulEqElem(b), reference);
}

TEST(MatrixOperations, MDivMEqu)
{
    Matrix<double> reference = { {1,0}, {0,1} };

    Matrix<double> a = { {1,2}, {3,4} };

    EXPECT_EQ(a / a, reference);
    EXPECT_EQ(a.divMatr(a), reference);
}

TEST(MatrixOperations, MDivMEquConst)
{
    const Matrix<double> reference = { {1,0}, {0,1} };

    const Matrix<double> a = { {1,2}, {3,4} };

    EXPECT_EQ(a / a, reference);
    EXPECT_EQ(a.divMatr(a), reference);
}


TEST(MatrixOperations, MDivM)
{
    Matrix<double> reference = { {1,0, 0}, {-1.2, 1.8, -0.4} };

    Matrix<double> a = { {1,2,3}, {3,4,2} };
    Matrix<double> b = { {1,2,3}, {3,4,4}, {3,2,4} };

    EXPECT_DOUBLE_EQ(a / b, reference);
    EXPECT_DOUBLE_EQ(a.divMatr(b), reference);
}


TEST(MatrixOperations, MDivMConst)
{
    const Matrix<double> reference = { {1,0, 0}, {-1.2, 1.8, -0.4} };

    const Matrix<double> a = { {1,2,3}, {3,4,2} };
    const Matrix<double> b = { {1,2,3}, {3,4,4}, {3,2,4} };

    EXPECT_DOUBLE_EQ(a / b, reference);
    EXPECT_DOUBLE_EQ(a.divMatr(b), reference);
}


TEST(MatrixOperations, MDivMSingularMatrix)
{
    Matrix<double> reference = { {1,0}, {0,1} };

    Matrix<double> a = { {1,2}, {3,4} };
    Matrix<double> b = { {0,0}, {0,0} };

    EXPECT_THROW(a / b, SingularMatrix);
}


TEST(MatrixOperations, MDivMSingularMatrixMethod)
{
    Matrix<double> reference = { {1,0}, {0,1} };

    Matrix<double> a = { {1,2}, {3,4} };
    Matrix<double> b = { {0,0}, {0,0} };

    EXPECT_THROW(a.divMatr(b), SingularMatrix);
}


TEST(MatrixOperations, MDivMNonSquareMatrix)
{
    Matrix<double> reference = { {1,0}, {0,1} };

    Matrix<double> a = { {1,2}, {3,4} };
    Matrix<double> b = { {1,2,3}, {4,5,6} };

    EXPECT_THROW(a / b, InvalidDimensions);
}

TEST(MatrixOperations, MDivMNonSquareMatrixMethod)
{
    Matrix<double> reference = { {1,0}, {0,1} };

    Matrix<double> a = { {1,2}, {3,4} };
    Matrix<double> b = { {1,2,3}, {4,5,6} };

    EXPECT_THROW(a / b, InvalidDimensions);
}



TEST(MatrixOperations, MDivMSingularMatrixConst)
{
    const Matrix<double> reference = { {1,0}, {0,1} };

    const Matrix<double> a = { {1,2}, {3,4} };
    const Matrix<double> b = { {0,0}, {0,0} };

    EXPECT_THROW(a / b, SingularMatrix);
}


TEST(MatrixOperations, MDivMSingularMatrixMethodConst)
{
    const Matrix<double> reference = { {1,0}, {0,1} };

    const Matrix<double> a = { {1,2}, {3,4} };
    const Matrix<double> b = { {0,0}, {0,0} };

    EXPECT_THROW(a.divMatr(b), SingularMatrix);
}


TEST(MatrixOperations, MDivMNonSquareMatrixConst)
{
    const Matrix<double> reference = { {1,0}, {0,1} };

    const Matrix<double> a = { {1,2}, {3,4} };
    const Matrix<double> b = { {1,2,3}, {4,5,6} };

    EXPECT_THROW(a / b, InvalidDimensions);
}

TEST(MatrixOperations, MDivMNonSquareMatrixMethodConst)
{
    const Matrix<double> reference = { {1,0}, {0,1} };

    const Matrix<double> a = { {1,2}, {3,4} };
    const Matrix<double> b = { {1,2,3}, {4,5,6} };

    EXPECT_THROW(a / b, InvalidDimensions);
}


TEST(MatrixOperations, MDivElem)
{
    Matrix<double> reference = { {1,2}, {3,4} };

    Matrix<double> a = { {2,4}, {6,8} };

    double b = 2;

    EXPECT_EQ(a / b, reference);
}

TEST(MatrixOperations, MDivElemConst)
{
    const Matrix<double> reference = { {1,2}, {3,4} };

    const Matrix<double> a = { {2,4}, {6,8} };

    const double b = 2;

    EXPECT_EQ(a / b, reference);
}


TEST(MatrixOperations, MDivElemZero)
{
    Matrix<double> a = { {2,4}, {6,8} };

    double b = 0;

    EXPECT_THROW(a / b, ZeroDivision);
}


TEST(MatrixOperations, MNegative)
{
    Matrix<double> a = { {2,4}, {6,8} };
    Matrix<double> reference = { {-2,-4}, {-6,-8} };

    EXPECT_EQ(-a, reference);
    EXPECT_EQ(a.neg(), reference);
}







#endif // __TESTS_MATRIX_OPERATIONS_INL__