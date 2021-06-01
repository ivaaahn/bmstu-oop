//
// Created by ivaaahn on 23.05.2021.
//

#ifndef __LAB_03_SET_CAMERA_HPP__
#define __LAB_03_SET_CAMERA_HPP__


#include <cstddef>
#include "../camera_command.hpp"

class SetCamera : public CameraCommand {
public:
    SetCamera() = delete;

    explicit SetCamera(size_t camera_id);

    ~SetCamera() override = default;

    void execute() override;


private:
    std::size_t camera_id;
};

#endif //__LAB_03_SET_CAMERA_HPP__
