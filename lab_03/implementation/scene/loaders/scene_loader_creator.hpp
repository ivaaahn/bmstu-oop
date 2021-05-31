//
// Created by ivaaahn on 31.05.2021.
//

#ifndef __LAB_03_SCENE_LOADER_CREATOR_HPP__
#define __LAB_03_SCENE_LOADER_CREATOR_HPP__

#include "scene_loader.hpp"

class SceneLoaderCreator {
public:
    SceneLoaderCreator() = default;

    virtual ~SceneLoaderCreator() = default;

    virtual std::shared_ptr<SceneLoader> create() = 0;
};

#endif //__LAB_03_SCENE_LOADER_CREATOR_HPP__
