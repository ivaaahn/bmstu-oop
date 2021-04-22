#ifndef __MATRIX_ACCESS_OPERATORS_INL__
#define __MATRIX_ACCESS_OPERATORS_INL__

#include "matrix.hpp"


template <typename T>
bool Matrix<T>::operator==(const Matrix &anotherM) const
{
    if (this->rows != anotherM.rows || this->cols != anotherM.cols)
        return false;

    bool equ = true;
    for (size_t i = 0; i < this->rows && equ; ++i)
        for (size_t j = 0; j < this->cols && equ; ++j)
            equ = (this->data[i][j] == anotherM[i][j]);
    
    return equ;
}

template <typename T>
bool Matrix<T>::operator!=(const Matrix &anotherM) const
{
    return !(*this==anotherM);
}

template <typename T>
typename Matrix<T>::MatrixRow Matrix<T>::operator[](const size_t row)
{
    if (row >= this->rows)
        throw IndexError(__FILE__, __LINE__, "Index out of bound of matrix dimensions");

    return this->data[row];
}

template <typename T>
const typename Matrix<T>::MatrixRow Matrix<T>::operator[](const size_t row) const
{
    if (row >= this->rows)
        throw IndexError(__FILE__, __LINE__, "Index out of bound of matrix dimensions");

    return this->data[row];
}

template <typename T>
T &Matrix<T>::operator()(const size_t row, const size_t col)
{
    if (row >= this->rows || col >= this->cols)
        throw IndexError(__FILE__, __LINE__, "Index out of bound of matrix dimensions");

    return this->data[row][col];
}

template <typename T>
T &Matrix<T>::at(const size_t row, const size_t col)
{
    if (row >= this->rows || col >= this->cols)
        throw IndexError(__FILE__, __LINE__, "Index out of bound of matrix dimensions");

    return this->data[row][col];
}

template <typename T>
const T &Matrix<T>::operator()(const size_t row, const size_t col) const
{
    if (row >= this->rows || col >= this->cols)
        throw IndexError(__FILE__, __LINE__, "Index out of bound of matrix dimensions");

    return this->data[row][col];
}

template <typename T>
const T &Matrix<T>::at(const size_t row, const size_t col) const
{
    if (row >= this->rows || col >= this->cols)
        throw IndexError(__FILE__, __LINE__, "Index out of bound of matrix dimensions");

    return this->data[row][col];
}


#endif  // __MATRIX_ACCESS_OPERATORS_INL__
