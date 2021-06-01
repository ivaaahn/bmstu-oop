//
// Created by ivaaahn on 30.05.2021.
//

#ifndef __LAB_03_QT_DRAWER_HPP__
#define __LAB_03_QT_DRAWER_HPP__


#include "drawer/drawer.hpp"
#include <QGraphicsScene>
#include <memory>

class QtDrawer : public Drawer {
public:
    QtDrawer() = delete;

    explicit QtDrawer(std::shared_ptr<QGraphicsScene> &scene);

    QtDrawer(const QtDrawer &drawer);

    void drawLine(const Point &point1, const Point &point2) override;

    void clearScene() override;

private:
    std::shared_ptr<QGraphicsScene> scene;
};

#endif //__LAB_03_QT_DRAWER_HPP__
