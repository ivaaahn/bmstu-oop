//
// Created by ivaaahn on 24.05.2021.
//

#include "file_camera_loader.hpp"

#include <fstream>

FileCameraLoader::FileCameraLoader() : builder(std::make_shared<CameraBuilder>()) {}

FileCameraLoader::FileCameraLoader(std::shared_ptr<std::ifstream> &src_file) : FileCameraLoader() {
    this->src_file = src_file;
}

void FileCameraLoader::open(const std::string &src_name) {
    this->src_file = std::make_shared<std::ifstream>(src_name);

    if (!*(this->src_file)) throw FileOpenException(); // TODO: exceptions
}

std::shared_ptr<Object> FileCameraLoader::load() {
    this->builder->reset();

    if (!*(this->src_file)) throw FileOpenException();

    double x, y, z;
    if (!(*(this->src_file) >> x >> y >> z)) throw FileFormatException();
    this->builder->buildPosition(x, y, z);

    if (!(*(this->src_file) >> x >> y >> z)) throw FileFormatException();
    this->builder->buildAngles(x, y, z);

    return std::dynamic_pointer_cast<Object>(this->builder->get());
}

void FileCameraLoader::close() {
    this->src_file->close();
}
