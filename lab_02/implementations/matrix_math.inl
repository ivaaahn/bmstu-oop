#ifndef __MATRIX_MATH_INL__
#define __MATRIX_MATH_INL__

#include "matrix.hpp"

template <typename T>
static void _excludeAndCopy(Matrix<T> &dest, const Matrix<T> &src, size_t exRow, size_t exCol)
{
    if (dest.getRows() != src.getRows() - 1 || dest.getColumns() != src.getColumns() - 1)
    {
        time_t currT = time(NULL);
        auto localT = localtime(&currT);
        throw IncompatibleElements(asctime(localT), __FILE__, __LINE__, "Destination has wrong size");
    }

    size_t rowIndex, colIndex;
    for (size_t i = 0; i < src.getRows() - 1; ++i)
        for (size_t j = 0; j < src.getColumns() - 1; ++j)
        {
            rowIndex = i >= exRow ? i + 1 : i;
            colIndex = j >= exCol ? j + 1 : j;
            dest[i][j] = src[rowIndex][colIndex];
        }
}

template <typename T>
static T _determinant(const Matrix<T> &matrix)
{
    size_t rows = matrix.getRows(), cols = matrix.getColumns();

    if (rows == 2) return matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];

    if (rows == 1) return matrix[0][0];

    Matrix<T> tmp(rows - 1, cols - 1);

    T result = {};
    for (size_t j = 0; j < cols; ++j)
    {
        _excludeAndCopy(tmp, matrix, 0, j);
        T minor = _determinant(tmp);
        result += j & 1 ? -matrix[0][j] * minor : matrix[0][j] * minor;
    }

    return result;
}

template <typename T>
void Matrix<T>::transpose()
{
    auto tempData = this->allocMem(this->cols, this->rows);

    for (size_t i = 0; i < this->rows; ++i)
        for (size_t j = 0; j < this->cols; ++j)
            tempData[j][i] = this->data[i][j];

    this->data = tempData;
    std::swap(this->rows, this->cols);
}

template <typename T>
T Matrix<T>::determinant() const
{
    if (!*this) return 1;

    if (!this->isSquare())
    {
        time_t currT = time(NULL);
        auto localT = localtime(&currT);
        throw InvalidState(asctime(localT), __FILE__, __LINE__, "Matrix should be square to get determinant;");
    }

    return _determinant(*this);
}

template <typename T>
Matrix<T>& Matrix<T>::inverse()
{
    T thisDet = this->determinant();

    if (!this->isSquare() || !thisDet)
    {
        time_t currT = time(NULL);
        auto localT = localtime(&currT);
        throw InvalidState(asctime(localT), __FILE__, __LINE__, "Only square matrix can be inversed and determinant should be != 0");
    }

    Matrix<T> result(this->rows, this->cols);
    Matrix<T> tmp(this->rows - 1, this->cols - 1);
    T value = {};

    for (size_t i = 0; i < this->rows; ++i)
        for (size_t j = 0; j < this->cols; ++j)
        {
            _excludeAndCopy(tmp, *this, i, j);
            value = tmp.determinant() / thisDet;

            //! [j][i] => Transpose right here!
            result[j][i] = (i + j) & 1 ? -value : value;
        }

    *this = result;

    return *this;
}

#endif // __MATRIX_MATH_INL__