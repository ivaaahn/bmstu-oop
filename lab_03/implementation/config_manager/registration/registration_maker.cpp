//
// Created by ivaaahn on 26.05.2021.
//

#include <memory>
#include <exceptions/load_exceptions.hpp>


#include "registration_maker.hpp"
#include "load/loaders/model/file_model_loader/file_model_loader.hpp"
#include "load/loaders/camera/file_camera_loader/file_camera_loader.hpp"
#include "scene/loaders/file/file_scene_loader_creator.hpp"


void RegistrationMaker::makeRegistration(Solution &solution) {
    if (!solution.registerObjectLoader(0, std::make_shared<ConObjectLoaderCreator<FileModelLoader>>()))
        throw ConfigError(__FILE__, __LINE__, "failed to register source loader");

    if (!solution.registerObjectLoader(1, std::make_shared<ConObjectLoaderCreator<FileCameraLoader>>()))
        throw ConfigError(__FILE__, __LINE__, "failed to register source loader");

    if (!solution.registerSceneLoader(0, std::make_shared<FileSceneLoaderCreator>()))
        throw ConfigError(__FILE__, __LINE__, "failed to register source director loader");

}
