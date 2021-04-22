#ifndef __ITERATOR_INL__
#define __ITERATOR_INL__

#include "iterator.hpp"

template <typename T>
Iterator<T> &Iterator<T>::operator=(const Iterator<T> &it)
{
    this->data = it.data;
    this->index = it.index;
    this->rows = it.rows;
    this->cols = it.cols;
    return *this;
}

template <typename T>
Iterator<T> &Iterator<T>::operator++()
{
    if (this->index < this->cols * this->rows)
        ++this->index;
    return *this;
}

template <typename T>
Iterator<T> Iterator<T>::operator++(int)
{
    Iterator<T> it(*this);
    ++(*this);
    return it;
}

template <typename T>
Iterator<T> &Iterator<T>::operator--()
{
    if (this->index > 0)
        --this->index;
    return *this;
}

template <typename T>
Iterator<T> Iterator<T>::operator--(int)
{
    Iterator<T> it(*this);
    --(*this);
    return it;
}

template <typename T>
bool Iterator<T>::operator==(const Iterator &other) const
{
    return this->index == other.index;
}

template <typename T>
bool Iterator<T>::operator!=(const Iterator &other) const
{
    return !(*this == other);
}

template <typename T>
bool Iterator<T>::operator<(const Iterator<T> &other) const
{
    return this->index < other.index;
}

template <typename T>
bool Iterator<T>::operator>(const Iterator<T> &other) const
{
    return this->index > other.index;
}

template <typename T>
bool Iterator<T>::operator>=(const Iterator<T> &other) const
{
    return !(this->index < other.index);
}

template <typename T>
bool Iterator<T>::operator<=(const Iterator<T> &other) const
{
    return !(this->index > other.index);
}

template <typename T>
T &Iterator<T>::operator*() const
{
    if (!this->isValid())
        throw MemoryError(__FILE__, __LINE__, "Iterator points on nullptr");

    if (this->index >= this->rows * this->cols)
        throw IndexError(__FILE__, __LINE__, "Iterator doens't in data bounds, while executing const operator*");

    auto dataPtr = this->data.lock();
    return dataPtr[this->index / this->cols][this->index % this->cols];
}

template <typename T>
T &Iterator<T>::current() const
{
    return this->operator*();
}

template <typename T>
T *Iterator<T>::operator->() const
{
    if (!this->isValid())
        throw MemoryError(__FILE__, __LINE__, "Iterator points on nullptr");

    if (this->index >= this->rows * this->cols)
        throw IndexError(__FILE__, __LINE__, "Iterator doens't in data bounds, while executing const operator->");

    auto dataPtr = this->data.lock();
    return this->dataPtr[this->index / this->cols].getAddr() + (this->index % this->cols);
}

template <typename T>
bool Iterator<T>::isBegin() const
{
    return this->index == 0;
}

template <typename T>
bool Iterator<T>::isEnd() const
{
    return this->index == this->rows * this->cols;
}

template <typename T>
Iterator<T>::operator bool() const
{
    return !this->data.expired();
}

template <typename T>
bool Iterator<T>::isValid() const
{
    return bool(*this);
}

template <typename T>
Iterator<T> Iterator<T>::operator+(const int value) const
{
    Iterator<T> it(*this);

    if (value < 0 && it.index < static_cast<size_t>(-value))
        it.index = 0;
    else
        it.index += value;

    if (it.index > this->rows * this->cols)
        it.index = this->rows * this->cols;

    return it;
}

template <typename T>
Iterator<T> Iterator<T>::operator-(const int value) const
{
    return operator+(-value);
}

template <typename T>
int Iterator<T>::operator-(const Iterator<T> &it) const
{
    return static_cast<int>(this->index) - static_cast<int>(it.index);
}

template <typename T>
Iterator<T> operator+(const int value, const Iterator<T> &it)
{
    return it + value;
}

template <typename T>
Iterator<T> &Iterator<T>::operator+=(const int value)
{
    *this = *this + value;
    return *this;
}

template <typename T>
Iterator<T> &Iterator<T>::operator-=(const int value)
{
    *this = *this - value;
    return *this;
}

template <typename T>
T &Iterator<T>::operator[](const int value) const
{
    return *(*this + value);
}

template <typename T>
void Iterator<T>::swapWith(Iterator<T> &it)
{
    T tmp = **this;
    **this = *it;
    *it = tmp;
}

#endif // __ITERATOR_INL__