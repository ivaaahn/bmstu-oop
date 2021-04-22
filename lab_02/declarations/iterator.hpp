#ifndef __ITERATOR_HPP__
#define __ITERATOR_HPP__

#include <iterator>

template <typename T>
class Matrix;

template <typename T>
class Iterator : public std::iterator<std::random_access_iterator_tag, T>
{
    friend Matrix<T>;

private:
    std::weak_ptr<typename Matrix<T>::MatrixRow[]> data = nullptr;
    size_t cols = 0;
    size_t rows = 0;
    size_t index = 0;

    Iterator(const std::shared_ptr<typename Matrix<T>::MatrixRow[]> &data, const size_t rows, const size_t cols, const size_t index)
        : data(data), index(index), rows(rows), cols(cols) {}

public:
    Iterator(const Iterator &it) = default;
    Iterator<T> &operator=(const Iterator<T> &it);

    bool operator==(const Iterator<T> &other) const;
    bool operator!=(const Iterator<T> &other) const;
    bool operator<(const Iterator<T> &other) const;
    bool operator<=(const Iterator<T> &other) const;
    bool operator>(const Iterator<T> &other) const;
    bool operator>=(const Iterator<T> &other) const;

    operator bool() const;
    bool isBegin() const;
    bool isEnd() const;
    bool isValid() const;

    Iterator<T> operator+(const int value) const;
    Iterator<T> operator-(const int value) const;
    int operator-(const Iterator<T> &it) const;

    T &current() const;
    T &operator*() const;
    T *operator->() const;

    Iterator<T> operator++(int);
    Iterator<T> &operator++();

    Iterator<T> operator--(int);
    Iterator<T> &operator--();

    Iterator<T> &operator+=(const int value);
    Iterator<T> &operator-=(const int value);

    T &operator[](const int value) const;

    void swapWith(Iterator<T> &it);
};

#include "iterator.inl"

#endif // __ITERATOR_HPP__