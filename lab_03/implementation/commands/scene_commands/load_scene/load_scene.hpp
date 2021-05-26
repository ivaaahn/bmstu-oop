//
// Created by ivaaahn on 23.05.2021.
//

#ifndef __LAB_03_LOAD_SCENE_HPP__
#define __LAB_03_LOAD_SCENE_HPP__


#include "../scene_command.hpp"

class LoadScene : public SceneCommand {
public:
    LoadScene() = delete;

    explicit LoadScene(std::string fileName);


    void execute() override;


    ~LoadScene() override = default;

private:
    std::string fileName;
};


#endif //__LAB_03_LOAD_SCENE_HPP__
