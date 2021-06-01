//
// Created by ivaaahn on 01.06.2021.
//

#ifndef __LAB_03_CAMERA_EXCEPTIONS_HPP__
#define __LAB_03_CAMERA_EXCEPTIONS_HPP__

class LastCameraRemoveError : public BaseException {
public:
    explicit LastCameraRemoveError(const string &file, const int line, const string &msg) : BaseException(file, line, msg) {
        this->error_msg = "LastCameraRemoveError: " + this->error_msg;
    }
};

#endif //__LAB_03_CAMERA_EXCEPTIONS_HPP__
