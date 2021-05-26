//
// Created by ivaaahn on 24.05.2021.
//

#include "file_model_loader.hpp"
#include "../../../../objects/model/model_details/edge/edge.hpp"

#include <fstream>

FileModelLoader::FileModelLoader() : builder(std::make_shared<ModelBuilder>()) {}

FileModelLoader::FileModelLoader(std::shared_ptr<std::ifstream> &src_file) : FileModelLoader() {
    this->src_file = src_file;
}

void FileModelLoader::open(const std::string &src_name) {
    this->src_file = std::make_shared<std::ifstream>(src_name);
    if (!*(this->src_file)) throw FileOpenException(); // TODO: exceptions
}

std::shared_ptr<Object> FileModelLoader::load() {
    this->builder->reset();

//    if (!*(this->src_file)) throw FileOpenException();

    this->loadCenter();
    this->loadPoints();
    this->loadEdges();

    return std::dynamic_pointer_cast<Object>(this->builder->get());
}

void FileModelLoader::close() {
    this->src_file->close();
}

void FileModelLoader::loadCenter() {
    double x, y, z;
    if (!(*(this->src_file) >> x >> y >> z) throw FileFormatException();
    this->builder->buildCenter(Point(x, y, z));
}

void FileModelLoader::loadPoints() {
    size_t points_count = 0;
    *(this->src_file) >> points_count;
    if (points_count <= 1) throw FileFormatException();

    for (size_t i = 0; i < points_count; i++)
    {   double x, y, z;
        if (!(*(this->src_file) >> x >> y >> z)) throw FileFormatException();
        this->builder->buildPoint(Point(x, y, z));
    }
}

void FileModelLoader::loadEdges() {
    size_t edges_count = 0;
    *(this->src_file) >> edges_count;
    if (edges_count < 1) throw FileFormatException();

    for (size_t i = 0; i < edges_count; i++)
    {
        size_t p1_id, p2_id;
        if (!(*(this->src_file) >> p1_id >> p2_id)) throw FileFormatException();
        this->builder->buildEdge(Edge(p1_id, p2_id))
    }
}
