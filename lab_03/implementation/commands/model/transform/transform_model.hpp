//
// Created by ivaaahn on 23.05.2021.
//

#ifndef __LAB_03_TRANSFORM_MODEL_HPP__
#define __LAB_03_TRANSFORM_MODEL_HPP__


#include <cstddef>
#include "../model_command.hpp"

class TransformModel : public ModelCommand {
public:
    TransformModel() = delete;

    TransformModel(std::size_t model_id, const Point &move, const Point &scale, const Point &rotate);

    ~TransformModel() override = default;

    void execute() override;

private:
    std::size_t model_id;

    Point move, scale, rotate;
};

#endif //__LAB_03_TRANSFORM_MODEL_HPP__
