#ifndef __EXCEPTIONS_INL__
#define __EXCEPTIONS_INL__

#include "exceptions.hpp"

MatrixException::MatrixException(const string timeInfo, const string fileInfo, const int lineInfo,
                                 const string errorMessage)
{
    this->errorMessage = "\nFile: " + fileInfo + "\nLine: " + std::to_string(lineInfo) + "\nTime: " + timeInfo + "Message: " + errorMessage;
}

#endif // __EXCEPTION_INL__