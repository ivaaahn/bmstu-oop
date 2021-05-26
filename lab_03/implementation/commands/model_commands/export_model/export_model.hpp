//
// Created by ivaaahn on 23.05.2021.
//

#ifndef __LAB_03_EXPORT_MODEL_HPP__
#define __LAB_03_EXPORT_MODEL_HPP__


#include <string>
#include "../model_command.hpp"

class ExportModel : public ModelCommand {
public:
    ExportModel() = delete;

    explicit ExportModel(std::string fileName);

    ~ExportModel() override = default;

    void execute() override;

private:
    std::string fileName;
};


#endif //__LAB_03_EXPORT_MODEL_HPP__
