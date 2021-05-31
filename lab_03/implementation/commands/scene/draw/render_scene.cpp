//
// Created by ivaaahn on 23.05.2021.
//

#include <managers/draw/draw_manager.hpp>
#include <managers/scene/scene_manager.hpp>
#include <utility>
#include "render_scene.hpp"

RenderScene::RenderScene(std::shared_ptr<Drawer> drawer) : drawer(std::move(drawer)) {}

void RenderScene::execute() {
    auto scene_manager = SceneManagerCreator().getManager();
    auto draw_manager = DrawManagerCreator().getManager();

    draw_manager->setCamera(scene_manager->getCurrentCamera());
    draw_manager->setDrawer(this->drawer);

    this->drawer->clearScene();

    draw_manager->draw(scene_manager->getScene()->getComposite());
}
