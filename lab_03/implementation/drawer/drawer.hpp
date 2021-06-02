//
// Created by ivaaahn on 30.05.2021.
//

#ifndef __LAB_03_DRAWER_HPP__
#define __LAB_03_DRAWER_HPP__


#include <objects/model/model_details/point/point.hpp>
#include <memory>

class Drawer {
public:
    Drawer() = default;

    virtual ~Drawer() = default;

    virtual void drawLine(const Point &p1, const Point &p2) = 0;

    virtual void clearScene() = 0;
};

class DrawerFactory {
public:
    virtual std::unique_ptr<Drawer> createDrawer() = 0;
};

#endif //__LAB_03_DRAWER_HPP__
