//
// Created by ivaaahn on 23.05.2021.
//

#include <managers/scene/scene_manager.hpp>
#include "remove_model.hpp"

RemoveModel::RemoveModel(size_t model_id) : model_id(model_id) {}

void RemoveModel::execute() {
    auto scene = SceneManagerCreator().getManager()->getScene();
    auto it = scene->begin();
    std::advance(it, model_id);
    scene->removeObject(it);
}