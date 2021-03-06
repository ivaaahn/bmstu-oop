//
// Created by ivaaahn on 26.05.2021.
//

#ifndef __LAB_03_CONFIG_MANAGER_HPP__
#define __LAB_03_CONFIG_MANAGER_HPP__


#include <memory>
#include "solution/solution.hpp"
#include "registration/registration_maker.hpp"

class ConfigManager {
public:
    ConfigManager();

    std::shared_ptr<ObjectLoaderCreator> getLoaderCreator(size_t id);

private:
    Solution solution;
};


#endif //__LAB_03_CONFIG_MA NAGER_HPP__
