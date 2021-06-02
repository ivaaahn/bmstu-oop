//
// Created by ivaaahn on 23.05.2021.
//

#include <iostream>
#include "model_details.hpp"

ModelDetails::ModelDetails(std::vector<Point> &points, std::vector<Edge> &edges)
        : center{}, points(points), edges(edges) {}

ModelDetails::ModelDetails(Point &center, std::vector<Point> &points, std::vector<Edge> &edges) : center(center),
                                                                                                  points(points),
                                                                                                  edges(edges) {}

void ModelDetails::addPoint(const Point &point) {
    this->points.push_back(point);
}

void ModelDetails::addEdge(const Edge &edge) {
    this->edges.push_back(edge);
}

const Point &ModelDetails::getCenter() const {
    return this->center;
}

const std::vector<Point> &ModelDetails::getPoints() const {
    return this->points;
}

const std::vector<Edge> &ModelDetails::getEdges() const {
    return this->edges;
}

void ModelDetails::transform(const Point &move_params, const Point &scale_params, const Point &rotate_params) {
    this->move(-this->center);

    for (auto &point: points)
    {
        point.rotate(rotate_params.getX(), rotate_params.getY(), rotate_params.getZ());
        point.scale(scale_params.getX(), scale_params.getY(), scale_params.getZ());
    }

    this->center.move(move_params.getX(), move_params.getY(), move_params.getZ());
    this->move(this->center);
}

void ModelDetails::setCenter(const Point &point) {
    this->center = point;
}

void ModelDetails::move(const Point &move_params) {
    for (auto &point: points)
        point.move(move_params.getX(), move_params.getY(), move_params.getZ());
}

void ModelDetails::scale(const Point &scale_params) {
    for (auto &point: points)
        point.scale(scale_params.getX(), scale_params.getY(), scale_params.getZ());
}

void ModelDetails::rotate(const Point &rotate_params) {
    for (auto &point: points)
        point.rotate(rotate_params.getX(), rotate_params.getY(), rotate_params.getZ());
}
