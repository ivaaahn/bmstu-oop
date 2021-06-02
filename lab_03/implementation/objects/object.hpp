//
// Created by ivaaahn on 23.05.2021.
//

#ifndef __LAB_03_OBJECT_HPP__
#define __LAB_03_OBJECT_HPP__

#include <memory>
#include <vector>

#include <visitor/visitor.hpp>
#include "model/model_details/point/point.hpp"

class Object;

using Iterator = std::vector<std::shared_ptr<Object>>::iterator;
using ConstIterator = std::vector<std::shared_ptr<Object>>::const_iterator;


class Object {
public:
    Object() = default;

    virtual ~Object() = default;

    virtual void accept(std::shared_ptr<Visitor> visitor) = 0;

    virtual bool add(const std::shared_ptr<Object> &) { return false; };

    virtual bool remove(const Iterator &) { return false; };

    virtual Iterator begin() { return Iterator(); };

    virtual Iterator end() { return Iterator(); };

    virtual ConstIterator begin() const { return ConstIterator(); };

    virtual ConstIterator end() const { return ConstIterator(); };

    virtual ConstIterator cbegin() const { return ConstIterator(); };

    virtual ConstIterator cend() const { return ConstIterator(); };

    virtual bool is_visible() { return false; }

    [[nodiscard]] virtual bool is_composite() const { return false; };

    virtual void transform(const Point &move_params, const Point &scale_params, const Point &rotate_params) = 0;
};

class VisibleObject : public Object {
public:
    VisibleObject() = default;

    ~VisibleObject() override = default;

    bool is_visible() override { return true; }
};

class InvisibleObject : public Object {
public:
    InvisibleObject() = default;

    ~InvisibleObject() override = default;

    bool is_visible() override { return false; }
};


#endif //__LAB_03_OBJECT_HPP__
