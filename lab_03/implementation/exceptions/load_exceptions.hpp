//
// Created by ivaaahn on 31.05.2021.
//

#ifndef __LAB_03_LOAD_EXCEPTIONS_HPP__
#define __LAB_03_LOAD_EXCEPTIONS_HPP__

#include "base_exception.hpp"

class FileError : public BaseException {
public:
    explicit FileError(const string &file, const int line, const string &msg) : BaseException(file, line, msg) {
        this->error_msg = "FileError: " + this->error_msg;
    }
};

class BuildError : public BaseException {
public:
    explicit BuildError(const string &file, const int line, const string &msg) : BaseException(file, line, msg) {
        this->error_msg = "BuildError: " + this->error_msg;
    }
};

class NoDirectorError : public BaseException {
public:
    explicit NoDirectorError(const string &file, const int line, const string &msg) : BaseException(file, line, msg) {
        this->error_msg = "NoDirectorError: " + this->error_msg;
    }
};


class ConfigError : public BaseException {
public:
    explicit ConfigError(const string &file, const int line, const string &msg) : BaseException(file, line, msg) {
        this->error_msg = "ConfigurationError: " + this->error_msg;
    }
};

class NoCameraError : public BaseException {
public:
    explicit NoCameraError(const string &file, const int line, const string &msg) : BaseException(file, line, msg) {
        this->error_msg = "NoCameraError: " + this->error_msg;
    }
};

class FileOpenError : public BaseException {
public:
    explicit FileOpenError(const string &file, const int line, const string &msg) : BaseException(file, line, msg) {
        this->error_msg = "FileOpenError: " + this->error_msg;
    }
};

class FileFormatError : public BaseException {
public:
    explicit FileFormatError(const string &file, const int line, const string &msg) : BaseException(file, line, msg) {
        this->error_msg = "FileFormatError: " + this->error_msg;
    }
};

#endif //__LAB_03_LOAD_EXCEPTIONS_HPP__
