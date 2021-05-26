//
// Created by ivaaahn on 23.05.2021.
//

#include "model.hpp"

Model::Model() : details(std::make_shared<ModelDetails>()) {}

Model::Model(std::shared_ptr<ModelDetails> details) : details(std::move(details)) {}

Model::Model(const Model &model) {
    this->details = model.getDetails();
}

void Model::transform(const Point &move_params, const Point &scale_params, const Point &rotate_params) {
    this->details->transform(move_params, scale_params, rotate_params);
}

void Model::accept(std::shared_ptr<Visitor> visitor) {
    visitor->visit(*this);
}

const std::shared_ptr<ModelDetails> Model::getDetails() const {
    return this->details;
}





