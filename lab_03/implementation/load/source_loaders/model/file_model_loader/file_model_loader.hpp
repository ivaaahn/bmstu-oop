//
// Created by ivaaahn on 24.05.2021.
//

#ifndef __LAB_03_FILE_MODEL_LOADER_HPP__
#define __LAB_03_FILE_MODEL_LOADER_HPP__


#include "../source_model_loader.hpp"

class FileModelLoader : public SourceModelLoader {
    FileModelLoader();
    explicit FileModelLoader(std::shared_ptr<std::ifstream> &src_file);
    void open(const std::string &src_name) override;
    std::shared_ptr<Object> load() override;
    void close() override;

private:
    std::shared_ptr<ModelBuilder> builder;
    std::shared_ptr<std::ifstream> src_file;

    void loadCenter();
    void loadPoints();
    void loadEdges();
};


#endif //__LAB_03_FILE_MODEL_LOADER_HPP__
