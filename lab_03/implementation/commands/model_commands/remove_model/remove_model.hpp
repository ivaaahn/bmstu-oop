//
// Created by ivaaahn on 23.05.2021.
//

#ifndef __LAB_03_REMOVE_MODEL_HPP__
#define __LAB_03_REMOVE_MODEL_HPP__


#include <cstddef>
#include "../model_command.hpp"

class RemoveModel : public ModelCommand {
public:
    RemoveModel() = delete;

    explicit RemoveModel(std::size_t model_id);

    ~RemoveModel() override = default;

    void execute() override;

private:
    std::size_t model_id;
};


#endif //__LAB_03_REMOVE_MODEL_HPP__
