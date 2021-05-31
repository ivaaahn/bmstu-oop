//
// Created by ivaaahn on 31.05.2021.
//

#ifndef __LAB_03_FILE_SCENE_LOADER_CREATOR_HPP__
#define __LAB_03_FILE_SCENE_LOADER_CREATOR_HPP__


#include <scene/loaders/scene_loader_creator.hpp>
#include "file_scene_loader.hpp"

class FileSceneLoaderCreator : public SceneLoaderCreator {
public:
    FileSceneLoaderCreator() = default;

    ~FileSceneLoaderCreator() override = default;

    std::shared_ptr<SceneLoader> create() override {
        return std::make_shared<FileSceneLoader>();
    }
};


#endif //__LAB_03_FILE_SCENE_LOADER_CREATOR_HPP__
