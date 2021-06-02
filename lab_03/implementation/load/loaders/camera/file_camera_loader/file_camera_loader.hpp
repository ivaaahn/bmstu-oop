//
// Created by ivaaahn on 24.05.2021.
//

#ifndef __LAB_03_FILE_CAMERA_LOADER_HPP__
#define __LAB_03_FILE_CAMERA_LOADER_HPP__


#include <load/builders/model/model_builder.hpp>
#include <load/builders/camera/camera_builder.hpp>
#include "../camera_loader.hpp"

class FileCameraLoader : public CameraLoader {
public:
    FileCameraLoader();
    explicit FileCameraLoader(std::shared_ptr<std::ifstream> &src_file);
    void open(const std::string &src_name) override;
    std::shared_ptr<Object> load() override;
    void close() override;

private:
    std::shared_ptr<CameraBuilder> builder;
    std::shared_ptr<std::ifstream> src_file;
};


#endif //__LAB_03_FILE_CAMERA_LOADER_HPP__
