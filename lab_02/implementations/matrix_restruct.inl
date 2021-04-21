#ifndef __MATRIX_RESTRUCT_INL__
#define __MATRIX_RESTRUCT_INL__

#include "matrix.hpp"

template <typename T>
void Matrix<T>::resize(size_t newRows, size_t newCols, const T &filler)
{
    if (newRows * newCols == 0) newRows = 0, newCols = 0;

    auto newData = allocMem(newRows, newCols);

    for (size_t i = 0; i < newRows; ++i)
        for (size_t j = 0; j < newCols; ++j)
            newData[i][j] = (i < this->rows && j < this->cols) ? this->data[i][j] : filler;

    this->data = newData;
    this->cols = newCols;
    this->rows = newRows;
}

template <typename T>
void Matrix<T>::resizeRows(const size_t newRows, const T &filler)
{
    this->resize(newRows, this->cols, filler);
}

template <typename T>
void Matrix<T>::resizeCols(const size_t newCols, const T &filler)
{
    this->resize(this->rows, newCols, filler);
}

// TODO: WATAHELL IS GOIN ON HERE
template <typename T>
void Matrix<T>::insertRow(size_t pos, const T &filler) {
    this->_checkIndexOutOfBound(pos, this->rows);
    resizeRows(this->rows + 1);

    this->fill(this->end() - static_cast<int>(this->cols), end(), filler);
    this->_moveRow(this->rows - 1, pos);
}

template <typename T>
void Matrix<T>::insertCol(size_t pos, const T &filler) {
    this->_checkIndexOutOfBound(pos, this->cols);
    resizeCols(this->cols + 1);

    for (size_t i = 0; i < this->rows; i++)
        this->data[i][this->cols - 1] = filler;
    
    this->_moveCol(this->cols - 1, pos);
}

template <typename T>
void Matrix<T>::deleteRow(size_t pos) {
    this->_checkIndexOutOfBound(pos, this->rows - 1);

    auto tmp = allocMem(this->rows - 1, this->cols);
    
    size_t src = 0, dest = 0;
    while (src < this->rows) 
    {
        if (src != pos) 
        {
            for (size_t i = 0; i < this->cols; ++i)
                tmp[dest++][i] = this->data[src][i];
        }
        
        ++src;
    }

    this->data = tmp;
    this->rows--;
}

template <typename T>
void Matrix<T>::deleteCol(size_t pos) 
{
    this->_checkIndexOutOfBound(pos, this->cols - 1);
    auto tmp = allocMem(this->rows, this->cols - 1);


    size_t src = 0, dest = 0;
    while (src < this->cols)
    {
        if (src != pos) 
        {
            for (size_t i = 0; i < this->rows; ++i)
                tmp[i][dest++] = this->data[i][src];
        }

        ++src;
    }

    this->data = tmp;
    this->cols--;
}

// template <typename T>
// void Matrix<T>::reverse(Iterator<T> start, Iterator<T> end) 
// {
//     for ()
//     end = end - 1;
//     for (; start < end; start++, end--)
//     {
//         auto tmp = *start;
//         *start = *end;
//         *end = tmp;
//     }
// }

template <typename T>
bool Matrix<T>::isSquare() const 
{ 
    return this->rows == this->cols; 
}

template <typename T>
void Matrix<T>::_moveRow(const size_t from, const size_t to) 
{
    auto tmp = this->data[from];

    for (size_t i = from; i > to; --i)
        this->data[i] = this->data[i - 1];

    for (size_t i = from; i < to; ++i)
        this->data[i] = this->data[i + 1];
        
    this->data[to] = tmp;
}

template <typename T>
void Matrix<T>::_moveCol(const size_t from, const size_t to) {
    for (size_t j = 0; j < this->rows; ++j)
    {
        auto tmp = this->data[j][from];

        for (size_t i = from; i > to; --i)
            this->data[j][i] = this->data[j][i - 1];
            
        for (size_t i = from; i < to; ++i)
            this->data[j][i] = this->data[j][i + 1];

        this->data[j][to] = tmp;
    }
}


#endif // __MATRIX_RESTRUCT_INL__
