//
// Created by ivaaahn on 23.05.2021.
//

#include <managers/scene/scene_manager.hpp>
#include "count_cameras.hpp"

CameraCount::CameraCount(std::shared_ptr<size_t> &count) : count(count) {}

void CameraCount::execute() {
    *(this->count) = SceneManagerCreator().getManager()->getScene()->getCameras().size();
}

