//
// Created by ivaaahn on 26.05.2021.
//

#ifndef __LAB_03_CAMERA_LOAD_SOLUTION_HPP__
#define __LAB_03_CAMERA_LOAD_SOLUTION_HPP__


#include <memory>
#include "load/loaders/object_loader_creator.hpp"

#define CAMERA_CFG_PATH "../data/configuration/camera_load.cfg"


class CameraLoadSolution {
public:
    CameraLoadSolution() = default;

    static std::shared_ptr<ObjectLoaderCreator> getCreator();
};


#endif //__LAB_03_CAMERA_LOAD_SOLUTION_HPP__
