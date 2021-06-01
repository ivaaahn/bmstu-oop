//
// Created by ivaaahn on 23.05.2021.
//

#include <managers/scene/scene_manager.hpp>
#include "count_models.hpp"

CountModels::CountModels(std::shared_ptr<size_t> &count) : count(count) {}

void CountModels::execute() {
    *(this->count) = SceneManagerCreator().getManager()->getScene()->getModelsCount();
}

