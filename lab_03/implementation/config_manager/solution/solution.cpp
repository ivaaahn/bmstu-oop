//
// Created by ivaaahn on 26.05.2021.
//

#include "solution.hpp"
#include <cstddef>

bool Solution::makeRegistration(size_t id, const std::shared_ptr<SourceLoaderCreator> &loader_creator) {
    return this->callback_map.insert(CallbackMap::value_type(id, loader_creator)).second;
}

std::shared_ptr<SourceLoaderCreator> Solution::getCreator(size_t id) {
    auto it = this->callback_map.find(id);
    if (it == this->callback_map.end())
        throw ConfigException(); // TODO exception

    return it->second;
}
