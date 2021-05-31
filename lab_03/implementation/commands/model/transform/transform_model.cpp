//
// Created by ivaaahn on 23.05.2021.
//

#include <objects/model/model_details/point/point.hpp>
#include <managers/scene/scene_manager.hpp>
#include <managers/transform/transform_manager.hpp>
#include "transform_model.hpp"


TransformModel::TransformModel(std::size_t model_id, const Point &move, const Point &scale, const Point &rotate)
    : model_id(model_id), move(move), scale(scale), rotate(rotate) {}

void TransformModel::execute()
{
    auto scene_manager = SceneManagerCreator().getManager();
    auto transform_manager = TransformManagerCreator().getManager();

    std::shared_ptr<Object> model = scene_manager->getScene()->getModels().at(model_id);
    transform_manager->transform(model, move, scale, rotate);
}