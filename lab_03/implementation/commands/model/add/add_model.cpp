//
// Created by ivaaahn on 23.05.2021.
//

#include <managers/scene/scene_manager.hpp>
#include "add_model.hpp"

void AddModel::execute() {
    SceneManagerCreator().getManager()->getScene()->addModel(model);

}

AddModel::AddModel(std::shared_ptr<Object> model) : model(model) {}