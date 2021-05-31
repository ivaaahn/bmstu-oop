//
// Created by ivaaahn on 24.05.2021.
//

#include "transform_manager.hpp"

void
TransformManager::transform(const std::shared_ptr<Object> &obj, const Point &move_params, const Point &scale_params,
                            const Point &rotate_params) {
    obj->transform(move_params, scale_params, rotate_params);
}

void TransformManagerCreator::createManager() {
    static auto manager = std::make_shared<TransformManager>();
    this->manager = manager;
}

std::shared_ptr<TransformManager> TransformManagerCreator::getManager() {
    if (this->manager == nullptr) this->createManager();

    return this->manager;
}