#ifndef __CONST_ITERATOR_HPP__
#define __CONST_ITERATOR_HPP__

#include <iterator>

#include "exceptions.hpp"

template <typename T>
class Matrix;

template <typename T>
class ConstMatrixIterator : public std::iterator<std::random_access_iterator_tag, T>
{
    friend Matrix<T>;

public:
    ConstMatrixIterator(const ConstMatrixIterator &it) = default;
    ConstMatrixIterator<T> &operator=(const ConstMatrixIterator<T> &other);

    bool operator==(ConstMatrixIterator const &other) const;
    bool operator!=(ConstMatrixIterator const &other) const;
    bool operator<(const ConstMatrixIterator<T> &other) const;
    bool operator<=(const ConstMatrixIterator<T> &other) const;
    bool operator>(const ConstMatrixIterator<T> &other) const;
    bool operator>=(const ConstMatrixIterator<T> &other) const;

    operator bool() const;
    bool isEnd() const;
    bool isBegin() const;
    bool isValid() const;

    ConstMatrixIterator<T> operator+(const int value) const;
    ConstMatrixIterator<T> operator-(const int value) const;
    int operator-(const ConstMatrixIterator<T> &other) const;

    const T &current() const;
    const T &operator*() const;
    const T *operator->() const;

    ConstMatrixIterator<T> operator++(int);
    const ConstMatrixIterator<T> &operator++();

    ConstMatrixIterator<T> operator--(int);
    const ConstMatrixIterator<T> &operator--();

    ConstMatrixIterator<T> &operator+=(const int value);
    ConstMatrixIterator<T> &operator-=(const int value);

    const T &operator[](const int value) const;

private:
    std::weak_ptr<typename Matrix<T>::MatrixRow[]> data = nullptr;
    std::weak_ptr<size_t> rows = nullptr;
    std::weak_ptr<size_t> cols = nullptr;
    size_t index = 0;

    ConstMatrixIterator(const std::shared_ptr<typename Matrix<T>::MatrixRow[]> &data, const std::shared_ptr<size_t> &rows, const std::shared_ptr<size_t> &cols, const size_t index)
        : data(data), index(index), rows(rows), cols(cols) {}

};

#include "const_iterator.inl"

#endif // __CONST_ITERATOR_HPP__