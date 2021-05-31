//
// Created by ivaaahn on 24.05.2021.
//

#ifndef __LAB_03_SCENE_MANAGER_HPP__
#define __LAB_03_SCENE_MANAGER_HPP__


#include <memory>
#include "../manager.hpp"
#include "../../scene/scene.hpp"

class SceneManager : public Manager {
public:
    SceneManager();

    SceneManager(const SceneManager &) = delete;

    SceneManager &operator=(const SceneManager &) = delete;

    ~SceneManager() override = default;

    [[nodiscard]] std::shared_ptr<Scene> getScene() const;

    [[nodiscard]] std::shared_ptr<Camera> getCurrentCamera() const;

    void setScene(std::shared_ptr<Scene> scene);

    void setCamera(std::size_t camera_id);

private:
    std::shared_ptr<Scene> scene;
    std::weak_ptr<Camera> current_camera;
};

class SceneManagerCreator {
public:
    std::shared_ptr<SceneManager> getManager();

private:
    void createManager();

    std::shared_ptr<SceneManager> manager;
};

#endif //__LAB_03_SCENE_MANAGER_HPP__
