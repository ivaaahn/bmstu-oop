//
// Created by ivaaahn on 23.05.2021.
//

#ifndef __LAB_03_REMOVE_CAMERA_HPP__
#define __LAB_03_REMOVE_CAMERA_HPP__


#include <cstddef>
#include "../camera_command.hpp"

class RemoveCamera : public CameraCommand {
public:
    RemoveCamera() = delete;

    explicit RemoveCamera(std::size_t camera_id);

    ~RemoveCamera() override = default;

    void execute() override;

private:
    std::size_t camera_id;
};

#endif //__LAB_03_REMOVE_CAMERA_HPP__
