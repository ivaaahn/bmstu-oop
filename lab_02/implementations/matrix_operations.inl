#ifndef __MATRIX_OPERATIONS_INL__
#define __MATRIX_OPERATIONS_INL__

#include "matrix.hpp"

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &anotherM) const
{
    if (!(this->rows == anotherM.rows && this->cols == anotherM.cols))
        throw(InvalidDimensions(__FILE__, __LINE__, "The dimensions of the matrices must be the same."));

    Matrix<T> resultM(this->rows, this->cols);

    for (size_t i = 0; i < this->rows; ++i)
        for (size_t j = 0; j < this->cols; ++j)
            resultM[i][j] = this->data[i][j] + anotherM[i][j];

    return resultM;
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const T &elem) const noexcept
{
    Matrix<T> resultM(this->rows, this->cols);

    for (size_t i = 0; i < this->rows; ++i)
        for (size_t j = 0; j < this->cols; ++j)
            resultM[i][j] = this->data[i][j] + elem;

    return resultM;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> &anotherM) const
{
    if (!(this->rows == anotherM.rows && this->cols == anotherM.cols))
        throw(InvalidDimensions(__FILE__, __LINE__, "The dimensions of the matrices must be the same."));

    Matrix<T> resultM(this->rows, this->cols);

    for (size_t i = 0; i < this->rows; ++i)
        for (size_t j = 0; j < this->cols; ++j)
            resultM[i][j] = this->data[i][j] - anotherM[i][j];

    return resultM;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const T &elem) const noexcept
{
    Matrix<T> resultM(this->rows, this->cols);

    for (size_t i = 0; i < this->rows; ++i)
        for (size_t j = 0; j < this->cols; ++j)
            resultM[i][j] = this->data[i][j] - elem;

    return resultM;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &anotherM) const
{
    if (this->cols != anotherM.rows)
        throw(InvalidDimensions(__FILE__, __LINE__, "The number of columns in the first"
                                                    "matrix must be equal to the number of rows in the second."));

    Matrix<T> resultM(this->rows, anotherM.cols, 0);

    for (size_t i = 0; i < this->rows; ++i)
        for (size_t j = 0; j < anotherM.cols; ++j)
            for (size_t k = 0; k < this->cols; ++k)
                resultM[i][j] += this->data[i][k] * anotherM[k][j];

    return resultM;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const T &elem) const noexcept
{
    Matrix<T> resultM(this->rows, this->cols);

    for (size_t i = 0; i < this->rows; ++i)
        for (size_t j = 0; j < this->cols; ++j)
            resultM[i][j] = this->data[i][j] * elem;

    return resultM;
}


template <typename T>
Matrix<T> Matrix<T>::operator/(const Matrix &anotherM) const
{
    Matrix<T> resultM(anotherM);
    return *this * resultM.inverse();
}

template <typename T>
Matrix<T> Matrix<T>::operator/(const T &elem) const
{
    if (!elem) throw InvalidArgument(__FILE__, __LINE__, "Zero divisor");

    Matrix<T> resultM(this->rows, this->cols);

    for (size_t i = 0; i < this->rows; ++i)
        for (size_t j = 0; j < this->cols; ++j)
            resultM[i][j] = this->data[i][j] / elem;

    return resultM;
}


template <typename T>
Matrix<T> &Matrix<T>::operator+=(const Matrix &anotherM)
{
    if (!(this->rows == anotherM.rows && this->cols == anotherM.cols))
        throw(InvalidDimensions(__FILE__, __LINE__, "The dimensions of the matrices must be the same."));

    for (size_t i = 0; i < this->rows; ++i)
        for (size_t j = 0; j < this->cols; ++j)
            this->data[i][j] += anotherM[i][j];

    return *this;
}

template <typename T>
Matrix<T> &Matrix<T>::operator+=(const T &elem) noexcept
{
    for (auto &oldElement : *this)
        oldElement += elem;

    return *this;
}

template <typename T>
Matrix<T> &Matrix<T>::operator-=(const Matrix &anotherM)
{
    if (!(this->rows == anotherM.rows && this->cols == anotherM.cols))
        throw(InvalidDimensions(__FILE__, __LINE__, "The dimensions of the matrices must be the same."));

    for (size_t i = 0; i < this->rows; ++i)
        for (size_t j = 0; j < this->cols; ++j)
            this->data[i][j] -= anotherM[i][j];

    return *this;
}

template <typename T>
Matrix<T> &Matrix<T>::operator-=(const T &elem) noexcept
{
    for (auto &oldElement : *this)
        oldElement -= elem;

    return *this;
}

template <typename T>
Matrix<T> &Matrix<T>::operator*=(const Matrix &anotherM)
{
    *this = *this * anotherM;
    return *this;
}

template <typename T>
Matrix<T> &Matrix<T>::operator*=(const T &elem) noexcept
{
    *this = *this * elem;
    return *this;
}


template <typename T>
Matrix<T> &Matrix<T>::operator/=(const T &elem)
{
    if (!elem) throw InvalidArgument(__FILE__, __LINE__, "Zero divisor");

    for (size_t i = 0; i < this->rows; ++i)
        for (size_t j = 0; j < this->cols; ++j)
            this->data[i][j] /= elem;

    return *this;
}

template <typename T>
Matrix<T> &Matrix<T>::operator/=(const Matrix &anotherM)
{
    *this = *this / anotherM;
    return *this;
}


template <typename T>
Matrix<T> Matrix<T>::operator-() const
{
    Matrix<T> resultM(this->rows, this->cols);

    for (size_t i = 0; i < this->rows; ++i)
        for (size_t j = 0; j < this->cols; ++j)
            resultM[i][j] = -this->data[i][j];

    return resultM;
}


template <typename T>
Matrix<T> Matrix<T>::addMatr(const Matrix &anotherM) const
{
    return *this + anotherM;
}

template <typename T>
Matrix<T> Matrix<T>::addElem(const T &elem) const noexcept
{
    return *this + elem;
}

template <typename T>
Matrix<T> Matrix<T>::subMatr(const Matrix &anotherM) const
{
    return *this - anotherM;
}

template <typename T>
Matrix<T> Matrix<T>::subElem(const T &elem) const noexcept
{
    return *this - elem;
}


template <typename T>
Matrix<T> Matrix<T>::mulMatr(const Matrix &anotherM) const
{
    return *this * anotherM;
}


template <typename T>
Matrix<T> Matrix<T>::mulElem(const T &elem) const noexcept
{
    return *this * elem;
}


template <typename T>
Matrix<T> Matrix<T>::divMatr(const Matrix &anotherM) const
{
    return *this / anotherM;
}


template <typename T>
Matrix<T> Matrix<T>::divElem(const T &elem) const
{
    return *this / elem;
}



template <typename T>
Matrix<T> &Matrix<T>::addEqMatrix(const Matrix &anotherM)
{
    return *this += anotherM;
}

template <typename T>
Matrix<T> &Matrix<T>::addEqElem(const T &elem) noexcept
{
    return *this += elem;
}



template <typename T>
Matrix<T> &Matrix<T>::subEqMatrix(const Matrix &anotherM)
{
    return *this -= anotherM;
}


template <typename T>
Matrix<T> &Matrix<T>::subEqElem(const T &elem) noexcept
{
    return *this -= elem;
}


template <typename T>
Matrix<T> &Matrix<T>::mulEqMatrix(const Matrix &anotherM)
{
    return *this *= anotherM;
}

template <typename T>
Matrix<T> &Matrix<T>::mulEqElem(const T &elem) noexcept
{
    return *this *= elem;
}


template <typename T>
Matrix<T> &Matrix<T>::divEqElem(const T &elem)
{
    return *this /= elem;

}


template <typename T>
Matrix<T> &Matrix<T>::divEqMatrix(const Matrix &anotherM)
{
    return *this /= anotherM;
}


template <typename T>
Matrix<T> Matrix<T>::neg() const 
{
    return -*this();
}

template <typename T>
Matrix<T> operator+(const T &elem, const Matrix<T> &matrix)
{
    return matrix + elem;
}

template <typename T>
Matrix<T> operator-(const T &elem, const Matrix<T> &matrix)
{
    return -matrix + elem;
}

template <typename T>
Matrix<T> operator*(const T &elem, const Matrix<T> &matrix)
{
    return matrix * elem;
}

template <typename T>
Matrix<T> operator/(const T &elem, const Matrix<T> &matrix)
{
    Matrix<T> resultM(matrix);
    return resultM.inverse() * elem;
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const Matrix<T> &matrix)
{
    for (size_t i = 0; i < matrix.getRows(); ++i)
    {
        for (size_t j = 0; j < matrix.getColumns(); ++j)
            out << matrix[i][j] << '\t';

        out << '\n';
    }

    return out;
}


// TODO добавить деление и унарные

#endif // __MATRIX_OPERATIONS_INL__