//
// Created by ivaaahn on 26.05.2021.
//

#ifndef __LAB_03_SOLUTION_HPP__
#define __LAB_03_SOLUTION_HPP__

#include <map>
#include <cstddef>
#include <memory>
#include "load/source_loaders//source_loader_creator.hpp"
#include <scene/loaders/scene_loader_creator.hpp>


using CallbackMapSrc = std::map<size_t, std::shared_ptr<SourceLoaderCreator>>;
using CallbackMapScene = std::map<size_t, std::shared_ptr<SceneLoaderCreator>>;

class Solution {
public:
    Solution() = default;

    ~Solution() = default;

    bool makeSrcLoaderRegistration(size_t id, const std::shared_ptr<SourceLoaderCreator> &src_loader_creator);

    bool makeSceneLoaderRegistration(size_t id, const std::shared_ptr<SceneLoaderCreator> &scene_loader_creator);

    std::shared_ptr<SourceLoaderCreator> getLoaderCreator(size_t id);

    std::shared_ptr<SceneLoaderCreator> getSceneLoaderCreator(size_t id);

private:
    CallbackMapSrc callbacks;
    CallbackMapScene callbacks_for_scene;
};


#endif //__LAB_03_SOLUTION_HPP__
