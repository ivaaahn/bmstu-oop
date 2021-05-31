//
// Created by ivaaahn on 30.05.2021.
//

#include "draw_visitor.hpp"

#include "drawer/drawer.hpp"
#include "objects/model/model.hpp"


DrawVisitor::DrawVisitor(const std::shared_ptr<Drawer> &drawer, const std::shared_ptr<Camera> &camera) : drawer(drawer),
                                                                                                         camera(camera) {}

void DrawVisitor::visit(const Model &model) {
    auto points = model.getDetails()->getPoints();
    auto center = model.getDetails()->getCenter();

    for (const auto &edge : model.getDetails()->getEdges())
        this->drawer->drawLine(points.at(edge.getFirst()), points.at(edge.getSecond())); // TODO project and DRAWER
}


Point DrawVisitor::projectPoint(const Point &point) {
    Point new_point(point);
    Point camera_position(this->camera->getPosition());

    new_point.setX(new_point.getX() - camera_position.getX());
    new_point.setY(new_point.getY() - camera_position.getY());

    return new_point;
}


void DrawVisitor::visit(const Camera &camera) {}

void DrawVisitor::visit(const Composite &composite) {}

