#ifndef __EXCEPTIONS_HPP__
#define __EXCEPTIONS_HPP__

#include <exception>
#include <string>

using string = std::string;

class MatrixException : public std::exception
{
protected:
    string errMsg;

public:
    MatrixException(const string file, const int line, const string errMsg = "No error message")
    {
        time_t currTime = time(NULL);
        auto localTime = localtime(&currTime);
        this->errMsg = errMsg + "\nFile: " + file + "\nLine: " + std::to_string(line) + "\nTime: " + asctime(localTime);
    }

    virtual ~MatrixException(){};

    virtual const char *what() const noexcept override
    {
        return this->errMsg.c_str();
    }
};

class IndexError : public MatrixException
{
public:
    IndexError(const string file, const int line, const string msg = "No error message") : MatrixException(file, line, msg)
    {
        this->errMsg = "IndexError: " + this->errMsg;
    }
};

class MemoryError : public MatrixException
{
public:
    MemoryError(const string file, const int line, const string msg = "No error message") : MatrixException(file, line, msg)
    {
        this->errMsg = "MemoryError: " + this->errMsg;
    }
};

class InvalidArgument : public MatrixException
{
public:
    InvalidArgument(const string file, const int line, const string msg = "No error message") : MatrixException(file, line, msg)
    {
        this->errMsg = "InvalidArgument: " + this->errMsg;
    }
};

class IncompatibleElements : public MatrixException
{
public:
    IncompatibleElements(const string file, const int line, const string msg = "No error message") : MatrixException(file, line, msg)
    {
        this->errMsg = "IncompatibleElements: " + this->errMsg;
    }
};

class InvalidDimensions : public MatrixException
{
public:
    InvalidDimensions(const string file, const int line, const string msg = "No error message") : MatrixException(file, line, msg)
    {
        this->errMsg = "InvalidDimensions: " + this->errMsg;
    }
};

class SingularMatrix : public MatrixException
{
public:
    SingularMatrix(const string file, const int line, const string msg = "No error message") : MatrixException(file, line, msg)
    {
        this->errMsg = "SingularMatrix: " + this->errMsg;
    }
};


class ZeroDivision : public MatrixException
{
public:
    ZeroDivision(const string file, const int line, const string msg = "No error message") : MatrixException(file, line, msg)
    {
        this->errMsg = "ZeroDivision: " + this->errMsg;
    }
};


#endif // __EXCEPTIONS_HPP__
