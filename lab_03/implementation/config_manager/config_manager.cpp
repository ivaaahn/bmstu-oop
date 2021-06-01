//
// Created by ivaaahn on 26.05.2021.
//

#include "config_manager.hpp"

ConfigManager::ConfigManager() {
    auto reg_maker = std::make_shared<RegistrationMaker>();
    reg_maker->makeRegistration(this->solution);
}

std::shared_ptr<SourceLoaderCreator> ConfigManager::getSrcLoaderCreator(const size_t id) {
    return this->solution.getLoaderCreator(id);
}

std::shared_ptr<SceneLoaderCreator> ConfigManager::getSceneLoaderCreator(size_t id) {
    return this->solution.getSceneLoaderCreator(id);
}