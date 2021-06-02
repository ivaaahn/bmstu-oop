//
// Created by ivaaahn on 30.05.2021.
//

#include "qt_drawer.hpp"

QtDrawer::QtDrawer(std::shared_ptr<QGraphicsScene> &scene) : scene(scene) {}

QtDrawer::QtDrawer(const QtDrawer &drawer) : scene(drawer.scene) {}

void QtDrawer::drawLine(const Point &point1, const Point &point2) {
    this->scene->addLine(point1.getX(), point1.getY(), point2.getX(), point2.getY());
}

void QtDrawer::clearScene() {
    this->scene->clear();
}

