//
// Created by ivaaahn on 26.05.2021.
//

#ifndef __LAB_03_CAMERA_LOAD_CONTROLLER_HPP__
#define __LAB_03_CAMERA_LOAD_CONTROLLER_HPP__

#include "../load_controller.hpp"

class CameraLoadController : public LoadController {
public:
    CameraLoadController();
    ~CameraLoadController() = default;

    std::shared_ptr<Object> load(const std::string &src_name) override;
};


#endif //__LAB_03_CAMERA_LOAD_CONTROLLER_HPP__
