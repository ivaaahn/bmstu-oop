//
// Created by ivaaahn on 23.05.2021.
//

#ifndef __LAB_03_MODEL_HPP__
#define __LAB_03_MODEL_HPP__


#include <memory>
#include "../object.hpp"
#include "model_details/model_details.hpp"


class Model : public VisibleObject {
public:
    Model();

    explicit Model(std::shared_ptr<ModelDetails> details);

    Model(const Model &model);

    ~Model() override = default;

    void transform(const Point &move_params, const Point &scale_params, const Point &rotate_params) override;

    void accept(std::shared_ptr<Visitor> visitor) override;

    [[nodiscard]] const std::shared_ptr<ModelDetails> getDetails() const;


private:
    std::shared_ptr<ModelDetails> details;
};


#endif //__LAB_03_MODEL_HPP__
