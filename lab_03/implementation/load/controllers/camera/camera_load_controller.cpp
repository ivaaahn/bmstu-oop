//
// Created by ivaaahn on 26.05.2021.
//

#include "camera_load_controller.hpp"
#include "../../solutions/model/model_load_solution.hpp"

CameraLoadController::CameraLoadController() {
    auto camera_src_loader_creator = ModelLoadSolution().getCreator();
    this->src_loader = camera_src_loader_creator->create();
}

std::shared_ptr<Object> CameraLoadController::load(const std::string &src_name) {
    this->src_loader->open(src_name);
    auto camera = this->src_loader->load();
    this->src_loader->close();

    return camera;
}
