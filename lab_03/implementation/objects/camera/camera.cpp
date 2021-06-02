//
// Created by ivaaahn on 24.05.2021.
//

#include <iostream>
#include "camera.hpp"

Camera::Camera(const Point &position) : position(position) {}

void Camera::transform(const Point &move_params, const Point &scale_params, const Point &rotate_params) {
    this->shiftX(move_params.getX());
    this->shiftY(move_params.getY());
}

void Camera::accept(std::shared_ptr<Visitor> visitor) {
    visitor->visit(*this);
}

void Camera::shiftX(const double delta) {
    this->position.setX(this->position.getX() + delta);
}

void Camera::shiftY(const double delta) {
    this->position.setY(this->position.getY() + delta);
}

void Camera::shiftZ(const double delta) {
    this->position.setZ(this->position.getZ() + delta);
}

Point Camera::getPosition() const {
    return this->position;
}
