//
// Created by ivaaahn on 24.05.2021.
//

#ifndef __LAB_03_DRAW_MANAGER_HPP__
#define __LAB_03_DRAW_MANAGER_HPP__


#include "managers/manager.hpp"
#include "managers/load/load_manager.hpp"
#include "objects/model/model_details/point/point.hpp"
#include "objects/model/model.hpp"
#include "objects/camera/camera.hpp"
#include "visitor/visitor.hpp"

class DrawManager : public Manager {
public:
    DrawManager() = default;

    DrawManager(const DrawManager &) = delete;

    DrawManager &operator=(const DrawManager &) = delete;

    ~DrawManager() override = default;

    void draw(const std::shared_ptr<Scene> &scene);

    void setDrawer(std::shared_ptr<Drawer> drawer);

    void setCamera(std::shared_ptr<Camera> camera);

private:
    std::shared_ptr<Drawer> drawer;
    std::shared_ptr<Camera> camera;
};

class DrawManagerCreator {
public:
    std::shared_ptr<DrawManager> getManager();

private:
    void createManager();

    std::shared_ptr<DrawManager> manager;
};

#endif //__LAB_03_DRAW_MANAGER_HPP__
