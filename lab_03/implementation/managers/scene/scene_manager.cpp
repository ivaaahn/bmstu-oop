//
// Created by ivaaahn on 24.05.2021.
//

#include <exceptions/load_exceptions.hpp>
#include "scene_manager.hpp"

SceneManager::SceneManager() : scene(std::make_shared<Scene>()) {}

std::shared_ptr<Camera> SceneManager::getCurrentCamera() const {
    auto camera_ptr = this->current_camera.lock();

    if (!camera_ptr) throw NoCameraError(__FILE__, __LINE__, "no cameras installed");

    return camera_ptr;
}

std::shared_ptr<Scene> SceneManager::getScene() const {
    return this->scene;
}

void SceneManager::setScene(std::shared_ptr<Scene> new_scene) {
    this->scene = std::move(new_scene);
}

void SceneManager::setCamera(std::size_t camera_id) {
    this->current_camera = this->scene->getCameras().at(camera_id);
}

void SceneManagerCreator::createManager() {
    static auto manager = std::make_shared<SceneManager>();
    this->manager = manager;
}

std::shared_ptr<SceneManager> SceneManagerCreator::getManager() {
    if (this->manager == nullptr) this->createManager();

    return this->manager;
}

