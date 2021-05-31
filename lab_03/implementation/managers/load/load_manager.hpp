//
// Created by ivaaahn on 24.05.2021.
//

#ifndef __LAB_03_LOAD_MANAGER_HPP__
#define __LAB_03_LOAD_MANAGER_HPP__


#include <memory>
#include <load/directors/load_director.hpp>
#include "../manager.hpp"
#include "../../objects/object.hpp"

class LoadManager : public Manager {
public:
    LoadManager() = default;

    LoadManager(const LoadManager &) = delete;

    LoadManager &operator=(const LoadManager &) = delete;

    ~LoadManager() override = default;

    virtual std::shared_ptr<Object> load(const std::string &name);

    void setDirector(const std::shared_ptr<LoadDirector> &director);


private:
    std::shared_ptr<LoadDirector> director;
};

class LoadManagerCreator {
public:
    std::shared_ptr<LoadManager> getManager();

private:
    void createManager();
    std::shared_ptr<LoadManager> manager;
};


#endif //__LAB_03_LOAD_MANAGER_HPP__
