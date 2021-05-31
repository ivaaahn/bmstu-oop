//
// Created by ivaaahn on 26.05.2021.
//

#include "config_manager_creator.hpp"

std::shared_ptr<ConfigManager> ConfigManagerCreator::getManager() {
    if (!this->manager)
        this->createManager();

    return this->manager;
}

void ConfigManagerCreator::createManager() {
    static auto new_manager = std::make_shared<ConfigManager>();
    this->manager = new_manager;
}
