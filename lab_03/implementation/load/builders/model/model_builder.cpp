//
// Created by ivaaahn on 28.05.2021.
//

#include "model_builder.hpp"

ModelBuilder::ModelBuilder() : model_details(nullptr) {}

bool ModelBuilder::isBuild() {
    return this->model_details != nullptr;
}

void ModelBuilder::reset() {
    this->model_details = std::make_shared<ModelDetails>();
}

void ModelBuilder::buildCenter(const Point &point) {
    this->model_details->setCenter(point);
}

void ModelBuilder::buildPoint(const Point &point) {
    this->model_details->addPoint(point);
}

void ModelBuilder::buildEdge(const Edge &edge) {
    this->model_details->addEdge(edge);
}

std::shared_ptr<Model> ModelBuilder::get() {
    return std::make_shared<Model>(this->model_details);
}
