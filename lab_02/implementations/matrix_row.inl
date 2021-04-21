#ifndef __MATRIX_ROW_INL__
#define __MATRIX_ROW_INL__

#include <time.h>
#include "matrix.hpp"

template<typename T>
const T& Matrix<T>::MatrixRow::operator[](const size_t index) const
{
    if (index >= this->size)
    {
        time_t currTime = time(NULL);
        auto localTime = localtime(&currTime);
        throw(IndexError(asctime(localTime), __FILE__, __LINE__, "Incorrect column"));
    }

    return this->data[index];
}

        
template<typename T>
T& Matrix<T>::MatrixRow::operator[](const size_t index)
{
    if (index >= this->size) 
    {
        time_t currTime = time(NULL);
        auto localTime = localtime(&currTime);
        throw(IndexError(asctime(localTime), __FILE__, __LINE__, "Incorrect column"));
    }

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
