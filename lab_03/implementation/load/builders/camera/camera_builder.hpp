//
// Created by ivaaahn on 28.05.2021.
//

#ifndef __LAB_03_CAMERA_BUILDER_HPP__
#define __LAB_03_CAMERA_BUILDER_HPP__


class CameraBuilder {
public:
    CameraBuilder();
    ~CameraBuilder() = default;


    bool isBuild() const;
    void reset();
    void buildPosition(double x, double y, double z);
    void buildAngles(double ax, double ay, double az);

    std::shared_ptr<Camera> get();

private:
    std::shared_ptr<Camera> camera;
};


#endif //__LAB_03_CAMERA_BUILDER_HPP__
