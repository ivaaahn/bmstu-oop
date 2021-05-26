//
// Created by ivaaahn on 24.05.2021.
//

#ifndef __LAB_03_FACADE_HPP__
#define __LAB_03_FACADE_HPP__


#include "../commands/command.hpp"

class Facade {
public:
    void execute(Command &command);
};


#endif //__LAB_03_FACADE_HPP__
