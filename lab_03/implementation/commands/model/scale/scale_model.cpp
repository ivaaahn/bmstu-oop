//
// Created by ivaaahn on 23.05.2021.
//

#include <objects/model/model_details/point/point.hpp>
#include <managers/scene/scene_manager.hpp>
#include <managers/transform/transform_manager.hpp>
#include "scale_model.hpp"

ScaleModel::ScaleModel(std::size_t model_id, const double kx, const double ky, const double kz) : model_id(model_id),
                                                                                                  kx(kx),
                                                                                                  ky(ky), kz(kz) {}

void ScaleModel::execute() {
    Point move(0, 0, 0);
    Point scale(kx, ky, kz);
    Point rotate(0, 0, 0);

    auto scene_manager = SceneManagerCreator().getManager();
    auto transform_manager = TransformManagerCreator().getManager();

    auto models_iter = scene_manager->getScene()->getComposite()->begin();
    std::advance(models_iter, model_id);

    auto model = *models_iter;
//    std::shared_ptr<Object> model = scene_manager->getScene()->getModels().at(model_id);
    transform_manager->transform(model, move, scale, rotate);
}
