//
// Created by ivaaahn on 30.05.2021.
//

#include <drawer/qt/qt_drawer.hpp>
#include "qt_drawer_factory.hpp"

QtDrawerFactory::QtDrawerFactory(std::shared_ptr<QGraphicsScene> &scene) : scene(scene) {}

std::unique_ptr<Drawer> QtDrawerFactory::create() {
    return std::make_unique<QtDrawer>(this->scene);
}

