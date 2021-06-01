//
// Created by ivaaahn on 23.05.2021.
//

#ifndef __LAB_03_SCALE_MODEL_HPP__
#define __LAB_03_SCALE_MODEL_HPP__


#include <cstddef>
#include "../model_command.hpp"

class ScaleModel : public ModelCommand {
public:
    ScaleModel() = delete;

    ScaleModel(std::size_t model_id, double kx, double ky, double kz);

    ~ScaleModel() override = default;

    void execute() override;

private:
    std::size_t model_id;

    double kx, ky, kz;
};

#endif //__LAB_03_SCALE_MODEL_HPP__
