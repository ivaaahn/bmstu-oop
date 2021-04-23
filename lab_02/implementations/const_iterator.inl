#ifndef __CONST_ITERATOR_INL__
#define __CONST_ITERATOR_INL__

#include "const_iterator.hpp"

template <typename T>
ConstMatrixIterator<T> &ConstMatrixIterator<T>::operator=(const ConstMatrixIterator<T> &it)
{
    this->data = it.data;
    this->index = it.index;
    this->rows = it.rows;
    this->cols = it.cols;
    return *this;
}

template <typename T>
const ConstMatrixIterator<T> &ConstMatrixIterator<T>::operator++()
{
    if (this->index < this->cols * this->rows)
        ++this->index;
    return *this;
}

template <typename T>
ConstMatrixIterator<T> ConstMatrixIterator<T>::operator++(int)
{
    ConstMatrixIterator<T> it(*this);
    ++(*this);
    return it;
}

template <typename T>
const ConstMatrixIterator<T> &ConstMatrixIterator<T>::operator--()
{
    if (this->index > 0)
        --this->index;
    return *this;
}

template <typename T>
ConstMatrixIterator<T> ConstMatrixIterator<T>::operator--(int)
{
    ConstMatrixIterator<T> it(*this);
    --(*this);
    return it;
}

template <typename T>
bool ConstMatrixIterator<T>::operator==(ConstMatrixIterator const &other) const
{
    return this->index == other.index;
}

template <typename T>
bool ConstMatrixIterator<T>::operator!=(ConstMatrixIterator const &other) const
{
    return !(*this == other);
}

template <typename T>
bool ConstMatrixIterator<T>::operator<(const ConstMatrixIterator<T> &other) const
{
    return this->index < other.index;
}

template <typename T>
bool ConstMatrixIterator<T>::operator>(const ConstMatrixIterator<T> &other) const
{
    return this->index > other.index;
}

template <typename T>
bool ConstMatrixIterator<T>::operator>=(const ConstMatrixIterator<T> &other) const
{
    return !(this->index < other.index);
}

template <typename T>
bool ConstMatrixIterator<T>::operator<=(const ConstMatrixIterator<T> &other) const
{
    return !(this->index > other.index);
}

template <typename T>
const T &ConstMatrixIterator<T>::operator*() const
{
    if (!isValid())
        throw MemoryError(__FILE__, __LINE__, "Iterator points on nullptr");

    if (this->index >= this->rows * this->cols)
        throw IndexError(__FILE__, __LINE__, "Iterator doens't in data bounds, while executing const operator*");

    auto dataPtr = this->data.lock();
    return dataPtr[this->index / this->cols][this->index % this->cols];
}

template <typename T>
const T &ConstMatrixIterator<T>::current() const
{
    return this->operator*();
}

template <typename T>
const T *ConstMatrixIterator<T>::operator->() const
{
    if (!isValid())
        throw MemoryError(__FILE__, __LINE__, "Iterator points on nullptr");

    if (this->index >= this->rows * this->cols)
        throw IndexError(__FILE__, __LINE__, "Iterator doens't in data bounds, while executing const operator->");

    auto dataPtr = this->data.lock();
    return dataPtr[this->index / this->cols].getAddr() + (this->index % this->cols);
}

template <typename T>
bool ConstMatrixIterator<T>::isBegin() const
{
    return this->index == 0;
}

template <typename T>
bool ConstMatrixIterator<T>::isEnd() const
{
    return this->index == this->rows * this->cols;
}

template <typename T>
ConstMatrixIterator<T>::operator bool() const
{
    return !this->data.expired();
}

template <typename T>
bool ConstMatrixIterator<T>::isValid() const
{
    return bool(*this);
}

template <typename T>
ConstMatrixIterator<T> ConstMatrixIterator<T>::operator+(const int value) const
{
    ConstMatrixIterator<T> it(*this);
    if (value < 0 && it.index < static_cast<size_t>(-value))
        it.index = 0;
    else
        it.index += value;

    if (it.index > this->rows * this->cols)
        it.index = this->rows * this->cols;

    return it;
}

template <typename T>
ConstMatrixIterator<T> ConstMatrixIterator<T>::operator-(const int value) const
{
    return operator+(-value);
}

template <typename T>
int ConstMatrixIterator<T>::operator-(const ConstMatrixIterator<T> &it) const
{
    return static_cast<int>(this->index) - static_cast<int>(it.index);
}

template <typename T>
ConstMatrixIterator<T> operator+(const int value, const ConstMatrixIterator<T> &it)
{
    return it + value;
}

template <typename T>
ConstMatrixIterator<T> &ConstMatrixIterator<T>::operator+=(const int value)
{
    *this = *this + value;
    return *this;
}

template <typename T>
ConstMatrixIterator<T> &ConstMatrixIterator<T>::operator-=(const int value)
{
    *this = *this - value;
    return *this;
}

template <typename T>
const T &ConstMatrixIterator<T>::operator[](const int value) const
{
    return *(*this + value);
}

#endif // __CONST_ITERATOR_INL__