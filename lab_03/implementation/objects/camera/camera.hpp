//
// Created by ivaaahn on 24.05.2021.
//

#ifndef __LAB_03_CAMERA_HPP__
#define __LAB_03_CAMERA_HPP__


#include "../object.hpp"
#include "../model/model_details/point/point.hpp"

class Camera : public InvisibleObject {
public:
    Camera() = default;

    explicit Camera(const Point &position);

    ~Camera() override = default;

    void transform(const Point &move_params, const Point &scale_params, const Point &rotate_params) override;

    void accept(std::shared_ptr<Visitor> visitor) override;

    Point getPosition() const;

    void shiftX(double delta);

    void shiftY(double delta);

    void shiftZ(double delta);

private:
    Point position;
};


#endif //__LAB_03_CAMERA_HPP__
