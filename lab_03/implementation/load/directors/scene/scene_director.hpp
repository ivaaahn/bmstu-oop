//
// Created by ivaaahn on 24.05.2021.
//

#ifndef __LAB_03_SCENE_DIRECTOR_HPP__
#define __LAB_03_SCENE_DIRECTOR_HPP__


#include "../load_director.hpp"

class SceneDirector : public LoadDirector {
public:
    SceneDirector();
    ~SceneDirector() = default;

    std::shared_ptr<Object> load(const std::string &src_name) override;
};


#endif //__LAB_03_SCENE_DIRECTOR_HPP__
