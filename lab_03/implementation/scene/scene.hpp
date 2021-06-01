//
// Created by ivaaahn on 24.05.2021.
//

#ifndef __LAB_03_SCENE_HPP__
#define __LAB_03_SCENE_HPP__


#include <memory>
#include "../objects/composite/composite.hpp"
#include "../objects/camera/camera.hpp"
#include "../objects/model/model.hpp"

class Scene {
public:
    Scene();
    ~Scene() = default;

    void addModel(const std::shared_ptr<Object> &model);
    void removeModel(std::size_t model_id);

    void addCamera(const std::shared_ptr<Camera> &camera);
    void removeCamera(std::size_t camera_id);

    std::shared_ptr<Composite> getModels();
    std::vector<std::shared_ptr<Camera>> getCameras();

private:
    std::shared_ptr<Composite> models;
    std::vector<std::shared_ptr<Camera>> cameras; // TODO может камеры тоже запихнуть в модели?
};


#endif //__LAB_03_SCENE_HPP__
