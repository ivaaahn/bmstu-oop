//
// Created by ivaaahn on 24.05.2021.
//

#include "transform_manager.hpp"


void TransformManager::move(const std::shared_ptr<Object> &obj, double dx, double dy, double dz) {
    obj->transform(Point(dx, dy, dz), Point(1, 1, 1), Point(0, 0, 0));
}

void TransformManager::scale(const std::shared_ptr<Object> &obj, double kx, double ky, double kz) {
    obj->transform(Point(0, 0, 0), Point(kx, ky, kz), Point(0, 0, 0));

}

void TransformManager::rotate(const std::shared_ptr<Object> &obj, double ax, double ay, double az) {
    obj->transform(Point(0, 0, 0), Point(1, 1, 1), Point(ax, ay, az));
}

void TransformManager::transform(const std::shared_ptr<Object> &obj, const Point &move_params, const Point &scale_params,
                            const Point &rotate_params) {
    obj->transform(move_params, scale_params, rotate_params);
}

