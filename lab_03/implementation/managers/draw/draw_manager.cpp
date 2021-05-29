//
// Created by ivaaahn on 24.05.2021.
//

#include <utility>
#include <memory>

#include "draw_manager.hpp"


// TODO: непонятки с центром все-таки
void DrawManager::visit(const Model &model) {
    auto points = model.getDetails()->getPoints();
    auto center = model.getDetails()->getCenter();

    for (auto edge : model.getDetails()->getEdges())
        this->drawer->drawLine(
                this->projectPoint(points.at(edge.getFirst()).relativeTo(center)),
                this->projectPoint(points.at(edge.getSecond())).relativeTo(center));
}


void DrawManager::setDrawer(std::shared_ptr<Drawer> drawer) {
    this->drawer = std::move(drawer);
}

void DrawManager::setCamera(std::shared_ptr<Camera> camera) {
    this->camera = std::move(camera);
}


// TODO: а не минус ли должен быть???
Point DrawManager::projectPoint(const Point &point) {
    Point new_point(point);
    Point camera_position(this->camera->getPosition());

    new_point.setX(new_point.getX() + camera_position.getX());
    new_point.setY(new_point.getY() + camera_position.getY());

    return new_point;
}

void DrawManager::visit(const Camera &camera) {}

void DrawManager::visit(const Composite &composite) {}
