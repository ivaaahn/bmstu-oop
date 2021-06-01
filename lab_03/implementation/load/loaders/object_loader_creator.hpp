//
// Created by ivaaahn on 26.05.2021.
//

#ifndef __LAB_03_OBJECT_LOADER_CREATOR_HPP__
#define __LAB_03_OBJECT_LOADER_CREATOR_HPP__

#include <memory>
#include "object_loader.hpp"

class ObjectLoaderCreator {
public:
    ObjectLoaderCreator() = default;

    virtual ~ObjectLoaderCreator() = default;

    virtual std::shared_ptr<ObjectLoader> create() = 0;
};

template<typename SourceLoaderType>
class ConObjectLoaderCreator : public ObjectLoaderCreator {
public:
    ConObjectLoaderCreator() = default;

    ~ConObjectLoaderCreator() override = default;

    std::shared_ptr<ObjectLoader> create() override {
        return std::make_shared<SourceLoaderType>();
    }
};


#endif //__LAB_03_OBJECT_LOADER_CREATOR_HPP__
