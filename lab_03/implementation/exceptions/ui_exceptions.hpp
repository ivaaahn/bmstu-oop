//
// Created by ivaaahn on 31.05.2021.
//

#ifndef __LAB_03_UI_EXCEPTIONS_HPP__
#define __LAB_03_UI_EXCEPTIONS_HPP__

#include "base_exception.hpp"

class UIError : public BaseException {
public:
    explicit UIError(const string &file, const int line, const string &msg) : BaseException(file, line, msg) {
        this->error_msg = "UIError: " + this->error_msg;
    }
};

#endif //__LAB_03_UI_EXCEPTIONS_HPP__
