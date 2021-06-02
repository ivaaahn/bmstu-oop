//
// Created by ivaaahn on 26.05.2021.
//

#include "config_manager.hpp"

ConfigManager::ConfigManager() {
    auto reg_maker = std::make_shared<RegistrationMaker>();
    reg_maker->makeRegistration(this->solution);
}

std::shared_ptr<ObjectLoaderCreator> ConfigManager::getLoaderCreator(size_t id) {
    return this->solution.getLoaderCreator(id);
}
