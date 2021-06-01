//
// Created by ivaaahn on 24.05.2021.
//

#ifndef __LAB_03_TRANSFORM_MANAGER_HPP__
#define __LAB_03_TRANSFORM_MANAGER_HPP__


#include "objects/model/model_details/point/point.hpp"
#include "objects/object.hpp"
#include "managers/manager.hpp"

class TransformManager : public Manager {
public:
    TransformManager() = default;

    TransformManager(const TransformManager &) = delete;

    TransformManager &operator=(const TransformManager &) = delete;

    ~TransformManager() override = default;

    static void transform(const std::shared_ptr<Object> &obj, const Point &move_params, const Point &scale_params,
                          const Point &rotate_params);

};

class TransformManagerCreator {
public:
    std::shared_ptr<TransformManager> getManager();

private:
    void createManager();

    std::shared_ptr<TransformManager> manager;
};

#endif //__LAB_03_TRANSFORM_MANAGER_HPP__
