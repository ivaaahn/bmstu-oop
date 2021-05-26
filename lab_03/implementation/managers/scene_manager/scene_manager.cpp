//
// Created by ivaaahn on 24.05.2021.
//

#include "scene_manager.hpp"

SceneManager::SceneManager() : scene(std::make_shared<Scene>()) {}

std::shared_ptr<Camera> SceneManager::getCurrentCamera() const {
    return this->current_camera;
}

std::shared_ptr<Scene> SceneManager::getScene() const {
    return this->scene;
}

void SceneManager::setScene(std::shared_ptr<Scene> scene) {
    this->scene = std::move(scene);
}

void SceneManager::setCamera(std::size_t camera_id) {
    this->current_camera = this->scene->getCameras().at(camera_id);
}


