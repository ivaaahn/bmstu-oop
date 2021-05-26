//
// Created by ivaaahn on 24.05.2021.
//

#ifndef __LAB_03_BASE_MANAGER_CREATOR_HPP__
#define __LAB_03_BASE_MANAGER_CREATOR_HPP__


#include <memory>
#include "../manager.hpp"


class BaseManagerCreator {
public:
    virtual ~BaseManagerCreator() = 0;

    std::shared_ptr<Manager> getManager();

protected:
    virtual std::shared_ptr<Manager> createManager() = 0;

private:
    std::shared_ptr<Manager> manager;
};


#endif //__LAB_03_BASE_MANAGER_CREATOR_HPP__
