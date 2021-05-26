//
// Created by ivaaahn on 24.05.2021.
//

#ifndef __LAB_03_EDGE_HPP__
#define __LAB_03_EDGE_HPP__


#include <cstddef>

class Edge {
public:
    Edge() = default;

    Edge(std::size_t point1_id, std::size_t point2_id);

    Edge(const Edge &other) = default;

    ~Edge() = default;

    [[nodiscard]] std::size_t getFirst() const;

    [[nodiscard]] std::size_t getSecond() const;

    void setFirst(std::size_t point_id);

    void setSecond(std::size_t point_id);

private:
    std::size_t point1_id;
    std::size_t point2_id;
};


#endif //__LAB_03_EDGE_HPP__
