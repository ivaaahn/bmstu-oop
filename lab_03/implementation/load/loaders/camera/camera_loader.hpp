//
// Created by ivaaahn on 24.05.2021.
//

#ifndef __LAB_03_CAMERA_LOADER_HPP__
#define __LAB_03_CAMERA_LOADER_HPP__


#include "../../../objects/object.hpp"
#include "../object_loader.hpp"

class CameraLoader : public ObjectLoader {
public:
    CameraLoader() = default;

    virtual ~CameraLoader() = default;

    virtual void open(const std::string &src_name) = 0;

    virtual std::shared_ptr<Object> load() = 0;

    virtual void close() = 0;
};


#endif //__LAB_03_CAMERA_LOADER_HPP__
