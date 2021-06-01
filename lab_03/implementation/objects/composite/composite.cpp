//
// Created by ivaaahn on 24.05.2021.
//

#include "composite.hpp"

Composite::Composite(const std::shared_ptr<Object> &component) {
    this->objects.push_back(component);
}

Composite::Composite(const std::vector<std::shared_ptr<Object>> &vector) {
    this->objects = vector;
}

bool Composite::add(const std::shared_ptr<Object> &component) {
    this->objects.push_back(component);
    return true;
}

bool Composite::remove(const Iterator &iterator) {
    this->objects.erase(iterator);
    return true;
}

Iterator Composite::begin() {
    return this->objects.begin();
}

Iterator Composite::end() {
    return this->objects.end();
}

bool Composite::is_visible() {
    return false;
}

bool Composite::is_composite() const {
    return true;
}

void Composite::transform(const Point &move_params, const Point &scale_params, const Point &rotate_params) {
    for (auto &elem: this->objects)
        elem->transform(move_params, scale_params, rotate_params);
}

void Composite::accept(std::shared_ptr<Visitor> visitor) {
    for (auto &elem: this->objects)
        elem->accept(visitor);
}

ConstIterator Composite::cbegin() const {
    return this->objects.cbegin();
}

ConstIterator Composite::cend() const {
    return this->objects.cend();
}

ConstIterator Composite::begin() const {
    return this->objects.begin();
}

ConstIterator Composite::end() const {
    return this->objects.end();
}
