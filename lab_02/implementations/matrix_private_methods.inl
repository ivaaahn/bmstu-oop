#ifndef __MATRIX_PRIVATE_METHODS_INL__
#define __MATRIX_PRIVATE_METHODS_INL__

#include "matrix.hpp"

template <typename T>
std::shared_ptr<typename Matrix<T>::MatrixRow[]> Matrix<T>::_allocateMemory(const size_t rows, const size_t cols)
{
    std::shared_ptr<MatrixRow[]> data = nullptr;

    try
    {
        data.reset(new MatrixRow[rows]);
        for (size_t i = 0; i < rows; i++)
            data[i].reset(new T[cols], cols);
    }
    catch (std::bad_alloc &err)
    {
        throw MemoryError(__FILE__, __LINE__, "Memory allocation error");
    }

    return data;
}

template <typename T>
bool Matrix<T>::_initListIsValid(std::initializer_list<std::initializer_list<T>> initList, const size_t rowSize) const
{
    for (const auto &row : initList)
        if (row.size() != rowSize)
            return false;

    return true;
}

template <typename T>
void Matrix<T>::_moveRow(const size_t from, const size_t to)
{
    auto tmp = this->data[from];

    for (size_t i = from; i > to; --i)
        this->data[i] = this->data[i - 1];

    for (size_t i = from; i < to; ++i)
        this->data[i] = this->data[i + 1];

    this->data[to] = tmp;
}

template <typename T>
void Matrix<T>::_moveCol(const size_t from, const size_t to)
{
    for (size_t j = 0; j < this->rows; ++j)
    {
        auto tmp = this->data[j][from];

        for (size_t i = from; i > to; --i)
            this->data[j][i] = this->data[j][i - 1];

        for (size_t i = from; i < to; ++i)
            this->data[j][i] = this->data[j][i + 1];

        this->data[j][to] = tmp;
    }
}

#endif // __MATRIX_PRIVATE_METHODS_INL__