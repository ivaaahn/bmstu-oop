//
// Created by ivaaahn on 24.05.2021.
//

#include "scene_load_controller.hpp"
    #include "../../solutions/scene/scene_load_solution.hpp"

SceneLoadController::SceneLoadController() {
    auto scene_src_loader_creator = SceneLoadSolution().getCreator();
    this->src_loader = scene_src_loader_creator->create();
}

std::shared_ptr<Object> SceneLoadController::load(const std::string &src_name) {
    this->src_loader->open(src_name);
    auto scene = this->src_loader->load();
    this->src_loader->close();

    return scene;
}
