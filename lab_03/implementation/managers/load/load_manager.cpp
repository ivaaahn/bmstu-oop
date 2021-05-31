//
// Created by ivaaahn on 24.05.2021.
//

#include <exceptions/load_exceptions.hpp>
#include "load_manager.hpp"


void LoadManager::setDirector(const std::shared_ptr<LoadDirector> &new_director) {
    this->director = new_director;
}

std::shared_ptr<Object> LoadManager::load(const std::string &name) {
    if (this->director == nullptr) throw NoDirectorError(__FILE__, __LINE__, "no directors");

    return this->director->load(name);
}

void LoadManagerCreator::createManager() {
    static auto manager = std::make_shared<LoadManager>();
    this->manager = manager;
}

std::shared_ptr<LoadManager> LoadManagerCreator::getManager() {
    if (this->manager == nullptr) this->createManager();

    return this->manager;
}