//
// Created by ivaaahn on 24.05.2021.
//

#ifndef __LAB_03_TRANSFORM_MANAGER_HPP__
#define __LAB_03_TRANSFORM_MANAGER_HPP__


#include "../../objects/model/model_details/point/point.hpp"
#include "../../objects/object.hpp"
#include "../manager.hpp"

class TransformManager : public Manager {
public:
    TransformManager() = default;

    TransformManager(const TransformManager &) = delete;

    TransformManager &operator=(const TransformManager &) = delete;

    ~TransformManager() = default;

    static void move(const std::shared_ptr<Object> &obj, double dx, double dy, double dz);

    static void scale(const std::shared_ptr<Object> &obj, double kx, double ky, double kz);

    static void rotate(const std::shared_ptr<Object> &obj, double ax, double ay, double az);

    static void transform(const std::shared_ptr<Object> &obj, const Point &move_params, const Point &scale_params,
                          const Point &rotate_params);
};


#endif //__LAB_03_TRANSFORM_MANAGER_HPP__
