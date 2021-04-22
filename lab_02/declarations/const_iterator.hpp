#ifndef __CONST_ITERATOR_HPP__
#define __CONST_ITERATOR_HPP__

#include <iterator>

#include "exceptions.hpp"

template <typename T>
class Matrix;

template <typename T>
class ConstIterator : public std::iterator<std::random_access_iterator_tag, T>
{
    friend Matrix<T>;

private:
    std::weak_ptr<typename Matrix<T>::MatrixRow[]> data = nullptr;
    size_t cols = 0;
    size_t rows = 0;
    size_t index = 0;

    ConstIterator(const std::shared_ptr<typename Matrix<T>::MatrixRow[]> &data, const size_t rows, const size_t cols, const size_t index)
        : data(data), index(index), rows(rows), cols(cols) {}

public:
    ConstIterator(const ConstIterator &it) = default;
    ConstIterator<T> &operator=(const ConstIterator<T> &it);

    bool operator==(ConstIterator const &other) const;
    bool operator!=(ConstIterator const &other) const;
    bool operator<(const ConstIterator<T> &other) const;
    bool operator<=(const ConstIterator<T> &other) const;
    bool operator>(const ConstIterator<T> &other) const;
    bool operator>=(const ConstIterator<T> &other) const;

    operator bool() const;
    bool isEnd() const;
    bool isBegin() const;
    bool isValid() const;

    ConstIterator<T> operator+(const int value) const;
    ConstIterator<T> operator-(const int value) const;
    int operator-(const ConstIterator<T> &it) const;

    const T &current() const;
    const T &operator*() const;
    const T *operator->() const;

    ConstIterator<T> operator++(int);
    const ConstIterator<T> &operator++();

    ConstIterator<T> operator--(int);
    const ConstIterator<T> &operator--();

    ConstIterator<T> &operator+=(const int value);
    ConstIterator<T> &operator-=(const int value);

    const T &operator[](const int value) const;
};

#include "const_iterator.inl"

#endif // __CONST_ITERATOR_HPP__