//
// Created by ivaaahn on 24.05.2021.
//
#include <fstream>
#include <exceptions/load_exceptions.hpp>

#include "load/loaders/camera/file_camera_loader/file_camera_loader.hpp"
#include "load/loaders/model/file_model_loader/file_model_loader.hpp"
#include "file_scene_loader.hpp"

FileSceneLoader::FileSceneLoader() : builder(std::make_shared<SceneBuilder>()) {}

FileSceneLoader::FileSceneLoader(std::shared_ptr<std::ifstream> &src_file) : FileSceneLoader() {
    this->src_file = src_file;
};

void FileSceneLoader::open(const std::string &src_name) {
    this->src_file = std::make_shared<std::ifstream>(src_name);

    if (!*(this->src_file)) throw FileOpenError(__FILE__, __LINE__, "could not open file with director");
}

std::shared_ptr<Scene> FileSceneLoader::load() {
    this->builder.reset();
    this->loadModels();
    this->loadCameras();

    return this->builder->get();
}

void FileSceneLoader::close() {
    this->src_file->close();
}

void FileSceneLoader::loadModels() {
    size_t models_count;

    if (!(*this->src_file >> models_count)) throw FileFormatError(__FILE__, __LINE__, "invalid director-file format");

    for (size_t i = 0; i < models_count; i++)
        this->builder->buildModel(FileModelLoader(this->src_file).load());
}

void FileSceneLoader::loadCameras() {
    size_t cameras_count;

    if (!(*this->src_file >> cameras_count)) throw FileFormatError(__FILE__, __LINE__, "invalid director-file format");

    for (size_t i = 0; i < cameras_count; i++)
        this->builder->buildCamera(std::dynamic_pointer_cast<Camera>(FileCameraLoader(this->src_file).load()));
}


