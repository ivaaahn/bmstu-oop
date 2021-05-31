//
// Created by ivaaahn on 23.05.2021.
//

#include <managers/scene/scene_manager.hpp>
#include "remove_model.hpp"

RemoveModel::RemoveModel(size_t model_id) : model_id(model_id) {}

void RemoveModel::execute() {
    SceneManagerCreator().getManager()->getScene()->removeModel(model_id);
}