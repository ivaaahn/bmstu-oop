#ifndef __CONST_ITERATOR_INL__
#define __CONST_ITERATOR_INL__ 

#include "const_iterator.hpp"

template <typename T>
using SharedPtrOnRow = std::shared_ptr<typename Matrix<T>::MatrixRow[]>;


template <typename T>
const ConstIterator<T>& ConstIterator<T>::operator++() const 
{
    if (this->index < this->cols * this->rows)
        ++this->index;
    return *this;
}

template <typename T>
ConstIterator<T> ConstIterator<T>::operator++(int) const 
{
    ConstIterator<T> it(*this);
    ++(*this);
    return it;
}

template <typename T>
ConstIterator<T>& ConstIterator<T>::next() const 
{
    return this->operator++();
}


template <typename T>
const ConstIterator<T>& ConstIterator<T>::operator--() const 
{
    if (this->index > 0)
        --this->index;
    return *this;
}

template <typename T>
ConstIterator<T> ConstIterator<T>::operator--(int) const 
{
    ConstIterator<T> it(*this);
    --(*this);
    return it;
}

template <typename T>
ConstIterator<T>& ConstIterator<T>::prev() const 
{
    return this->operator--();
}


template <typename T>
bool ConstIterator<T>::operator!=(ConstIterator const &other) const 
{
    return this->index != other.index;
}

template <typename T>
bool ConstIterator<T>::operator==(ConstIterator const &other) const 
{
    return this->index == other.index;
}


template <typename T>
const T& ConstIterator<T>::operator*() const {
    checkValid("Iterator points on nullptr");
    _checkIndex("ConstIterator doens't in data bounds, while executing const operator*");

    SharedPtrOnRow<T> dataPtr = this->data.lock();
    return dataPtr[this->index / this->cols][this->index % this->cols];
}

template <typename T>
const T& ConstIterator<T>::current() const 
{
    return this->operator*();
}

template <typename T>
const T* ConstIterator<T>::operator->() const 
{
    checkValid("Iterator points on nullptr");
    _checkIndex("ConstIterator doens't in data bounds, while executing const operator->");
    std::shared_ptr<typename Matrix<T>::MatrixRow[]> dataPtr = this->data.lock();
    return dataPtr[this->index / this->cols].getAddr() + (this->index % this->cols);
}


template <typename T>
void ConstIterator<T>::_checkIndex(const string hint) const 
{
    if (this->index >= this->rows * this->cols)
    {
        time_t cur_time = time(NULL);
        auto local_time = localtime(&cur_time);
        throw IndexError(asctime(local_time), __FILE__, __LINE__, hint);
    }
}

template <typename T>
void ConstIterator<T>::checkValid(const string hint) const
{
    if (!isValid()) 
    {
        time_t cur_time = time(NULL);
        auto local_time = localtime(&cur_time);
        throw MemoryError(asctime(local_time), __FILE__, __LINE__, hint);
    }
}

template <typename T>
bool ConstIterator<T>::isBegin() const 
{
    return this->index == 0;
}

template <typename T>
bool ConstIterator<T>::isEnd() const 
{
    return this->index == this->rows * this->cols;
}


template <typename T>
ConstIterator<T>::operator bool() const 
{
    return !this->data.expired();
}

template <typename T>
bool ConstIterator<T>::isValid() const 
{
    return bool(*this);
}

template <typename T>
ConstIterator<T> ConstIterator<T>::operator+(const int value) const 
{
    ConstIterator<T> it(*this);
    if (value < 0 && it.index < static_cast<size_t>(-value))
        it.index = 0;
    else
        it.index += value;

    if (it.index > this->rows * this->cols)
        it.index = this->rows * this->cols;

    return it;
}

template <typename T>
ConstIterator<T> ConstIterator<T>::operator-(const int value) const 
{
    return operator+(-value);
}

template <typename T>
ConstIterator<T> &ConstIterator<T>::operator+=(const int value) const 
{
    this->index += value;
    return *this;
}

#endif  // __CONST_ITERATOR_INL__