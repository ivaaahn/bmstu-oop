#ifndef __CONST_ITERATOR_HPP__
#define __CONST_ITERATOR_HPP__ 

#include <memory>
#include <string>

#include "exceptions.hpp"

using string = std::string;

template<typename T>
class Matrix;

template<typename T>
class ConstIterator: public std::iterator<std::bidirectional_iterator_tag, T> 
{
    friend Matrix<T>;

private:
    std::weak_ptr<typename Matrix<T>::MatrixRow[]> data = nullptr;   
    size_t cols = 0;
    size_t rows = 0;
    mutable size_t index = 0;

    void _checkIndex(const string hint = "") const;
    void checkValid(const string hint = "") const;

    ConstIterator(const std::shared_ptr<typename Matrix<T>::MatrixRow[]> &data, const size_t rows, const size_t cols, const size_t index) 
        : data(data), index(index), rows(rows), cols(cols) {}
public:
    ConstIterator(ConstIterator &it) = default;

    bool operator==(ConstIterator const &other) const;
    bool operator!=(ConstIterator const &other) const;
    // bool operator<(ConstIterator const &other) const;

    explicit operator bool() const;
    bool isEnd() const;
    bool isBegin() const;
    bool isValid() const;

    ConstIterator<T> operator+(const int value) const;
    ConstIterator<T> operator-(const int value) const;
    ConstIterator<T>& operator+=(const int value) const;

    const T& current() const;
    const T& operator*() const;
    const T* operator->() const;

    ConstIterator<T>& next() const;
    ConstIterator<T> operator++(int) const;
    const ConstIterator<T>& operator++() const;

    ConstIterator<T>& prev() const;
    ConstIterator<T> operator--(int) const;
    const ConstIterator<T>& operator--() const;
};


#include "const_iterator.inl"

#endif  // __CONST_ITERATOR_HPP__