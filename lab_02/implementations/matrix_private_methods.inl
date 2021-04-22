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
bool Matrix<T>::_validInitList(std::initializer_list<std::initializer_list<T>> initList, const size_t rowSize) const
{
    for (const auto &row : initList)
        if (row.size() != rowSize)
            return false;

    return true;
}

#endif // __MATRIX_PRIVATE_METHODS_INL__