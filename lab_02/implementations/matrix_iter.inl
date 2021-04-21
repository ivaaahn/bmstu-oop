#ifndef __MATRIX_ITER_INL__
#define __MATRIX_ITER_INL__

#include "matrix.hpp"


template <typename T>
Iterator<T> Matrix<T>::begin()
{
    return Iterator<T>(this->data, this->rows, this->cols, 0);
}

template <typename T>
Iterator<T> Matrix<T>::end()
{
    return Iterator<T>(this->data, this->rows, this->cols, this->cols * this->rows);
}


// TODO: А надо ли???
template <typename T>
ConstIterator<T> Matrix<T>::begin() const
{
    return ConstIterator<T>(this->data, this->rows, this->cols, 0);
}

template <typename T>
ConstIterator<T> Matrix<T>::end() const
{
    return ConstIterator<T>(this->data, this->rows, this->cols, this->cols * this->rows);
}

template <typename T>
ConstIterator<T> Matrix<T>::cbegin() const
{
    return ConstIterator<T>(this->data, this->rows, this->cols, 0);
}

template <typename T>
ConstIterator<T> Matrix<T>::cend() const
{
    return ConstIterator<T>(this->data, this->rows, this->cols, this->cols * this->rows);
}

#endif // __MATRIX_ITER_INL__