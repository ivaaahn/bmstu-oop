//
// Created by ivaaahn on 23.05.2021.
//

#ifndef __LAB_03_LOAD_SCENE_HPP__
#define __LAB_03_LOAD_SCENE_HPP__


#include "commands/scene/scene_command.hpp"

class LoadScene : public SceneCommand {
public:
    LoadScene() = delete;

    explicit LoadScene(std::string filename);

    ~LoadScene() override = default;

    void execute() override;

private:
    std::string filename;
};


#endif //__LAB_03_LOAD_SCENE_HPP__
