//
// Created by ivaaahn on 24.05.2021.
//

#ifndef __LAB_03_FILE_SCENE_LOADER_HPP__
#define __LAB_03_FILE_SCENE_LOADER_HPP__


#include <memory>
#include <scene/loaders/scene_loader.hpp>
#include <load/builders/scene/scene_builder.hpp>

class FileSceneLoader : public SceneLoader {
public:
    FileSceneLoader();

    explicit FileSceneLoader(std::shared_ptr<std::ifstream> &src_file);

    void open(const std::string &src_name) override;

    std::shared_ptr<Scene> load() override;

    void close() override;

private:
    std::shared_ptr<SceneBuilder> builder;
    std::shared_ptr<std::ifstream> src_file;

    void loadModels();

    void loadCameras();
};


#endif //__LAB_03_FILE_SCENE_LOADER_HPP__
