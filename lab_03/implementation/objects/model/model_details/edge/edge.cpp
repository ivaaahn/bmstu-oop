//
// Created by ivaaahn on 24.05.2021.
//

#include "edge.hpp"

Edge::Edge(const size_t point1_id, const size_t point2_id) : point1_id(point1_id), point2_id(point2_id) {}

void Edge::setFirst(const size_t point_id) {
    this->point1_id = point_id;
}

void Edge::setSecond(const size_t point_id) {
    this->point2_id = point_id;
}

std::size_t Edge::getFirst() const {
    return this->point1_id;
}

std::size_t Edge::getSecond() const {
    return this->point2_id;
}
