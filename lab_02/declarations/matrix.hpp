#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <memory>
#include <initializer_list>

#include "matrix_base.hpp"
#include "exceptions.hpp"
#include "iterator.hpp"
#include "const_iterator.hpp"

using string = std::string;
template <typename T>
class Matrix : public MatrixBase
{
public:
    class MatrixRow;

    explicit Matrix(const size_t rows = 0, const size_t cols = 0);
    explicit Matrix(const Matrix &anotherM);

    Matrix(const size_t rows, const size_t cols, const T &filler);
    Matrix(std::initializer_list<std::initializer_list<T>> lst);
    Matrix(Matrix &&anotherM);

    // Overloads of the assign operator

    Matrix<T> &operator=(std::initializer_list<std::initializer_list<T>> lst);
    Matrix<T> &operator=(const Matrix &anotherM);
    Matrix<T> &operator=(Matrix &&anotherM);

    // Overloads of the Matrix-Matrix binary operators

    Matrix<T> operator+(const Matrix &anotherM) const;
    Matrix<T> operator-(const Matrix &anotherM) const;
    Matrix<T> operator*(const Matrix &anotherM) const;
    Matrix<T> operator/(const Matrix &anotherM) const;

    Matrix<T> addMatr(const Matrix &anotherM) const;
    Matrix<T> subMatr(const Matrix &anotherM) const;
    Matrix<T> mulMatr(const Matrix &anotherM) const;
    Matrix<T> divMatr(const Matrix &anotherM) const;

    Matrix<T> &operator+=(const Matrix &matrix);
    Matrix<T> &operator-=(const Matrix &matrix);
    Matrix<T> &operator*=(const Matrix &matrix);
    Matrix<T> &operator/=(const Matrix &matrix);

    Matrix<T> &addEqMatr(const Matrix &matrix);
    Matrix<T> &subEqMatr(const Matrix &matrix);
    Matrix<T> &mulEqMatr(const Matrix &matrix);
    Matrix<T> &divEqMatr(const Matrix &matrix);

    bool operator==(const Matrix &matrix) const;
    bool operator!=(const Matrix &matrix) const;

    // Overloads of the Matrix-Element binary operators

    Matrix<T> operator*(const T &elem) const noexcept;
    Matrix<T> operator/(const T &elem) const;

    Matrix<T> mulElem(const T &elem) const noexcept;
    Matrix<T> divElem(const T &elem) const;

    Matrix<T> &operator*=(const T &elem) noexcept;
    Matrix<T> &operator/=(const T &elem);

    Matrix<T> &mulEqElem(const T &elem) noexcept;
    Matrix<T> &divEqElem(const T &elem);

    // Overloads of the unary operators

    Matrix<T> operator-() const;
    Matrix<T> neg() const;

    // Access operators

    MatrixRow operator[](const size_t row);
    const MatrixRow operator[](const size_t row) const;

    T &operator()(const size_t row, const size_t col);
    const T &operator()(const size_t row, const size_t col) const;

    T &at(const size_t row, const size_t col);
    const T &at(const size_t row, const size_t col) const;

    // Fillers

    void fill(Iterator<T> start, const Iterator<T> &end, const T &filler = {});
    void fill(Iterator<T> start, Iterator<T> source_start, const Iterator<T> &source_end);
    void fill(Iterator<T> start, ConstIterator<T> source_start, const ConstIterator<T> &source_end);

    Matrix<T> &eye();
    Matrix<T> &zeros();

    // Restructuration of matrix

    void resize(size_t newRows, size_t newCols, const T &filler = {});
    void resizeRows(const size_t new_size, const T &filler = {});
    void resizeCols(const size_t new_size, const T &filler = {});

    void insertRow(const size_t pos, const T &filler = {});
    void insertRow(const size_t pos, std::initializer_list<T> lst);

    void insertCol(const size_t pos, const T &filler = {});
    void insertCol(const size_t pos, std::initializer_list<T> lst);

    void deleteRow(const size_t pos);
    void deleteCol(const size_t pos);

    // Math operations

    T calcMinor(const size_t row, const size_t col) const;
    T calcDeterminant() const;
    Matrix<T> getTransposed();
    Matrix<T> getInversed();

    // Iterators

    Iterator<T> begin();
    Iterator<T> end();

    ConstIterator<T> begin() const;
    ConstIterator<T> end() const;

    ConstIterator<T> cbegin() const;
    ConstIterator<T> cend() const;

    bool isSquare() const;

    virtual ~Matrix() override = default;

private:
    std::shared_ptr<MatrixRow[]> data = nullptr;

    std::shared_ptr<MatrixRow[]> _allocateMemory(const size_t rows, const size_t cols);
    void _moveRow(const size_t from, const size_t to);
    void _moveCol(const size_t from, const size_t to);
    bool _validInitList(std::initializer_list<std::initializer_list<T>> lst, const size_t rowSize) const;

public:
    class MatrixRow
    {
    public:
        MatrixRow(T *data = nullptr, const size_t size = 0) : data(data), size(size) {}

        T &operator[](const size_t index);
        const T &operator[](const size_t index) const;

        void reset(T *data, const size_t size);
        void reset();

        T *getAddr() { return this->data.get(); }
        const T *getAddr() const { return this->data.get(); }

    private:
        std::shared_ptr<T[]> data;
        size_t size;
    };
};

#include "matrix_access_operators.inl"
#include "matrix_assign_operators.inl"
#include "matrix_checkers.inl"
#include "matrix_construct.inl"
#include "matrix_fill.inl"
#include "matrix_iter.inl"
#include "matrix_math.inl"
#include "matrix_operations.inl"
#include "matrix_restruct.inl"
#include "matrix_row.inl"

#endif // __MATRIX_HPP__