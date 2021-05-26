//
// Created by ivaaahn on 26.05.2021.
//

#ifndef __LAB_03_SOLUTION_HPP__
#define __LAB_03_SOLUTION_HPP__

#include <map>
#include <cstddef>
#include <memory>
#include "../../load/source_loaders/source_loader_creator.hpp"


class Solution {
public:
    Solution() = default;
    ~Solution() = default;

    bool makeRegistration(size_t id, const std::shared_ptr<SourceLoaderCreator> &loader_creator);
    std::shared_ptr<SourceLoaderCreator> getCreator(size_t id);

private:
    using CallbackMap = std::map<size_t, std::shared_ptr<SourceLoaderCreator>>;
    CallbackMap callback_map;
};


#endif //__LAB_03_SOLUTION_HPP__
