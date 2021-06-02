//
// Created by ivaaahn on 26.05.2021.
//

#ifndef __LAB_03_REGISTRATION_MAKER_HPP__
#define __LAB_03_REGISTRATION_MAKER_HPP__


#include "../solution/solution.hpp"

class BaseRegistrationMaker {
public:
    BaseRegistrationMaker() = default;
    virtual ~BaseRegistrationMaker() = default;
    virtual void makeRegistration(Solution &solution) = 0;
};

class RegistrationMaker : public BaseRegistrationMaker {
public:
    RegistrationMaker() = default;
    ~RegistrationMaker() override = default;
    void makeRegistration(Solution &solution) override;
};


#endif //__LAB_03_REGISTRATION_MAKER_HPP__
