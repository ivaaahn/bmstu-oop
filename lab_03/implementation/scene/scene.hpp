//
// Created by ivaaahn on 24.05.2021.
//

#ifndef __LAB_03_SCENE_HPP__
#define __LAB_03_SCENE_HPP__


#include <memory>
#include "objects/composite/composite.hpp"


class Scene {
public:
    Scene();

    ~Scene() = default;

    void addObject(const std::shared_ptr<Object> &object);

    void removeObject(const Iterator &it);

    void accept(std::shared_ptr<Visitor> visitor);


    [[nodiscard]] size_t getCamerasCount() const;

    [[nodiscard]] size_t getModelsCount() const;

    Iterator begin();

    Iterator end();

    [[nodiscard]] ConstIterator begin() const;

    [[nodiscard]] ConstIterator end() const;

    [[nodiscard]] ConstIterator cbegin() const;

    [[nodiscard]] ConstIterator cend() const;

private:
    std::shared_ptr<Composite> objects;

    size_t models_count = 0;
    size_t cameras_count = 0;
};


#endif //__LAB_03_SCENE_HPP__
