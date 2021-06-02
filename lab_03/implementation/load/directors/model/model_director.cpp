//
// Created by ivaaahn on 24.05.2021.
//

#include <load/solutions/model/model_load_solution.hpp>
#include "model_director.hpp"

ModelDirector::ModelDirector() {
    this->loader = ModelLoadSolution().getCreator()->create();
}

std::shared_ptr<Object> ModelDirector::load(const std::string &src_name) {
    this->loader->open(src_name);
    auto model = this->loader->load();
    this->loader->close();

    return model;
}
