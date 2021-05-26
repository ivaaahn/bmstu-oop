//
// Created by ivaaahn on 26.05.2021.
//

#include <fstream>
#include "scene_load_solution.hpp"
#include "../../../config_manager/creator/config_manager_creator.hpp"


std::shared_ptr <SourceLoaderCreator> SceneLoadSolution::getCreator() {
    std::ifstream cfg_file(SCENE_CFG_PATH);

    if (!cfg_file)
        throw FileOpenException(); // TODO

    size_t id;
    if (!(cfg_file >> id))
        throw FileFormatException();

    return ConfigManagerCreator().getManager()->getCreator(id);
}
