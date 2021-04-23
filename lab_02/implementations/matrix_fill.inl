#ifndef __MATRIX_FILL_INL__
#define __MATRIX_FILL_INL__

#include <cstddef>
#include <initializer_list>

#include "matrix.hpp"

template <typename T>
void Matrix<T>::fill(MatrixIterator<T> start, const MatrixIterator<T> &end, const T &value)
{
    for (auto it = start; it != end; ++it)
        *it = value;
}

template <typename T>
template <typename AnyIterator>
void Matrix<T>::fill(MatrixIterator<T> start, AnyIterator source_start, const AnyIterator &source_end)
{
    auto source_it = source_start;
    auto it = start;

    while (!it.isEnd() && source_it != source_end)
        *it++ = *source_it++;
}

template <typename T>
Matrix<T> &Matrix<T>::zeros()
{
    this->fill(this->begin(), this->end());
    return *this;
}

template <typename T>
Matrix<T> &Matrix<T>::eye()
{
    for (size_t i = 0; i < *(this->rows); ++i)
        for (size_t j = 0; j < *(this->cols); ++j)
            this->data[i][j] = (i == j) ? 1 : 0;

    return *this;
}

#endif // __MATRIX_FILL_INL__
