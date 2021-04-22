#ifndef __MATRIX_CONSTRUCT_INL__
#define __MATRIX_CONSTRUCT_INL__

#include <cstddef>
#include <initializer_list>

#include "matrix.hpp"

template <typename T>
Matrix<T>::Matrix(const size_t rows, const size_t cols) : MatrixBase(rows, cols)
{
    this->data = _allocateMemory(rows, cols);
}

template <typename T>
Matrix<T>::Matrix(const size_t rows, const size_t cols, const T &filler) : MatrixBase(rows, cols)
{
    this->data = _allocateMemory(rows, cols);
    for (size_t i = 0; i < rows; ++i)
        for (size_t j = 0; j < cols; ++j)
            this->data[i][j] = filler;
}

template <typename T>
Matrix<T>::Matrix(std::initializer_list<std::initializer_list<T>> initList) : MatrixBase(initList.size(), initList.size() ? initList.begin()->size() : 0)
{

    if (!this->_validInitList(initList, this->cols))
        throw InvalidArgument(__FILE__, __LINE__, "Receive bad initializer list for create matrix");

    this->data = _allocateMemory(rows, cols);

    size_t i = 0;
    for (const auto &row : initList)
        for (const auto &item : row)
        {
            this->data[i / cols][i % cols] = item;
            ++i;
        }
}

template <typename T>
Matrix<T>::Matrix(const Matrix &anotherM) : Matrix(anotherM.rows, anotherM.cols)
{
    for (size_t i = 0; i < this->rows; ++i)
        for (size_t j = 0; j < this->cols; ++j)
            this->data[i][j] = anotherM[i][j];
}

template <typename T>
Matrix<T>::Matrix(Matrix &&anotherM) : MatrixBase(anotherM.rows, anotherM.cols)
{
    this->data = anotherM.data;
}

#endif // __MATRIX_CONSTRUCT_INL__
