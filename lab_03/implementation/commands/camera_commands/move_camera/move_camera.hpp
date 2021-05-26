//
// Created by ivaaahn on 23.05.2021.
//

#ifndef __LAB_03_MOVE_CAMERA_HPP__
#define __LAB_03_MOVE_CAMERA_HPP__


#include <cstddef>
#include "../camera_command.hpp"

class MoveCamera : public CameraCommand {
public:
    MoveCamera() = delete;

    MoveCamera(std::size_t camera_id, double shift_x, double shift_y);

    ~MoveCamera() override = default;

    void execute() override;

private:
    std::size_t camera_id;
    double shift_x, shift_y;
};

#endif //__LAB_03_MOVE_CAMERA_HPP__
