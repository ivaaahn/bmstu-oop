//
// Created by ivaaahn on 24.05.2021.
//

#include "scene.hpp"

#include <utility>

Scene::Scene() : objects(std::make_shared<Composite>()) {}

void Scene::addObject(const std::shared_ptr<Object> &object) {
    this->objects->add(object);

    if (object->is_visible())
        this->models_count++;
    else
        this->cameras_count++;
}

void Scene::removeObject(const Iterator &it) {
    if((*it)->is_visible())
        this->models_count--;
    else
        this->cameras_count--;

    this->objects->remove(it);
}

size_t Scene::getCamerasCount() const {
    return this->cameras_count;
}

size_t Scene::getModelsCount() const {
    return this->models_count;
}

Iterator Scene::begin() {
    return this->objects->begin();
}

Iterator Scene::end() {
    return this->objects->end();
}

void Scene::accept(std::shared_ptr<Visitor> visitor) {
    this->objects->accept(std::move(visitor));
}

ConstIterator Scene::cbegin() const {
    return this->objects->cbegin();
}

ConstIterator Scene::cend() const {
    return this->objects->cend();
}


ConstIterator Scene::begin() const {
    return this->objects->cbegin();
}

ConstIterator Scene::end() const {
    return this->objects->cend();
}
