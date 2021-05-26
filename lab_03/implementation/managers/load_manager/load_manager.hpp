//
// Created by ivaaahn on 24.05.2021.
//

#ifndef __LAB_03_LOAD_MANAGER_HPP__
#define __LAB_03_LOAD_MANAGER_HPP__


#include <memory>
#include "../manager.hpp"
#include "../../objects/object.hpp"

class LoadController;  // TODO: removeIT;

class LoadManager : public Manager {
public:
    LoadManager();
    LoadManager(const LoadManager &) = delete;
    LoadManager &operator=(const LoadManager &) = delete;
    ~LoadManager() = default;

    virtual std::shared_ptr<Object> load(std::string &name);
    virtual void setLoadController(std::shared_ptr<LoadController> load_controller);

private:
    std::shared_ptr<LoadController> load_controller;
};


#endif //__LAB_03_LOAD_MANAGER_HPP__
