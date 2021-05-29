//
// Created by ivaaahn on 23.05.2021.
//

#ifndef __LAB_03_ROTATE_MODEL_HPP__
#define __LAB_03_ROTATE_MODEL_HPP__

#include <cstddef>
#include "../model_command.hpp"

class RotateModel : public ModelCommand {
public:
    RotateModel() = delete;

    RotateModel(std::size_t model_id, double ax, double ay, double az);

    ~RotateModel() override = default;

    void execute() override;

private:
    std::size_t model_id;

    double ax, ay, az;
};



#endif //__LAB_03_ROTATE_MODEL_HPP__
