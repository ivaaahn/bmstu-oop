//
// Created by ivaaahn on 26.05.2021.
//

#include <memory>
#include <exceptions/load_exceptions.hpp>


#include "registration_maker.hpp"
#include "load/source_loaders/model/file_model_loader/file_model_loader.hpp"
#include "load/source_loaders/camera/file_camera_loader/file_camera_loader.hpp"
#include "scene/loaders/file/file_scene_loader_creator.hpp"


void RegistrationMaker::makeRegistration(Solution &solution) {
    if (!solution.makeSrcLoaderRegistration(1, std::make_shared<ConSourceLoaderCreator<FileModelLoader>>()))
        throw ConfigError(__FILE__, __LINE__, "failed to register source loader")

    if (!solution.makeSrcLoaderRegistration(2, std::make_shared<ConSourceLoaderCreator<FileCameraLoader>>()))
        throw ConfigError(__FILE__, __LINE__, "failed to register source loader");

    if (!solution.makeSceneLoaderRegistration(0, std::make_shared<FileSceneLoaderCreator>()))
        throw ConfigError(__FILE__, __LINE__, "failed to register source scene loader")

}
