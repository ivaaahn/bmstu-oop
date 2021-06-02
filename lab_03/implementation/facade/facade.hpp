//
// Created by ivaaahn on 24.05.2021.
//

#ifndef __LAB_03_FACADE_HPP__
#define __LAB_03_FACADE_HPP__


#include <memory>
#include "commands/command.hpp"

class Facade {
public:
    void execute(const std::shared_ptr<Command> &command);
};


#endif //__LAB_03_FACADE_HPP__
