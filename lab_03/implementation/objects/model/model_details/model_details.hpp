//
// Created by ivaaahn on 23.05.2021.
//

#ifndef __LAB_03_MODEL_DETAILS_HPP__
#define __LAB_03_MODEL_DETAILS_HPP__


#include <vector>
#include "point/point.hpp"
#include "edge/edge.hpp"

class ModelDetails {
public:
    ModelDetails() = default;

    ModelDetails(std::vector<Point> &points, std::vector<Edge> &edges);

    ModelDetails(Point &center, std::vector<Point> &points, std::vector<Edge> &edges);

    ~ModelDetails() = default;

    void setCenter(const Point &point);

    void addPoint(const Point &point);

    void addEdge(const Edge &edge);

    [[nodiscard]] const Point &getCenter() const;

    [[nodiscard]] const std::vector<Point> &getPoints() const;

    [[nodiscard]] const std::vector<Edge> &getEdges() const;

    void transform(const Point &move_params, const Point &scale_params, const Point &rotate_params);

private:
    std::vector<Point> points;
    std::vector<Edge> edges;
    Point center{};

    void move(const Point &move_params);
    void scale(const Point &scale_params);
    void rotate(const Point &rotate_params);
};


#endif //__LAB_03_MODEL_DETAILS_HPP__
