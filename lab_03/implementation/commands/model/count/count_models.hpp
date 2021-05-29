//
// Created by ivaaahn on 23.05.2021.
//

#ifndef __LAB_03_COUNT_MODELS_HPP__
#define __LAB_03_COUNT_MODELS_HPP__


#include <memory>
#include "../model_command.hpp"

// TODO Do I really need it ?!
class CountModels : public ModelCommand {
public:
    CountModels() = delete;

    // TODO Why ref on the ptr?
    explicit CountModels(std::shared_ptr<size_t> &count);

    ~CountModels() override = default;

    void execute() override;

private:
    std::shared_ptr<size_t> &count;
};

#endif //__LAB_03_COUNT_MODELS_HPP__
