//
// Created by ivaaahn on 24.05.2021.
//

#ifndef __LAB_03_MANAGER_CREATOR_HPP__
#define __LAB_03_MANAGER_CREATOR_HPP__

template<typename ManagerT>
class ManagerCreator : public BaseManagerCreator {
protected:
    std::shared_ptr<Manager> createManager() override { return std::make_shared<ManagerT>(); }
};

#endif //__LAB_03_MANAGER_CREATOR_HPP__
