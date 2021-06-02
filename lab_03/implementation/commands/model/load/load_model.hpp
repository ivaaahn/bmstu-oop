//
// Created by ivaaahn on 23.05.2021.
//

#ifndef __LAB_03_LOAD_MODEL_HPP__
#define __LAB_03_LOAD_MODEL_HPP__


#include <string>
#include "../model_command.hpp"

class LoadModel : public ModelCommand {
public:
    LoadModel() = delete;

    explicit LoadModel(std::string filename);

    ~LoadModel() override = default;

    void execute() override;

private:
    std::string filename;
};


#endif //__LAB_03_LOAD_MODEL_HPP__
