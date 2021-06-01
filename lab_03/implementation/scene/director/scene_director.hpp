//
// Created by ivaaahn on 24.05.2021.
//

#ifndef __LAB_03_SCENE_DIRECTOR_HPP__
#define __LAB_03_SCENE_DIRECTOR_HPP__


#include "load/directors/load_director.hpp"

class SceneDirector {
public:
    SceneDirector();

    ~SceneDirector() = default;

    std::shared_ptr<Scene> load(const std::string &src_name);

private:
    std::shared_ptr<SceneLoader> loader;
};


#endif //__LAB_03_SCENE_DIRECTOR_HPP__
