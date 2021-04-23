#ifndef __MATRIX_ITER_INL__
#define __MATRIX_ITER_INL__

#include "matrix.hpp"

template <typename T>
MatrixIterator<T> Matrix<T>::begin()
{
    return MatrixIterator<T>(this->data, this->rows, this->cols, 0);
}

template <typename T>
MatrixIterator<T> Matrix<T>::end()
{
    return MatrixIterator<T>(this->data, this->rows, this->cols, this->cols * this->rows);
}

template <typename T>
ConstMatrixIterator<T> Matrix<T>::begin() const
{
    return ConstMatrixIterator<T>(this->data, this->rows, this->cols, 0);
}

template <typename T>
ConstMatrixIterator<T> Matrix<T>::end() const
{
    return ConstMatrixIterator<T>(this->data, this->rows, this->cols, this->cols * this->rows);
}

template <typename T>
ConstMatrixIterator<T> Matrix<T>::cbegin() const
{
    return ConstMatrixIterator<T>(this->data, this->rows, this->cols, 0);
}

template <typename T>
ConstMatrixIterator<T> Matrix<T>::cend() const
{
    return ConstMatrixIterator<T>(this->data, this->rows, this->cols, this->cols * this->rows);
}

#endif // __MATRIX_ITER_INL__