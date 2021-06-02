//
// Created by ivaaahn on 24.05.2021.
//

#include "facade.hpp"

void Facade::execute(const std::shared_ptr<Command> &command) {
    command->execute();
}
