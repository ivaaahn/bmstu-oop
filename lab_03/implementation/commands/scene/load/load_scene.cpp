//
// Created by ivaaahn on 23.05.2021.
//

#include "load_scene.hpp"

#include <utility>
#include <managers/load/load_manager.hpp>
#include <load/directors/scene/scene_director.hpp>
#include <managers/scene/scene_manager.hpp>

LoadScene::LoadScene(std::string filename) : filename(std::move(filename)) {}

void LoadScene::execute() {
    auto load_manager = LoadManagerCreator().getManager();
    load_manager->setDirector(std::make_shared<SceneDirector>());

    auto scene = load_manager->load(filename);
    SceneManagerCreator().getManager()->setScene(std::dynamic_pointer_cast<Scene>(scene));
}
