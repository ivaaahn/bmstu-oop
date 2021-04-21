#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__


#include <memory>
#include <initializer_list>

#include "matrix_base.hpp"
#include "exceptions.hpp"
#include "iterator.hpp"
#include "const_iterator.hpp"

template<typename T>
class Matrix : public MatrixBase
{
public:
    class MatrixRow;

private:
    std::shared_ptr<MatrixRow[]> data = nullptr ;
    
    std::shared_ptr<MatrixRow[]> allocMem(const size_t rows, const size_t cols);
    void _moveRow(const size_t from, const size_t to);
    void _moveCol(const size_t from, const size_t to);
    void _checkIndexOutOfBound(const size_t pos, const size_t limit) const;
    void _checkDimensionsEqu(const Matrix &matrix) const;
    void _checkDimensionsForMult(const Matrix &matrix) const;


public:
    Matrix(const size_t rows=0, const size_t cols=0);
    Matrix(const size_t rows, const size_t cols, const T &filler);
    Matrix(std::initializer_list<std::initializer_list<T>> initList);

    explicit Matrix(const Matrix &anotherM);
    Matrix(Matrix &&anotherM);
    

    // TODO constructor for iterators
    //? constructor for C-style

    virtual ~Matrix() override = default;



    Matrix<T> &operator=(const Matrix &matrix);
    Matrix<T> &operator=(Matrix &&matrix);
    Matrix<T> &operator=(std::initializer_list<std::initializer_list<T>> initList);


    Matrix<T> operator+(const Matrix &anotherM) const;
    Matrix<T> operator-(const Matrix &anotherM) const;
    Matrix<T> operator*(const Matrix &anotherM) const;
    Matrix<T> operator/(const Matrix &anotherM) const;

    Matrix<T> addMatr(const Matrix &anotherM) const;
    Matrix<T> subMatr(const Matrix &anotherM) const;
    Matrix<T> mulMatr(const Matrix &anotherM) const;
    Matrix<T> divMatr(const Matrix &anotherM) const;


    Matrix<T> operator+(const T &elem) const noexcept;
    Matrix<T> operator-(const T &elem) const noexcept;
    Matrix<T> operator*(const T &elem) const noexcept;
    Matrix<T> operator/(const T &elem) const;

    Matrix<T> addElem(const T &elem) const noexcept;
    Matrix<T> subElem(const T &elem) const noexcept;
    Matrix<T> mulElem(const T &elem) const noexcept;
    Matrix<T> divElem(const T &elem) const;


    Matrix<T> operator-();
    Matrix<T> neg();

    Matrix<T> &operator+=(const Matrix &matrix);
    Matrix<T> &operator-=(const Matrix &matrix);
    Matrix<T> &operator*=(const Matrix &matrix);
    Matrix<T> &operator/=(const Matrix &matrix);

    Matrix<T> &addEqMatrix(const Matrix &matrix);
    Matrix<T> &subEqMatrix(const Matrix &matrix);
    Matrix<T> &mulEqMatrix(const Matrix &matrix);
    Matrix<T> &divEqMatrix(const Matrix &matrix);

    Matrix<T> &operator+=(const T &elem) noexcept;
    Matrix<T> &operator-=(const T &elem) noexcept;
    Matrix<T> &operator*=(const T &elem) noexcept;
    Matrix<T> &operator/=(const T &elem);

    Matrix<T> &addEqElem(const T &elem) noexcept;
    Matrix<T> &subEqElem(const T &elem) noexcept;
    Matrix<T> &mulEqElem(const T &elem) noexcept;
    Matrix<T> &divEqElem(const T &elem);


    bool isSquare() const;
    T determinant() const;
    void transpose();
    Matrix<T>& inverse();

    // TODO: А надо ли???
    ConstIterator<T> begin() const;
    ConstIterator<T> end() const;

    Iterator<T> begin();
    Iterator<T> end();
    ConstIterator<T> cbegin() const;
    ConstIterator<T> cend() const;

    void fill(Iterator<T> start, const Iterator<T> &end, const T &value);
    void fill(Iterator<T> start, Iterator<T> source_start, const Iterator<T> &source_end);
    void fill(Iterator<T> start, ConstIterator<T> source_start, const ConstIterator<T> &source_end);

    void resize(size_t newRows, size_t newCols, const T &filler = {});
    void resizeRows(const size_t new_size, const T &filler = {});
    void resizeCols(const size_t new_size, const T &filler = {});

    void insertRow(const size_t pos, const T &filler = {});
    void insertCol(const size_t pos, const T &filler = {});

    void deleteRow(const size_t pos);
    void deleteCol(const size_t pos);

    bool operator==(const Matrix& matrix) const;
    bool operator!=(const Matrix& matrix) const;


    MatrixRow operator[](const size_t row);
    const MatrixRow operator[](const size_t row) const;

    T& at(const size_t row, const size_t col);
    T& operator()(const size_t row, const size_t col);
    
    const T& at(const size_t row, const size_t col) const;
    const T& operator()(const size_t row, const size_t col) const;


public:
    class MatrixRow 
    {

    private:
        std::shared_ptr<T[]> data;
        size_t size;
    
    public:
        MatrixRow(T *data = nullptr, const size_t size = 0): data(data), size(size) {}
        // MatrixRow(): data(nullptr), size(0) {}


        T& operator[](const size_t index);
        const T& operator[](const size_t index) const;

        void reset(T *data, const size_t size); //? WHATAHELL
        void reset();
        
        T* getAddr() { return this->data.get(); }
        const T* getAddr() const { return this->data.get(); }
    };
};

#include "matrix_row.inl"
#include "matrix_checkers.inl"
#include "matrix_construct.inl"
#include "matrix_assign_operators.inl"
#include "matrix_iter.inl"
#include "matrix_math.inl"
#include "matrix_operations.inl"
#include "matrix_restruct.inl"


#endif  // __MATRIX_HPP__