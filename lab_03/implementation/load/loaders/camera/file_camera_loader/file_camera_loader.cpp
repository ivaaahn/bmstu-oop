//
// Created by ivaaahn on 24.05.2021.
//

#include "file_camera_loader.hpp"

#include <fstream>
#include <load/builders/camera/camera_builder.hpp>
#include <exceptions/load_exceptions.hpp>

FileCameraLoader::FileCameraLoader() : builder(std::make_shared<CameraBuilder>()) {}

FileCameraLoader::FileCameraLoader(std::shared_ptr<std::ifstream> &src_file) : FileCameraLoader() {
    this->src_file = src_file;
}

void FileCameraLoader::open(const std::string &src_name) {
    this->src_file = std::make_shared<std::ifstream>(src_name);

    if (!*(this->src_file)) throw FileOpenError(__FILE__, __LINE__, "could not open camera-file");
}

std::shared_ptr<Object> FileCameraLoader::load() {
    this->builder->reset();

    double x, y, z;
    if (!(*(this->src_file) >> x >> y >> z)) throw FileFormatError(__FILE__, __LINE__, "bad format of camera-file");
    this->builder->buildPosition(x, y, z);

    return std::dynamic_pointer_cast<Object>(this->builder->get());
}

void FileCameraLoader::close() {
    this->src_file->close();
}
