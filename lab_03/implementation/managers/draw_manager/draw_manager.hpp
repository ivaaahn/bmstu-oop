//
// Created by ivaaahn on 24.05.2021.
//

#ifndef __LAB_03_DRAW_MANAGER_HPP__
#define __LAB_03_DRAW_MANAGER_HPP__


#include "../manager.hpp"
#include "../../visitor/visitor.hpp"
#include "../../objects/model/model_details/point/point.hpp"
#include "../../objects/model/model.hpp"
#include "../../objects/camera/camera.hpp"

class Drawer; // TODO: remove it!

class DrawManager : public Visitor, public Manager {
public:
    DrawManager() = default;

    DrawManager(const DrawManager &) = delete;

    DrawManager &operator=(const DrawManager &) = delete;

    ~DrawManager() = default;

    void visit(const Camera &camera) override;

    void visit(const Model &model) override;

    void visit(const Composite &composite) override;

    void setDrawer(std::shared_ptr<Drawer> drawer);

    void setCamera(std::shared_ptr<Camera> camera);

private:
    Point projectPoint(const Point &point);

    std::shared_ptr<Drawer> drawer;
    std::shared_ptr<Camera> camera;

};

#endif //__LAB_03_DRAW_MANAGER_HPP__
