//
// Created by ivaaahn on 28.05.2021.
//

#include "scene_builder.hpp"

SceneBuilder::SceneBuilder() : scene(nullptr) {}

bool SceneBuilder::isBuild() const {
    return this->scene != nullptr;
}

void SceneBuilder::reset() {
    this->scene = std::make_shared<Scene>();
}

void SceneBuilder::buildModel(const std::shared_ptr<Object> &model) {
    this->scene->addModel(model);
}

void SceneBuilder::buildCamera(const std::shared_ptr<Camera> &camera) {
    this->scene->addCamera(camera);
}

std::shared_ptr<Scene> SceneBuilder::get() {
    return this->scene;
}
