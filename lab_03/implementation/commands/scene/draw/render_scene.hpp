//
// Created by ivaaahn on 23.05.2021.
//

#ifndef __LAB_03_RENDER_SCENE_HPP__
#define __LAB_03_RENDER_SCENE_HPP__


#include <drawer/drawer.hpp>
#include "../scene_command.hpp"

class RenderScene : public SceneCommand {
public:
    RenderScene() = delete;

    explicit RenderScene(std::shared_ptr<Drawer> drawer);

    void execute() override;

    ~RenderScene() override = default;

private:
    std::shared_ptr<Drawer> drawer;
};


#endif //__LAB_03_RENDER_SCENE_HPP__
