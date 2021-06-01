//
// Created by ivaaahn on 23.05.2021.
//

#include <managers/scene/scene_manager.hpp>
#include "set_camera.hpp"

SetCamera::SetCamera(size_t camera_id) : camera_id(camera_id) {}

void SetCamera::execute() {
    auto scene_manager = SceneManagerCreator().getManager();
    auto it = scene_manager->getScene()->begin();
    std::advance(it, camera_id);

    scene_manager->setMainCamera(it);
}
