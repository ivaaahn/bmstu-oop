//
// Created by ivaaahn on 23.05.2021.
//

#ifndef __LAB_03_POINT_HPP__
#define __LAB_03_POINT_HPP__


class Point {
public:
    Point() = default;

    ~Point() = default;

    Point(double x, double y, double z);

    Point(const Point &other) = default;

    Point &operator=(const Point &other) = default;

    Point(const Point &&other) noexcept;

    Point &operator=(Point &&other) noexcept;

    Point operator-() const;

    bool operator==(const Point &other) const noexcept;

    [[nodiscard]] bool equ(const Point &other) const noexcept;

    bool operator!=(const Point &point) const noexcept;

    [[nodiscard]] double getX() const;

    [[nodiscard]] double getY() const;

    [[nodiscard]] double getZ() const;

    void setX(double x);

    void setY(double y);

    void setZ(double z);

    Point operator+(const Point &other);

    Point operator-(const Point &other);

    void move(double dx, double dy, double dz);

    void scale(double kx, double ky, double kz);

    void rotate(double ax, double ay, double az);

    void rotateX(double ax);

    void rotateY(double ay);

    void rotateZ(double az);

    Point relativeTo(const Point &point);

private:
    double x, y, z;
};


#endif //__LAB_03_POINT_HPP__
