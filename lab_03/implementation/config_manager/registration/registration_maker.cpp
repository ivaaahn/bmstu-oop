//
// Created by ivaaahn on 26.05.2021.
//

#include "registration_maker.hpp"
#include "../../load/source_loaders/scene/file_scene_loader/file_scene_loader.hpp"
#include "../../load/source_loaders/model/file_model_loader/file_model_loader.hpp"
#include "../../load/source_loaders/camera/file_camera_loader/file_camera_loader.hpp"


#include <memory>

void RegistrationMaker::makeRegistration(Solution &solution) {
    if(!solution.makeRegistration(0, std::make_shared<ConSourceLoaderCreator<FileSceneLoader>>());
        throw ConfigException(); // TODO: except

    if(!solution.makeRegistration(1, std::make_shared<ConSourceLoaderCreator<FileModelLoader>>());
        throw ConfigException(); // TODO: except

    if(!solution.makeRegistration(2, std::make_shared<ConSourceLoaderCreator<FileCameraLoader>>());
        throw ConfigException(); // TODO: except
}
