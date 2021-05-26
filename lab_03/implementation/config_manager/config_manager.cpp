//
// Created by ivaaahn on 26.05.2021.
//

#include "config_manager.hpp"

ConfigManager::ConfigManager() : reg_maker(std::make_shared<RegistrationMaker>()) {
    this->reg_maker->makeRegistration(this->solution);
}

std::shared_ptr<SourceLoaderCreator> ConfigManager::getCreator(const size_t id) {
    return this->solution.getCreator(id);
}
