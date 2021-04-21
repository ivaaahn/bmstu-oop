    #ifndef __EXCEPTIONS_HPP__
#define __EXCEPTIONS_HPP__

#include <exception>
#include <string>

using string = std::string;

class MatrixException : public std::exception
{
protected:
    string errorMessage;

public:
    MatrixException(const string timeInfo, const string fileInfo, const int lineInfo,
                    const string errorMessage = "No error message");

    virtual ~MatrixException(){};

    virtual const char* what() const noexcept override
    {
        return this->errorMessage.c_str();
    }
};

class IndexError : public MatrixException
{
public:
    IndexError(const string timeInfo, const string fileInfo, const int lineInfo,
               const string errorMessage = "No error message") : MatrixException(timeInfo, fileInfo, lineInfo, errorMessage)
    {
        this->errorMessage += " (error type: IndexError)";
    }
};

class MemoryError : public MatrixException
{
public:
    MemoryError(const string timeInfo, const string fileInfo, const int lineInfo,
                const string errorMessage = "No error message") : MatrixException(timeInfo, fileInfo, lineInfo, errorMessage)
    {
        this->errorMessage += " (error type: MemoryError)";
    }
};

class InvalidArgument : public MatrixException
{
public:
    InvalidArgument(const string timeInfo, const string fileInfo, const int lineInfo,
                    const string errorMessage = "No error message") : MatrixException(timeInfo, fileInfo, lineInfo, errorMessage)
    {
        this->errorMessage += " (error type: InvalidArgument)";
    }
};

class IncompatibleElements : public MatrixException
{
public:
    IncompatibleElements(const string timeInfo, const string fileInfo, const int lineInfo,
                         const string errorMessage = "No error message") : MatrixException(timeInfo, fileInfo, lineInfo, errorMessage)
    {
        this->errorMessage += " (error type: IncompatibleElements)";
    }
};

class InvalidState : public MatrixException
{
public:
    InvalidState(const string timeInfo, const string fileInfo, const int lineInfo,
                 const string errorMessage = "No error message") : MatrixException(timeInfo, fileInfo, lineInfo, errorMessage)
    {
        this->errorMessage += " (error type: IncompatibleElements)";
    }
};


#include "exceptions.inl"


#endif // __EXCEPTIONS_HPP__
