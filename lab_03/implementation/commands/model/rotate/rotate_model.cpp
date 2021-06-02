//
// Created by ivaaahn on 23.05.2021.
//

#include <objects/model/model_details/point/point.hpp>
#include <managers/scene/scene_manager.hpp>
#include <managers/transform/transform_manager.hpp>
#include "rotate_model.hpp"


RotateModel::RotateModel(std::size_t model_id, double ax, double ay, double az) : model_id(model_id), ax(ax), ay(ay),
                                                                                  az(az) {}

void RotateModel::execute() {
    Point move(0, 0, 0);
    Point scale(1, 1, 1);
    Point rotate(ax, ay, az);

    auto scene_manager = SceneManagerCreator().getManager();
    auto transform_manager = TransformManagerCreator().getManager();

    auto models_iter = scene_manager->getScene()->begin();
    std::advance(models_iter, model_id);

    auto model = *models_iter;
//    std::shared_ptr<Object> model = scene_manager->getScene()->getObjects().at(model_id);
    transform_manager->transform(model, move, scale, rotate);
}
