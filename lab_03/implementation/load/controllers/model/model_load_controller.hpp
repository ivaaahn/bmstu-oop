//
// Created by ivaaahn on 24.05.2021.
//

#ifndef __LAB_03_MODEL_LOAD_CONTROLLER_HPP__
#define __LAB_03_MODEL_LOAD_CONTROLLER_HPP__

#include "../load_controller.hpp"

class ModelLoadController : public LoadController {
public:
    ModelLoadController();
    ~ModelLoadController() = default;

    std::shared_ptr<Object> load(const std::string &src_name) override;
};


#endif //__LAB_03_MODEL_LOAD_CONTROLLER_HPP__
