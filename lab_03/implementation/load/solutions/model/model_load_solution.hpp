//
// Created by ivaaahn on 26.05.2021.
//

#ifndef __LAB_03_MODEL_LOAD_SOLUTION_HPP__
#define __LAB_03_MODEL_LOAD_SOLUTION_HPP__


#include <memory>
#include "load/loaders/object_loader_creator.hpp"

#define MODEL_CFG_PATH "../data/configuration/model_load.cfg"

class ModelLoadSolution {
public:
    ModelLoadSolution() = default;

    static std::shared_ptr<ObjectLoaderCreator> getCreator();
};


#endif //__LAB_03_MODEL_LOAD_SOLUTION_HPP__
