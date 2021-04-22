#ifndef __MATRIX_ROW_INL__
#define __MATRIX_ROW_INL__

#include <time.h>
#include "matrix.hpp"


template <typename T>
std::shared_ptr<typename Matrix<T>::MatrixRow[]> Matrix<T>::allocMem(const size_t rows, const size_t cols) 
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


template<typename T>
const T& Matrix<T>::MatrixRow::operator[](const size_t index) const
{
    if (index >= this->size)
        throw(IndexError(__FILE__, __LINE__, "Incorrect column"));

    return this->data[index];
}


template<typename T>
T& Matrix<T>::MatrixRow::operator[](const size_t index)
{
    if (index >= this->size) 
        throw(IndexError(__FILE__, __LINE__, "Incorrect column"));

    return this->data[index];
}

template<typename T>
void Matrix<T>::MatrixRow::reset()
{
    this->size = 0;
    this->data.reset();
}

template<typename T>
void Matrix<T>::MatrixRow::reset(T *data, const size_t size)
{
    this->size = size;
    this->data.reset(data);
}


#endif  // __MATRIX_ROW_INL__
