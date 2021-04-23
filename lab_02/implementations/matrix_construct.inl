#ifndef __MATRIX_CONSTRUCT_INL__
#define __MATRIX_CONSTRUCT_INL__

#include <cstddef>
#include <initializer_list>

#include "matrix.hpp"

template <typename T>
Matrix<T>::Matrix(const int rows, const int cols) : MatrixBase(cols ? rows : 0, rows ? cols : 0)
{
    if (rows < 0)
        throw(InvalidDimensions(__FILE__, __LINE__, "Matrix rows must not be negative."));

    if (cols < 0)
        throw(InvalidDimensions(__FILE__, __LINE__, "Matrix cols must not be negative."));

    this->data = _allocateData(*(this->rows), *(this->cols));
}

template <typename T>
Matrix<T>::Matrix(const int rows, const int cols, const T &filler) : Matrix(rows, cols)
{
    this->fill(this->begin(), this->end(), filler);
}

template <typename T>
Matrix<T>::Matrix(std::initializer_list<std::initializer_list<T>> lst) : Matrix(lst.size(), lst.size() ? lst.begin()->size() : 0)
{
    if (!this->_initListIsValid(lst, *(this->cols)))
        throw InvalidArgument(__FILE__, __LINE__, "Receive bad initializer list for create matrix");

    auto it = this->begin();

    for (const auto &row : lst)
        for (const auto &elem : row)
            *it++ = elem;
}

template <typename T>
Matrix<T>::Matrix(T **matrix, const int rows, const int cols): MatrixBase(rows, cols) 
{
    if (!matrix) 
        throw InvalidArgument(__FILE__, __LINE__, "nullptr as a ptr of c-matrix");

    this->data = _allocateData(rows, cols);

    for (size_t i = 0; i < rows; ++i)
    {
        if (!matrix) 
            throw InvalidArgument(__FILE__, __LINE__, "nullptr as a ptr of c-matrix");

        for (size_t j = 0; j < cols; ++j)
            this->data[i][j] = matrix[i][j];
    }
}

template <typename T>
Matrix<T>::Matrix(const Matrix &anotherM) : Matrix(*(anotherM.rows), *(anotherM.cols))
{
    this->fill(this->begin(), anotherM.begin(), anotherM.end());
}

template <typename T>
Matrix<T>::Matrix(Matrix &&anotherM) noexcept : MatrixBase(*(anotherM.rows), *(anotherM.cols))
{
    this->data = anotherM.data;
}

#endif // __MATRIX_CONSTRUCT_INL__
