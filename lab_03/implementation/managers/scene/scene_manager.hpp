//
// Created by ivaaahn on 24.05.2021.
//

#ifndef __LAB_03_SCENE_MANAGER_HPP__
#define __LAB_03_SCENE_MANAGER_HPP__


#include <memory>
#include "../manager.hpp"
#include "../../scene/scene.hpp"

using Iterator = std::vector<std::shared_ptr<Object>>::iterator;


class SceneManager : public Manager {
public:
    SceneManager();

    SceneManager(const SceneManager &) = delete;

    SceneManager &operator=(const SceneManager &) = delete;

    ~SceneManager() override = default;

    [[nodiscard]] std::shared_ptr<Scene> getScene() const;

    [[nodiscard]] std::shared_ptr<Camera> getMainCamera() const;

    void setScene(std::shared_ptr<Scene> scene);

    void setMainCamera(const Iterator &it);

private:
    std::shared_ptr<Scene> scene;
    std::weak_ptr<Camera> main_camera;
};

class SceneManagerCreator {
public:
    std::shared_ptr<SceneManager> getManager();

private:
    void createManager();

    std::shared_ptr<SceneManager> manager;
};

#endif //__LAB_03_SCENE_MANAGER_HPP__
