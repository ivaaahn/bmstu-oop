//
// Created by ivaaahn on 23.05.2021.
//

#include <managers/scene/scene_manager.hpp>
#include "count_cameras.hpp"

CountCameras::CountCameras(std::shared_ptr<size_t> &count) : count(count) {}

void CountCameras::execute() {
    *(this->count) = SceneManagerCreator().getManager()->getScene()->getCamerasCount();
}

