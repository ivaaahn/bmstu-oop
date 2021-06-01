//
// Created by ivaaahn on 24.05.2021.
//

#include <scene/solution/scene_load_solution.hpp>
#include "scene_director.hpp"

SceneDirector::SceneDirector() {
    this->loader = SceneLoadSolution().getCreator()->create();
}

std::shared_ptr<Scene> SceneDirector::load(const std::string &src_name) {
    this->loader->open(src_name);
    auto scene = this->loader->load();
    this->loader->close();

    return scene;
}
