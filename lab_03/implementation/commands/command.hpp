//
// Created by ivaaahn on 23.05.2021.
//

#ifndef __LAB_03_COMMAND_HPP__
#define __LAB_03_COMMAND_HPP__

class Command {
public:
    Command() = default;

    virtual ~Command() = default;

    virtual void execute() = 0;
};

#endif //__LAB_03_COMMAND_HPP__
