//
// Created by ivaaahn on 26.05.2021.
//

#include <fstream>
#include "camera_load_solution.hpp"
#include "../../../config_manager/creator/config_manager_creator.hpp"

std::shared_ptr <SourceLoaderCreator> CameraLoadSolution::getCreator() {
    std::ifstream cfg_file(CAMERA_CFG_PATH);

    if (!cfg_file)
        throw FileOpenException(); // TODO

    size_t id;
    if (!(cfg_file >> id))
        throw FileFormatException(); // TODO

    return ConfigManagerCreator().getManager()->getCreator(id);
