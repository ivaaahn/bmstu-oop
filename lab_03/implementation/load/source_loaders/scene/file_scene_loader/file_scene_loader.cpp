//
// Created by ivaaahn on 24.05.2021.
//

#include "file_scene_loader.hpp"

#include <fstream>

// TODO: Builder
FileSceneLoader::FileSceneLoader() : builder(std::make_shared<SceneBuilder>()) {}

FileSceneLoader::FileSceneLoader(std::shared_ptr<std::ifstream> &src_file) : FileSceneLoader() {
    this->src_file = src_file;
};

void FileSceneLoader::open(const std::string &src_name) {
    this->src_file = std::make_shared<std::ifstream>(src_name);

    if (!*(this->src_file)) throw FileOpenException(); // TODO: exceptions
}

std::shared_ptr<Object> FileSceneLoader::load() {
    this->builder.reset();

    if (!*(this->src_file)) throw FileOpenException(); // TODO: need this???

    this->loadModels();
    this->loadCameras();
}

void FileSceneLoader::close() {
    this->src_file->close();
}

void FileSceneLoader::loadModels() {
    size_t models_count;
    if (!(*this->src_file >> models_count))
        throw FileFormatException();

    for (size_t i = 0; i < models_count; i++)
        this->builder->build_model(FileModelLoader(this->src_file).load());
}

void FileSceneLoader::loadCameras() {
    size_t cameras_count;
    if (!(*this->src_file >> cameras_count))
        throw FileFormatException();

    for (size_t i = 0; i < cameras_count; i++)
        this->builder->build_camera(FileCameraLoader(this->file).load());
}


