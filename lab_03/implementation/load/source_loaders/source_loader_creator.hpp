//
// Created by ivaaahn on 26.05.2021.
//

#ifndef __LAB_03_SOURCE_LOADER_CREATOR_HPP__
#define __LAB_03_SOURCE_LOADER_CREATOR_HPP__

#include <memory>
#include "source_loader.hpp"

class SourceLoaderCreator {
public:
    SourceLoaderCreator() = default;

    virtual ~SourceLoaderCreator() = default;

    virtual std::shared_ptr<SourceLoader> create() = 0;
};

template<typename SourceLoaderType>
class ConSourceLoaderCreator : public SourceLoaderCreator {
public:
    ConSourceLoaderCreator() = default;

    ~ConSourceLoaderCreator() override = default;


    std::shared_ptr<SourceLoader> create() override {
        return std::make_shared<SourceLoaderType>();
    }
};


#endif //__LAB_03_SOURCE_LOADER_CREATOR_HPP__
