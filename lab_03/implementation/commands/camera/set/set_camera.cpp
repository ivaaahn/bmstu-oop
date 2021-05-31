//
// Created by ivaaahn on 23.05.2021.
//

#include <managers/scene/scene_manager.hpp>
#include "set_camera.hpp"

SetCamera::SetCamera(std::size_t camera_id) : camera_id(camera_id) {}

void SetCamera::execute() {
    auto scene_manager = SceneManagerCreator().getManager();
    scene_manager->setCamera(camera_id);
}
