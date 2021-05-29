//
// Created by ivaaahn on 28.05.2021.
//

#include "camera_builder.hpp"

CameraBuilder::CameraBuilder() : camera(nullptr) {}

bool CameraBuilder::isBuild() const {
    return this->camera != nullptr;
}

void CameraBuilder::reset() {
    this->camera = std::make_shared<Camera>();
}

void CameraBuilder::buildPosition(double x, double y, double z) {
    this->camera->transform(Point(x, y, z), Point(1, 1, 1), Point(0, 0, 0));
}

std::shared_ptr<Camera> CameraBuilder::get() {
    return this->camera;
}
