#ifndef __MATRIX_RESTRUCT_INL__
#define __MATRIX_RESTRUCT_INL__

#include "matrix.hpp"

template <typename T>
void Matrix<T>::resize(size_t newRows, size_t newCols, const T &filler)
{
    if (newRows * newCols == 0)
        newRows = 0, newCols = 0;

    auto tmpData = _allocateMemory(newRows, newCols);

    for (size_t i = 0; i < newRows; ++i)
        for (size_t j = 0; j < newCols; ++j)
            tmpData[i][j] = (i < this->rows && j < this->cols) ? this->data[i][j] : filler;

    this->data = tmpData;
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

template <typename T>
void Matrix<T>::insertRow(const size_t pos, const T &filler)
{
    if (pos > this->rows)
        throw IndexError(__FILE__, __LINE__, "Index out of bound matrix dimension during row insertion");

    resizeRows(this->rows + 1);

    for (size_t j = 0; j < this->cols; ++j)
        this->data[this->rows - 1][j] = filler;

    this->_moveRow(this->rows - 1, pos);
}

template <typename T>
void Matrix<T>::insertRow(const size_t pos, std::initializer_list<T> lst)
{
    if (pos > this->rows)
        throw IndexError(__FILE__, __LINE__, "Index out of bound matrix dimension during row insertion");

    resizeRows(this->rows + 1);

    size_t k = 0;
    for (const auto &item : lst)
        this->data[this->rows - 1][k++] = item;

    this->_moveRow(this->rows - 1, pos);
}

template <typename T>
void Matrix<T>::insertCol(const size_t pos, const T &filler)
{
    if (pos > this->cols)
        throw IndexError(__FILE__, __LINE__, "Index out of bound matrix dimension during column insertion");

    resizeCols(this->cols + 1);

    for (size_t i = 0; i < this->rows; i++)
        this->data[i][this->cols - 1] = filler;

    this->_moveCol(this->cols - 1, pos);
}

template <typename T>
void Matrix<T>::insertCol(const size_t pos, std::initializer_list<T> lst)
{
    if (pos > this->cols)
        throw IndexError(__FILE__, __LINE__, "Index out of bound matrix dimension during row insertion");

    resizeCols(this->cols + 1);

    size_t k = 0;
    for (const auto &item : lst)
        this->data[k++][this->cols - 1] = item;

    this->_moveCol(this->cols - 1, pos);
}

template <typename T>
void Matrix<T>::deleteRow(const size_t pos)
{
    if (pos >= this->rows)
        throw IndexError(__FILE__, __LINE__, "Index out of bound matrix dimension during row removing");

    auto tmpData = _allocateMemory(this->rows - 1, this->cols);

    size_t i_dst = 0;
    for (size_t i_src = 0; i_src < this->rows; ++i_src)
        if (i_src != pos)
        {
            for (size_t j_curr = 0; j_curr < this->cols; ++j_curr)
                tmpData[i_dst][j_curr] = this->data[i_src][j_curr];
            ++i_dst;
        }

    this->data = tmpData;
    --this->rows;
}

template <typename T>
void Matrix<T>::deleteCol(const size_t pos)
{
    if (pos >= this->cols)
        throw IndexError(__FILE__, __LINE__, "Index out of bound matrix dimension during column removing");

    auto tmp = _allocateMemory(this->rows, this->cols - 1);

    size_t j_dst = 0;
    for (size_t j_src = 0; j_src < this->cols; ++j_src)
    {
        if (j_src != pos)
        {
            for (size_t i_curr = 0; i_curr < this->rows; ++i_curr)
                tmp[i_curr][j_dst] = this->data[i_curr][j_src];
            ++j_dst;
        }
    }

    this->data = tmp;
    this->cols--;
}

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
void Matrix<T>::_moveCol(const size_t from, const size_t to)
{
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
