//
// Created by ivaaahn on 24.05.2021.
//

#include "base_manager_creator.hpp"

BaseManagerCreator::~BaseManagerCreator() = default;

std::shared_ptr <Manager> BaseManagerCreator::getManager() {
    if (!this->manager)
        this->manager = this->createManager();

    return this->manager;
}
