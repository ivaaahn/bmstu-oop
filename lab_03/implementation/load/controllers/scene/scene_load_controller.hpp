//
// Created by ivaaahn on 24.05.2021.
//

#ifndef __LAB_03_SCENE_LOAD_CONTROLLER_HPP__
#define __LAB_03_SCENE_LOAD_CONTROLLER_HPP__


#include "../load_controller.hpp"

class SceneLoadController : public LoadController {
public:
    SceneLoadController();
    ~SceneLoadController() = default;

    std::shared_ptr<Object> load(const std::string &src_name) override;
};


#endif //__LAB_03_SCENE_LOAD_CONTROLLER_HPP__
