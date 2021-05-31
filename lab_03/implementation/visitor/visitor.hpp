//
// Created by ivaaahn on 24.05.2021.
//

#ifndef __LAB_03_VISITOR_HPP__
#define __LAB_03_VISITOR_HPP__

class Model;
class Camera;
class Composite;

class Visitor {
public:
    Visitor() = default;
    virtual ~Visitor() = default;

    virtual void visit(const Camera &camera) = 0;
    virtual void visit(const Model &model) = 0;
    virtual void visit(const Composite &composite) = 0;
};


#endif //__LAB_03_VISITOR_HPP__
