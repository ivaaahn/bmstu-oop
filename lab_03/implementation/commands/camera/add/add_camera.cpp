//
// Created by ivaaahn on 23.05.2021.
//

#include <objects/model/model_details/point/point.hpp>
#include <objects/camera/camera.hpp>
#include <managers/scene/scene_manager.hpp>
#include "add_camera.hpp"

AddCamera::AddCamera(double x_pos, double y_pos, double z_pos) : x_pos(x_pos), y_pos(y_pos), z_pos(z_pos) {}

void AddCamera::execute() {
    Point cam_pos(x_pos, y_pos, z_pos);

    auto camera = std::make_shared<Camera>();
    camera->transform(cam_pos, cam_pos, cam_pos);

    auto scene_manager = SceneManagerCreator().getManager();
    scene_manager->getScene()->addCamera(camera);
    scene_manager->setCamera(scene_manager->getScene()->getCameras().size() - 1);
}
