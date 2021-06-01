//
// Created by ivaaahn on 24.05.2021.
//

#ifndef __LAB_03_COMPOSITE_HPP__
#define __LAB_03_COMPOSITE_HPP__


#include "objects/object.hpp"

class Visitor;

class Composite : public Object {
public:
    Composite() = default;

    explicit Composite(const std::shared_ptr<Object> &component);

    explicit Composite(const std::vector<std::shared_ptr<Object>> &vector);

    bool add(const std::shared_ptr<Object> &component) override;

    bool remove(const Iterator &iterator) override;

    Iterator begin() override;
    Iterator end() override;

    [[nodiscard]] ConstIterator begin() const override;
    [[nodiscard]] ConstIterator end() const override;

    [[nodiscard]] ConstIterator cbegin() const override;
    [[nodiscard]] ConstIterator cend() const override;

    bool is_visible() override;

    [[nodiscard]] bool is_composite() const override;

    void transform(const Point &move_params, const Point &scale_params, const Point &rotate_params) override;

    void accept(std::shared_ptr<Visitor> visitor) override;

private:
    std::vector<std::shared_ptr<Object>> objects;
};


#endif //__LAB_03_COMPOSITE_HPP__
