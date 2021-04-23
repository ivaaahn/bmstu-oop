#include <memory>

#include "matrix_base.hpp"
#include "exceptions.hpp"

std::shared_ptr<size_t> MatrixBase::_allocateDimension(const size_t dim)
{
    std::shared_ptr<size_t> dimPtr = nullptr;
    try
    {
        dimPtr.reset(new size_t(dim));
    }
    catch (std::bad_alloc &err)
    {
        throw MemoryError(__FILE__, __LINE__, "Memory allocation error during allocation of matrix dimensions");
    }

    return dimPtr;
}


MatrixBase::~MatrixBase() = default;
