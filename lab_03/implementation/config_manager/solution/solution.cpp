//
// Created by ivaaahn on 26.05.2021.
//

#include "solution.hpp"
#include <cstddef>
#include <exceptions/load_exceptions.hpp>

bool Solution::registerLoaderCreator(size_t id, const std::shared_ptr<ObjectLoaderCreator> &object_loader_creator) {
    return this->callbacks.insert(CallbackMapObject::value_type(id, object_loader_creator)).second;
}

std::shared_ptr<ObjectLoaderCreator> Solution::getLoaderCreator(size_t id) {
    auto it = this->callbacks.find(id);

    if (it == this->callbacks.end()) throw ConfigError(__FILE__, __LINE__, "loader creator not not found");

    return it->second;
}
