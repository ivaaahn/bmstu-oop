//
// Created by ivaaahn on 26.05.2021.
//

#include "solution.hpp"
#include <cstddef>
#include <exceptions/load_exceptions.hpp>

bool Solution::makeSrcLoaderRegistration(size_t id, const std::shared_ptr<SourceLoaderCreator> &src_loader_creator) {
    return this->callbacks.insert(CallbackMapSrc::value_type(id, src_loader_creator)).second;
}

bool Solution::makeSceneLoaderRegistration(size_t id, const std::shared_ptr<SceneLoaderCreator> &scene_loader_creator) {
    return this->callbacks_for_scene.insert(CallbackMapScene::value_type(id, scene_loader_creator)).second;
}

std::shared_ptr<SourceLoaderCreator> Solution::getLoaderCreator(size_t id) {
    auto it = this->callbacks.find(id);

    if (it == this->callbacks.end()) throw ConfigError(__FILE__, __LINE__, "loader creator not not found");

    return it->second;
}

std::shared_ptr<SceneLoaderCreator> Solution::getSceneLoaderCreator(size_t id) {
    auto it = this->callbacks_for_scene.find(id);

    if (it == this->callbacks_for_scene.end()) throw ConfigError(__FILE__, __LINE__, "director loader creator not not found");

    return it->second;
}
