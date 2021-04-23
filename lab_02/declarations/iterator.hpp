#ifndef __ITERATOR_HPP__
#define __ITERATOR_HPP__

#include <iterator>

template <typename T>
class Matrix;

template <typename T>
class MatrixIterator : public std::iterator<std::random_access_iterator_tag, T>
{
    friend Matrix<T>;

private:
    std::weak_ptr<typename Matrix<T>::MatrixRow[]> data = nullptr;
    size_t cols = 0;
    size_t rows = 0;
    size_t index = 0;

    MatrixIterator(const std::shared_ptr<typename Matrix<T>::MatrixRow[]> &data, const size_t rows, const size_t cols, const size_t index)
        : data(data), index(index), rows(rows), cols(cols) {}

public:
    MatrixIterator(const MatrixIterator &it) = default;
    MatrixIterator<T> &operator=(const MatrixIterator<T> &other);

    bool operator==(const MatrixIterator<T> &other) const;
    bool operator!=(const MatrixIterator<T> &other) const;
    bool operator<(const MatrixIterator<T> &other) const;
    bool operator<=(const MatrixIterator<T> &other) const;
    bool operator>(const MatrixIterator<T> &other) const;
    bool operator>=(const MatrixIterator<T> &other) const;

    operator bool() const;
    bool isBegin() const;
    bool isEnd() const;
    bool isValid() const;

    MatrixIterator<T> operator+(const int value) const;
    MatrixIterator<T> operator-(const int value) const;
    int operator-(const MatrixIterator<T> &other) const;

    T &current() const;
    T &operator*() const;
    T *operator->() const;

    MatrixIterator<T> operator++(int);
    MatrixIterator<T> &operator++();

    MatrixIterator<T> operator--(int);
    MatrixIterator<T> &operator--();

    MatrixIterator<T> &operator+=(const int value);
    MatrixIterator<T> &operator-=(const int value);

    T &operator[](const int value) const;

    void swapWith(MatrixIterator<T> &other);
};

#include "iterator.inl"

#endif // __ITERATOR_HPP__