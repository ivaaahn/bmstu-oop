//
// Created by ivaaahn on 26.05.2021.
//

#include "solution.hpp"
#include <cstddef>
#include <exceptions/load_exceptions.hpp>

bool Solution::registerObjectLoader(size_t id, const std::shared_ptr<ObjectLoaderCreator> &object_loader_creator) {
    return this->objects_callbacks.insert(CallbackMapObject::value_type(id, object_loader_creator)).second;
}

bool Solution::registerSceneLoader(size_t id, const std::shared_ptr<SceneLoaderCreator> &scene_loader_creator) {
    return this->scene_callbacks.insert(CallbackMapScene::value_type(id, scene_loader_creator)).second;
}

std::shared_ptr<ObjectLoaderCreator> Solution::getObjectLoaderCreator(size_t id) {
    auto it = this->objects_callbacks.find(id);

    if (it == this->objects_callbacks.end()) throw ConfigError(__FILE__, __LINE__, "loader creator not not found");

    return it->second;
}

std::shared_ptr<SceneLoaderCreator> Solution::getSceneLoaderCreator(size_t id) {
    auto it = this->scene_callbacks.find(id);

    if (it == this->scene_callbacks.end()) throw ConfigError(__FILE__, __LINE__, "director loader creator not not found");

    return it->second;
}
