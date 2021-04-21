#ifndef __MATRIX_BASE_HPP__
#define __MATRIX_BASE_HPP__


#include <stddef.h>

class MatrixBase
{
protected:
    size_t rows;
    size_t cols;

public:
    MatrixBase(const size_t rows = 0, const size_t cols = 0) : rows(cols ? rows : 0), cols(rows ? cols : 0) { }

    virtual size_t getColumns() const { return this->cols; }
    virtual size_t getRows() const { return this->rows; }
    virtual operator bool() const {return this->cols && this->rows; }

    virtual ~MatrixBase() = 0;
};

MatrixBase::~MatrixBase() = default;


#endif  // __MATRIX_BASE_HPP__