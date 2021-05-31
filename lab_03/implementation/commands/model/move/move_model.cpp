//
// Created by ivaaahn on 23.05.2021.
//

#include <objects/model/model_details/point/point.hpp>
#include <memory>
#include <objects/object.hpp>
#include <managers/scene/scene_manager.hpp>
#include <managers/transform/transform_manager.hpp>
#include "move_model.hpp"


MoveModel::MoveModel(size_t model_id, double dx, double dy, double dz) : model_id(model_id), dx(dx), dy(dy), dz(dz) {}

void MoveModel::execute() {
    Point move(dx, dy, dz);
    Point scale(1, 1, 1);
    Point rotate(0, 0, 0);

    auto scene_manager = SceneManagerCreator().getManager();
    auto transform_manager = TransformManagerCreator().getManager();

    std::shared_ptr<Object> model = scene_manager->getScene()->getModels().at(model_id);
    transform_manager->transform(model, move, scale, rotate);
}
