#ifndef __ITERATOR_HPP__
#define __ITERATOR_HPP__

#include <memory>
#include <string>

using string = std::string;

template <typename T>
class Matrix;

template <typename T>
class Iterator : public std::iterator<std::bidirectional_iterator_tag, T>
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

    bool operator==(const Iterator<T> &another) const;
    bool operator!=(const Iterator<T> &another) const;

    explicit operator bool() const;
    bool isBegin() const;
    bool isEnd() const;
    bool isValid() const;

    Iterator<T> operator+(const int value) const;
    Iterator<T> operator-(const int value) const;
    Iterator<T> &operator+=(const int value); //!

    T &current();
    T &operator*();
    T *operator->();

    const T &current() const;
    const T &operator*() const;
    const T *operator->() const;

    Iterator<T> next();
    Iterator<T> &operator++();
    Iterator<T> operator++(int);

    Iterator<T> prev();
    Iterator<T> &operator--();
    Iterator<T> operator--(int);
};

#include "iterator.inl"

#endif // __ITERATOR_HPP__