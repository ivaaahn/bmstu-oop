//
// Created by ivaaahn on 24.05.2021.
//

#include "scene.hpp"

Scene::Scene() : models(std::make_shared<Composite>()) {} // TODO: в оригинале было через new

void Scene::addModel(const std::shared_ptr<Model> &model) {
    this->models->add(model);
}

void Scene::removeModel(const size_t model_id) {
    auto it = this->models->begin();
    std::advance(it, model_id);
    this->models->remove(it);
}

void Scene::addCamera(const std::shared_ptr<Camera> &camera) {
    this->cameras.push_back(camera);
}

void Scene::removeCamera(std::size_t camera_id) {
    auto it = this->cameras.begin();
    std::advance(it, camera_id);
    this->cameras.erase(it);
}

std::vector<std::shared_ptr<Object>> Scene::getModels() {
    return this->models->getObjects();
}

std::vector<std::shared_ptr<Camera>> Scene::getCameras() {
    return this->cameras;
}

std::shared_ptr<Composite> Scene::getComposite() {
    return this->models;
}
