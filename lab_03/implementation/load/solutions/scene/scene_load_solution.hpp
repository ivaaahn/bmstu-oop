//
// Created by ivaaahn on 26.05.2021.
//

#ifndef __LAB_03_SCENE_LOAD_SOLUTION_HPP__
#define __LAB_03_SCENE_LOAD_SOLUTION_HPP__


#include <memory>
#include "../../source_loaders/source_loader_creator.hpp"

#define SCENE_CFG_PATH "./data/scene_load.cfg"

class SceneLoadSolution {
public:
    SceneLoadSolution() = default;

    std::shared_ptr<SourceLoaderCreator> getCreator();
};


#endif //__LAB_03_SCENE_LOAD_SOLUTION_HPP__
