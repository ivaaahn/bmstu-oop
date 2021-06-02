//
// Created by ivaaahn on 26.05.2021.
//

#include <fstream>
#include <exceptions/load_exceptions.hpp>
#include <config_manager/creator/config_manager_creator.hpp>
#include "camera_load_solution.hpp"

std::shared_ptr<ObjectLoaderCreator> CameraLoadSolution::getCreator() {
    std::ifstream cfg_file(CAMERA_CFG_PATH);

    if (!cfg_file) throw FileOpenError(__FILE__, __LINE__, "could not open config-file");

    size_t id;

    if (!(cfg_file >> id)) throw FileFormatError(__FILE__, __LINE__, "invalid сonfig-file format");


    return ConfigManagerCreator().getManager()->getLoaderCreator(id);
}