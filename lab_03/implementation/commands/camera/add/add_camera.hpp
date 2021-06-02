//
// Created by ivaaahn on 23.05.2021.
//

#ifndef __LAB_03_ADD_CAMERA_HPP__
#define __LAB_03_ADD_CAMERA_HPP__


#include "../camera_command.hpp"

class AddCamera : public CameraCommand {
public:
    AddCamera() = delete;

    AddCamera(double x_pos, double y_pos, double z_pos);

    ~AddCamera() override = default;

    void execute() override;

private:
    double x_pos, y_pos, z_pos;
};


#endif //__LAB_03_ADD_CAMERA_HPP__
