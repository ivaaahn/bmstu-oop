//
// Created by ivaaahn on 30.05.2021.
//

#ifndef __LAB_03_QT_DRAWER_FACTORY_HPP__
#define __LAB_03_QT_DRAWER_FACTORY_HPP__

#include <memory>
#include <QGraphicsScene>

#include "drawer/drawer.hpp"
#include "drawer/drawer_factory.hpp"

class QtDrawerFactory : public DrawerFactory {
public:
    explicit QtDrawerFactory(std::shared_ptr<QGraphicsScene> &scene);

    std::unique_ptr<Drawer> create() override;

private:
    std::shared_ptr<QGraphicsScene> scene;
};


#endif //__LAB_03_QT_DRAWER_FACTORY_HPP__
