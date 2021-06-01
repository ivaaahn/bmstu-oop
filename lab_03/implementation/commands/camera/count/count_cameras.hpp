//
// Created by ivaaahn on 23.05.2021.
//

#ifndef __LAB_03_COUNT_CAMERAS_HPP__
#define __LAB_03_COUNT_CAMERAS_HPP__

#include <memory>
#include <cstddef>

#include <commands/camera/camera_command.hpp>

class CountCameras : public CameraCommand {
public:
    CountCameras() = delete;

    explicit CountCameras(std::shared_ptr<std::size_t> &count);

    ~CountCameras() override = default;

    void execute() override;

private:
    std::shared_ptr<std::size_t> &count;
};


#endif //__LAB_03_COUNT_CAMERAS_HPP__
