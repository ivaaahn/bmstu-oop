#ifndef __MATRIX_ASSIGN_OPERATORS_INL__
#define __MATRIX_ASSIGN_OPERATORS_INL__

#include "matrix.hpp"


template <typename T>
Matrix<T> &Matrix<T>::operator=(const Matrix &anotherM)
{
    std::cout << "operator=(const Matrix &anotherM)" << std::endl;

    if (this == &anotherM)
        return *this;

    this->data = allocMem(anotherM.rows, anotherM.cols);
    this->rows = anotherM.rows, this->cols = anotherM.cols;

    for (size_t i = 0; i < this->rows; ++i)
        for (size_t j = 0; j < this->cols; ++j)
            this->data[i][j] = anotherM[i][j];
    return *this;
}

template <typename T>
Matrix<T> &Matrix<T>::operator=(Matrix &&anotherM)
{
    std::cout << "operator=(const Matrix &&anotherM)" << std::endl;

    if (this == &anotherM)
        return *this;

    this->data = anotherM.data;
    this->rows = anotherM.rows, this->cols = anotherM.cols;
    return *this;
}

template <typename T>
Matrix<T> &Matrix<T>::operator=(std::initializer_list<std::initializer_list<T>> initList)
{
    std::cout << "operator=(std::initializer_list<std::initializer_list<T>> initList)" << std::endl;

    size_t rows = initList.size();
    size_t cols = initList.size() ? initList.begin()->size() : 0;
    
    for (const auto &row : initList)
    {
        if (row.size() != cols)
        {
            time_t currT = time(NULL);
            auto localT = localtime(&currT);
            throw InvalidArgument(asctime(localT), __FILE__, __LINE__, "Bad initializer list");
        }
    }

    this->resize(rows, cols);
    size_t i = 0;
    for (const auto &row : initList)
    {
        for (const auto &item : row)
        {
            this->data[i / cols][i % cols] = item;
            ++i;
        }
    }

    return *this;
}


#endif  // __MATRIX_ASSIGN_OPERATORS_INL__