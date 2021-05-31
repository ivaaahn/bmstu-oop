//
// Created by ivaaahn on 24.05.2021.
//

#ifndef __LAB_03_SCENE_LOADER_HPP__
#define __LAB_03_SCENE_LOADER_HPP__


#include <string>
#include <memory>

#include "scene/scene.hpp"

class SceneLoader {
public:
    SceneLoader() = default;

    virtual ~SceneLoader() = default;

    virtual void open(const std::string &src_name) = 0;

    virtual std::shared_ptr<Scene> load() = 0;

    virtual void close() = 0;
};


#endif //__LAB_03_SCENE_LOADER_HPP__
