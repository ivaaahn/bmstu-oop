//
// Created by ivaaahn on 31.05.2021.
//

#ifndef __LAB_03_LOAD_CAMERA_HPP__
#define __LAB_03_LOAD_CAMERA_HPP__


#include <commands/camera/camera_command.hpp>
#include <string>

class LoadCamera : public CameraCommand {
public:
    explicit LoadCamera(std::string filename);
    void execute() override;

private:
    std::string filename;
};


#endif //__LAB_03_LOAD_CAMERA_HPP__
