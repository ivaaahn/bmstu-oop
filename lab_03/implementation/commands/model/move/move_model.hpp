//
// Created by ivaaahn on 23.05.2021.
//

#ifndef __LAB_03_MOVE_MODEL_HPP__
#define __LAB_03_MOVE_MODEL_HPP__


#include <cstddef>
#include "../model_command.hpp"

class MoveModel : public ModelCommand {
public:
    MoveModel() = delete;

    MoveModel(std::size_t model_id, double dx, double dy, double dz);

    ~MoveModel() override = default;

    void execute() override;

private:
    std::size_t model_id;

    double dx, dy, dz;
};



#endif //__LAB_03_MOVE_MODEL_HPP__
