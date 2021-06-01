//
// Created by ivaaahn on 31.05.2021.
//

#include <utility>
#include <managers/load/load_manager.hpp>
#include <managers/scene/scene_manager.hpp>
#include <load/directors/camera/camera_director.hpp>
#include "load_camera.hpp"

LoadCamera::LoadCamera(std::string filename) : filename(std::move(filename)) {}

void LoadCamera::execute() {
    auto load_manager = LoadManagerCreator().getManager();
    load_manager->setDirector(std::make_shared<CameraDirector>());

    auto camera = load_manager->load(filename);
    auto scene_manager = SceneManagerCreator().getManager();

    scene_manager->getScene()->addCamera(std::dynamic_pointer_cast<Camera>(camera));
}
