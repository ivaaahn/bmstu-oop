//
// Created by ivaaahn on 26.05.2021.
//

#ifndef __LAB_03_SOLUTION_HPP__
#define __LAB_03_SOLUTION_HPP__

#include <map>
#include <cstddef>
#include <memory>
#include "load/loaders/object_loader_creator.hpp"
#include "scene/loaders/scene_loader_creator.hpp"


using CallbackMapObject = std::map<size_t, std::shared_ptr<ObjectLoaderCreator>>;
using CallbackMapScene = std::map<size_t, std::shared_ptr<SceneLoaderCreator>>;

class Solution {
public:
    Solution() = default;

    ~Solution() = default;

    bool registerObjectLoader(size_t id, const std::shared_ptr<ObjectLoaderCreator> &object_loader_creator);

    bool registerSceneLoader(size_t id, const std::shared_ptr<SceneLoaderCreator> &scene_loader_creator);

    std::shared_ptr<ObjectLoaderCreator> getObjectLoaderCreator(size_t id);

    std::shared_ptr<SceneLoaderCreator> getSceneLoaderCreator(size_t id);

private:
    CallbackMapObject objects_callbacks;
    CallbackMapScene scene_callbacks;
};


#endif //__LAB_03_SOLUTION_HPP__
