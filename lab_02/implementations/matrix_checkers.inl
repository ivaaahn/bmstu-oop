#ifndef __MATRIX_CHECKERS_INL__
#define __MATRIX_CHECKERS_INL__

#include "matrix.hpp"

using string = std::string;



template <typename T>
bool Matrix<T>::_validInitList(std::initializer_list<std::initializer_list<T>> initList, const size_t rowSize) const
{
    for (const auto &row : initList)
        if (row.size() != rowSize) return false;

    return true;
}


#endif // __MATRIX_CHECKERS_INL__