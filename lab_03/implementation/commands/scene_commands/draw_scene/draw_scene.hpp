//
// Created by ivaaahn on 23.05.2021.
//

#ifndef __LAB_03_DRAW_SCENE_HPP__
#define __LAB_03_DRAW_SCENE_HPP__


#include "../scene_command.hpp"

class DrawScene : public SceneCommand {
public:
    DrawScene() = delete;

    explicit DrawScene(std::shared_ptr<Drawer> drawer);

    void execute() override;

    ~DrawScene() override = default;

private:
    std::shared_ptr<Drawer> drawer;
};


#endif //__LAB_03_DRAW_SCENE_HPP__
