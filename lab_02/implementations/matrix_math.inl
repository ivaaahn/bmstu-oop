#ifndef __MATRIX_MATH_INL__
#define __MATRIX_MATH_INL__

#include "matrix.hpp"

template <typename T>
static T _determinant(const Matrix<T> &matrix)
{
    if (!matrix)
        return 1;

    size_t rows = matrix.getRows(), cols = matrix.getCols();

    if (rows == 2)
        return matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
    if (rows == 1)
        return matrix[0][0];

    T result = {};
    for (size_t j = 0; j < cols; ++j)
    {
        T minor = matrix.calcMinor(0, j);
        result += j & 1 ? -matrix[0][j] * minor : matrix[0][j] * minor;
    }

    return result;
}

template <typename T>
T Matrix<T>::calcMinor(const size_t row, const size_t col) const
{
    if (!this->isSquare())
        throw InvalidDimensions(__FILE__, __LINE__, "Matrix should be square to calculate minor");

    Matrix<T> cutMatrix(*(this->rows) - 1, *(this->cols) - 1);

    size_t rowIndex, colIndex;
    for (size_t i = 0; i < *(this->rows) - 1; ++i)
        for (size_t j = 0; j < *(this->cols) - 1; ++j)
        {
            rowIndex = i >= row ? i + 1 : i;
            colIndex = j >= col ? j + 1 : j;
            cutMatrix[i][j] = this->data[rowIndex][colIndex];
        }

    return _determinant(cutMatrix);
}

template <typename T>
Matrix<T> Matrix<T>::getTransposed()
{
    if (!*this || (*(this->rows) == *(this->cols) == 1))
        return Matrix<T>(*this);

    Matrix<T> result(*(this->cols), *(this->rows));

    for (size_t i = 0; i < *(this->rows); ++i)
        for (size_t j = 0; j < *(this->cols); ++j)
            result[j][i] = this->data[i][j];

    return result;
}

template <typename T>
T Matrix<T>::calcDeterminant() const
{
    if (!this->isSquare())
        throw InvalidDimensions(__FILE__, __LINE__, "Matrix should be square to get determinant");

    return _determinant(*this);
}

template <typename T>
Matrix<T> Matrix<T>::getInversed()
{
    if (!*this)
        return Matrix<T>(*this);

    if (!this->isSquare())
        throw InvalidDimensions(__FILE__, __LINE__, "Only square matrix can be inversed");

    T thisDet = this->calcDeterminant();
    if (!thisDet)
        throw SingularMatrix(__FILE__, __LINE__, "A singular matrix cannot be inverted");

    Matrix<T> result(*(this->rows), *(this->cols));
    T value = {};

    for (size_t i = 0; i < *(this->rows); ++i)
        for (size_t j = 0; j < *(this->cols); ++j)
        {
            value = this->calcMinor(i, j) / thisDet;
            result[j][i] = (i + j) & 1 ? -value : value;
        }

    return result;
}

#endif // __MATRIX_MATH_INL__