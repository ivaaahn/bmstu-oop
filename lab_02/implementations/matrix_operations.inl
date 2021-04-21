#ifndef __MATRIX_OPERATIONS_INL__
#define __MATRIX_OPERATIONS_INL__

#include "matrix.hpp"

// TODO: Вынести перегрузку бинарных операций в функции

template <typename T>
bool Matrix<T>::operator==(const Matrix &anotherM) const
{
    if (this->rows != anotherM.rows || this->cols != anotherM.cols)
        return false;

    bool equ = true;
    for (size_t i = 0; i < this->rows && equ; ++i)
        for (size_t j = 0; j < this->cols && equ; ++j)
            equ = (this->data[i][j] == anotherM[i][j]);
    
    return equ;
}

template <typename T>
bool Matrix<T>::operator!=(const Matrix &anotherM) const
{
    return !operator==(anotherM);
}

// TODO: Надо же чекать выход за границы по идее!!!

template <typename T>
typename Matrix<T>::MatrixRow Matrix<T>::operator[](const size_t row)
{
    return this->data[row];
}

template <typename T>
const typename Matrix<T>::MatrixRow Matrix<T>::operator[](const size_t row) const
{
    return this->data[row];
}

template <typename T>
T &Matrix<T>::operator()(const size_t row, const size_t col)
{
    return this->data[row][col];
}

template <typename T>
T &Matrix<T>::at(const size_t row, const size_t col)
{
    return this->data[row][col];
}

template <typename T>
const T &Matrix<T>::operator()(const size_t row, const size_t col) const
{
    return this->data[row][col];
}

template <typename T>
const T &Matrix<T>::at(const size_t row, const size_t col) const
{
    return this->data[row][col];
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &anotherM) const
{
    this->_checkDimensionsEqu(anotherM);

    Matrix<T> resultM(this->rows, this->cols);

    for (size_t i = 0; i < this->rows; ++i)
        for (size_t j = 0; j < this->cols; ++j)
            resultM[i][j] = this->data[i][j] + anotherM[i][j];

    return resultM;
}

template <typename T>
Matrix<T> Matrix<T>::addMatr(const Matrix &anotherM) const
{
    return operator+(anotherM);
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> &anotherM) const
{
    this->_checkDimensionsEqu(anotherM);

    Matrix<T> resultM(this->rows, this->cols);

    for (size_t i = 0; i < this->rows; ++i)
        for (size_t j = 0; j < this->cols; ++j)
            resultM[i][j] = this->data[i][j] - anotherM[i][j];

    return resultM;
}

template <typename T>
Matrix<T> Matrix<T>::subMatr(const Matrix &anotherM) const
{
    return operator-(anotherM);
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &anotherM) const
{
    this->_checkDimensionsForMult(anotherM);

    Matrix<T> resultM(this->rows, anotherM.cols);

    for (size_t i = 0; i < this->rows; ++i)
        for (size_t j = 0; j < anotherM.cols; ++j)
            for (size_t k = 0; k < this->cols; ++k)
                resultM[i][j] += this->data[i][k] * anotherM[k][j];

    return resultM;
}

template <typename T>
Matrix<T> Matrix<T>::mulMatr(const Matrix &anotherM) const
{
    return operator*(anotherM);
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
Matrix<T> Matrix<T>::addElem(const T &elem) const noexcept
{
    return operator+(elem);
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
Matrix<T> Matrix<T>::subElem(const T &elem) const noexcept
{
    return operator-(elem);
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
Matrix<T> Matrix<T>::mulElem(const T &elem) const noexcept
{
    return operator*(elem);
}

template <typename T>
Matrix<T> &Matrix<T>::operator+=(const Matrix &anotherM)
{
    this->_checkDimensionsEqu(anotherM);

    for (size_t i = 0; i < this->rows; ++i)
        for (size_t j = 0; j < this->cols; ++j)
            this->data[i][j] += anotherM[i][j];

    return *this;
}

template <typename T>
Matrix<T> &Matrix<T>::addEqMatrix(const Matrix &anotherM)
{
    return operator+=(anotherM);
}

template <typename T>
Matrix<T> &Matrix<T>::operator-=(const Matrix &anotherM)
{
    this->_checkDimensionsEqu(anotherM);

    for (size_t i = 0; i < this->rows; ++i)
        for (size_t j = 0; j < this->cols; ++j)
            this->data[i][j] -= anotherM[i][j];

    return *this;
}

template <typename T>
Matrix<T> &Matrix<T>::subEqMatrix(const Matrix &anotherM)
{
    return operator-=(anotherM);
}

template <typename T>
Matrix<T> &Matrix<T>::operator*=(const Matrix &anotherM)
{
    this->_checkDimensionsEqu(anotherM);
    this->_checkDimensionsForMult(anotherM);

    Matrix<T> resultM(this->rows, this->cols);

    for (size_t i = 0; i < this->rows; ++i)
        for (size_t j = 0; j < this->cols; ++j)
            for (size_t k = 0; k < this->rows; ++k)
                resultM[i][j] += this->data[i][k] + anotherM[k][j];

    *this = resultM;
    return *this;
}

template <typename T>
Matrix<T> &Matrix<T>::mulEqMatrix(const Matrix &anotherM)
{
    return operator*=(anotherM);
}

template <typename T>
Matrix<T> &Matrix<T>::operator+=(const T &elem) noexcept
{
    for (auto &oldElement : *this)
        oldElement += elem;

    return *this;
}

template <typename T>
Matrix<T> &Matrix<T>::addEqElem(const T &elem) noexcept
{
    return operator+=(elem);
}

template <typename T>
Matrix<T> &Matrix<T>::operator-=(const T &elem) noexcept
{
    for (auto &oldElement : *this)
        oldElement -= elem;

    return *this;
}

template <typename T>
Matrix<T> &Matrix<T>::subEqElem(const T &elem) noexcept
{
    return operator-=(elem);
}

template <typename T>
Matrix<T> &Matrix<T>::operator*=(const T &elem) noexcept
{
    for (auto &oldElement : *this)
        oldElement *= elem;

    return *this;
}

template <typename T>
Matrix<T> &Matrix<T>::mulEqElem(const T &elem) noexcept
{
    return operator*=(elem);
}

template <typename T>
Matrix<T> &Matrix<T>::operator/=(const T &elem)
{
    if (elem == 0)
    {
        time_t currT = time(NULL);
        auto locT = localtime(&currT);
        throw InvalidArgument(asctime(locT), __FILE__, __LINE__, "Zero divisor");
    }

    for (size_t i = 0; i < this->rows; ++i)
        for (size_t j = 0; j < this->cols; ++j)
            this->data[i][j] /= elem;

    return *this;
}

template <typename T>
Matrix<T> &Matrix<T>::divEqElem(const T &elem)
{
    return operator/=(elem);
}

template <typename T>
Matrix<T> Matrix<T>::operator/(const T &elem) const
{
    if (elem == 0)
    {
        time_t currT = time(NULL);
        auto locT = localtime(&currT);
        throw InvalidArgument(asctime(locT), __FILE__, __LINE__, "Zero divisor");
    }

    Matrix<T> resultM(this->rows, this->cols);

    for (size_t i = 0; i < this->rows; ++i)
        for (size_t j = 0; j < this->cols; ++j)
            resultM[i][j] = this->data[i][j] / elem;

    return resultM;
}

template <typename T>
Matrix<T> Matrix<T>::divElem(const T &elem) const
{
    return operator/(elem);
}

template <typename T>
Matrix<T> Matrix<T>::operator/(const Matrix &anotherM) const
{
    Matrix<T> resultM(anotherM);

    resultM.inverse();
    return operator*(resultM);
}

template <typename T>
Matrix<T> Matrix<T>::divMatr(const Matrix &anotherM) const
{
    return operator/(anotherM);
}

template <typename T>
Matrix<T> &Matrix<T>::operator/=(const Matrix &anotherM)
{
    Matrix<T> resultM = operator/(anotherM);
    *this = resultM;
    return *this;
}

template <typename T>
Matrix<T> &Matrix<T>::divEqMatrix(const Matrix &anotherM)
{
    return operator/=(anotherM);
}

template <typename T>
Matrix<T> Matrix<T>::operator-()
{
    Matrix<T> resultM(this->rows, this->cols);

    for (size_t i = 0; i < this->rows; ++i)
        for (size_t j = 0; j < this->cols; ++j)
            resultM[i][j] = -this->data[i][j];

    return resultM;
}

template <typename T>
Matrix<T> Matrix<T>::neg()
{
    return operator-();
}

template <typename T>
Matrix<T> operator+(const T &elem, const Matrix<T> &matrix)
{
    return matrix + elem;
}

// TODO: ошибка ващето мб?
template <typename T>
Matrix<T> operator-(const T &elem, const Matrix<T> &matrix)
{
    return matrix - elem;
}

template <typename T>
Matrix<T> operator*(const T &elem, const Matrix<T> &matrix)
{
    return matrix * elem;
}

// TODO: ошибка ващето мб?
template <typename T>
Matrix<T> operator/(const T &elem, const Matrix<T> &matrix)
{
    Matrix<T> resultM(matrix);
    resultM.inverse();
    return resultM * elem;
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

#endif // __MATRIX_OPERATIONS_INL__