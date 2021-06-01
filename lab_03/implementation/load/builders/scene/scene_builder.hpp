//
// Created by ivaaahn on 28.05.2021.
//

#ifndef __LAB_03_SCENE_BUILDER_HPP__
#define __LAB_03_SCENE_BUILDER_HPP__

#include <memory>
#include <objects/object.hpp>
#include "scene/scene.hpp"

class SceneBuilder {
public:
    SceneBuilder();

    ~SceneBuilder() = default;

    [[nodiscard]] bool isBuild() const;

    void reset();

    void buildModel(const std::shared_ptr<Object> &model);

    void buildCamera(const std::shared_ptr<Object> &camera);

    std::shared_ptr<Scene> get();

private:
    std::shared_ptr<Scene> scene;
};


#endif //__LAB_03_SCENE_BUILDER_HPP__
