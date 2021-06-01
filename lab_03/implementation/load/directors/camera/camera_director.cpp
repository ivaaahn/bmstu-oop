//
// Created by ivaaahn on 26.05.2021.
//

#include <load/solutions/camera/camera_load_solution.hpp>
#include "camera_director.hpp"

CameraDirector::CameraDirector() {
    this->loader = CameraLoadSolution::getCreator()->create();
}

std::shared_ptr<Object> CameraDirector::load(const std::string &src_name) {
    this->loader->open(src_name);
    auto camera = this->loader->load();
    this->loader->close();

    return camera;
}
