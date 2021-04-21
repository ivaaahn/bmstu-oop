#ifndef __MATRIX_INITS_INL__
#define __MATRIX_INITS_INL__

#include <cstddef>
#include <initializer_list>

#include "matrix.hpp"

template <typename T>
Matrix<T>::Matrix(const size_t rows, const size_t cols) : MatrixBase(rows, cols)
{
    this->data = allocMem(rows, cols);
}

template <typename T>
Matrix<T>::Matrix(const size_t rows, const size_t cols, const T &filler) : MatrixBase(rows, cols)
{
    this->data = allocMem(rows, cols);
    for (size_t i = 0; i < rows; ++i)
        for (size_t j = 0; j < cols; ++j)
            this->data[i][j] = filler;
}

template <typename T>
Matrix<T>::Matrix(std::initializer_list<std::initializer_list<T>> initList) :
MatrixBase(initList.size(), initList.size() ? initList.begin()->size() : 0)
{
    for (const auto &row : initList)
    {
        if (row.size() != cols)
        {
            time_t currT = time(NULL);
            auto localT = localtime(&currT);
            throw InvalidArgument(asctime(localT), __FILE__, __LINE__, "Bad initializer list");
        }
    }

    this->data = allocMem(rows, cols);
    this->rows = rows;
    this->cols = cols;

    size_t i = 0;
    for (const auto &row : initList)
    {
        for (const auto &item : row)
        {
            this->data[i / cols][i % cols] = item;
            ++i;
        }
    }
}

// TODO А надо ли вщ си-стайл делать???
// template<typename T>
// static void _checkPtr(T ptr)
// {
//     if (!ptr)
//     {
//         time_t currT = time(NULL);
//         auto currT = localtime(&currT);
//         throw InvalidArgument(asctime(currT), __FILE__, __LINE__, "nullptr as a ptr of c-matrix");
//     }
// }

// template <typename T>
// Matrix<T>::Matrix(const size_t rows, const size_t cols, T **matrix): MatrixBase(rows, columns) {
//     _checkPtr(matrix);
//     this->data = allocMem(rows, cols);
//     for (size_t i = 0; i < rows; ++i)
//     {
//         _checkPtr(matrix[i]);
//         for (size_t j = 0; j < cols; ++j)
//             this->data[i][j] = matrix[i][j];
//     }
// }

template <typename T>
Matrix<T>::Matrix(const Matrix &anotherM) : Matrix(anotherM.rows, anotherM.cols)
{
    std::cout << "Matrix(const Matrix &anotherM)" << std::endl;

    for (size_t i = 0; i < this->rows; ++i)
        for (size_t j = 0; j < this->cols; ++j)
            this->data[i][j] = anotherM[i][j];
}

template <typename T>
Matrix<T>::Matrix(Matrix &&anotherM) : MatrixBase(anotherM.rows, anotherM.cols)
{
    std::cout << "Matrix(const Matrix &&anotherM)" << std::endl;

    this->data = anotherM.data;
}


template <typename T>
void Matrix<T>::fill(Iterator<T> start, const Iterator<T> &end, const T &value)
{
    for (auto it = start; it != end; ++it)
        *it = value;
}

template <typename T>
void Matrix<T>::fill(Iterator<T> start, Iterator<T> source_start, const Iterator<T> &source_end)
{
    auto source_it = source_start;
    auto it = start;

    while (!it.isEnd() && source_it != source_end)
        *it++ = source_it++;
        // ++it, ++source_it;
}

template <typename T>
void Matrix<T>::fill(Iterator<T> start, ConstIterator<T> source_start, const ConstIterator<T> &source_end)
{
    auto source_it = source_start;
    auto it = start;
    
    while (!it.isEnd() && source_it != source_end)
        *it++ = *source_it++;
        // ++it, ++source_it;
}

#endif // __MATRIX_INITS_INL__