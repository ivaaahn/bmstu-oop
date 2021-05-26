//
// Created by ivaaahn on 23.05.2021.
//

#ifndef __LAB_03_OBJECT_HPP__
#define __LAB_03_OBJECT_HPP__

#include <memory>

#include <visitor.h>

//#include <objects/model/model_details/point/point.h>

#include <vector>
#include "model/model_details/point/point.hpp"

class Object;
class Visitor;

using Iterator = std::vector<std::shared_ptr<Object>>::iterator;


class Object {
public:
    Object() = default;

    virtual ~Object() = default;

    virtual bool add(const std::shared_ptr<Object> &) { return false; };

    virtual bool remove(const Iterator &) { return false; };

    virtual Iterator begin() { return Iterator(); };

    virtual Iterator end() { return Iterator(); };

    virtual bool is_visible() { return false; }

    virtual bool is_composite() const { return false; };

    virtual void accept(std::shared_ptr<Visitor> visitor) = 0;

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
