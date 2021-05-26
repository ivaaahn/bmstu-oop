//
// Created by ivaaahn on 24.05.2021.
//

#include "model_load_controller.hpp"
#include "../../solutions/model/model_load_solution.hpp"

ModelLoadController::ModelLoadController() {
    auto model_src_loader_creator = ModelLoadSolution().getCreator();
    this->src_loader = model_src_loader_creator->create();
}

std::shared_ptr<Object> ModelLoadController::load(const std::string &src_name) {
    this->src_loader->open(src_name);
    auto model = this->src_loader->load();
    this->src_loader->close();

    return model;
}
