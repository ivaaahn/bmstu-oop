#ifndef __MATRIX_BASE_HPP__
#define __MATRIX_BASE_HPP__

// size_t
#include <stddef.h>

class MatrixBase
{
public:
    MatrixBase(const size_t rows, const size_t cols)
    {
        this->rows = _allocateDimension(rows);
        this->cols = _allocateDimension(cols);
    }

    virtual size_t getCols() const { return bool(this->cols) ? *(this->cols) : 0; }
    virtual size_t getRows() const { return bool(this->rows) ? *(this->rows) : 0; }
    
    virtual operator bool() const { return *(this->cols) && *(this->rows); }

    virtual ~MatrixBase() = 0;

protected:

    std::shared_ptr<size_t> rows;
    std::shared_ptr<size_t> cols;

private:
    std::shared_ptr<size_t> _allocateDimension(const size_t dim);
};


#endif // __MATRIX_BASE_HPP__