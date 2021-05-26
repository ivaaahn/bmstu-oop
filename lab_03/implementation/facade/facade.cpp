//
// Created by ivaaahn on 24.05.2021.
//

#include "facade.hpp"

void Facade::execute(Command &command) {
    command.execute();
}
