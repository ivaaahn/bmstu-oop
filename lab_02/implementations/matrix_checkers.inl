#ifndef __MATRIX_CHECKERS_INL__
#define __MATRIX_CHECKERS_INL__

#include "matrix.hpp"

template <typename T>
void Matrix<T>::_checkDimensionsEqu(const Matrix<T> &matrix) const 
{
    if (this->rows != matrix.rows || this->cols != matrix.cols) 
    {
        time_t currT = time(NULL);
        auto localT = localtime(&currT);
        throw IncompatibleElements(asctime(localT), __FILE__, __LINE__, "Different matrix dimensions");
    }
}

template <typename T>
void Matrix<T>::_checkDimensionsForMult(const Matrix<T> &matrix) const 
{
    if (this->cols != matrix.rows) 
    {
        time_t currT = time(NULL);
        auto localT = localtime(&currT);
        throw IncompatibleElements(asctime(localT), __FILE__, __LINE__,
                "Bad dimensions of matrices for multiplication");
    }
}

template <typename T>
void Matrix<T>::_checkIndexOutOfBound(const size_t pos, const size_t bound) const 
{
    if (pos > bound) 
    {
        time_t currT = time(NULL);
        auto localT = localtime(&currT);
        throw IndexError(asctime(localT), __FILE__, __LINE__, "Index out of bound matrix dimension");
    }
}


template <typename T>
std::shared_ptr<typename Matrix<T>::MatrixRow[]> Matrix<T>::allocMem(const size_t rows, const size_t cols) {
    std::shared_ptr<MatrixRow[]> data = nullptr;

    try 
    {
        data.reset(new MatrixRow[rows]);
    
        for (size_t i = 0; i < rows; i++)
            data[i].reset(new T[cols], cols);
    }
    catch (std::bad_alloc &err) 
    {
        time_t currT = time(NULL);
        auto localT = localtime(&currT);
        throw MemoryError(asctime(localT), __FILE__, __LINE__, "Memory allocation error [Matrix::allocMem()]");
    }

    return data;
}

#endif // __MATRIX_CHECKERS_INL__