//
// Created by ivaaahn on 24.05.2021.
//

#include <utility>
#include <memory>

#include "draw_manager.hpp"
#include "objects/composite/composite.hpp"
#include "visitor/draw_visitor/draw_visitor.hpp"

void DrawManager::setDrawer(std::shared_ptr<Drawer> drawer) {
    this->drawer = std::move(drawer);
}

void DrawManager::setCamera(std::shared_ptr<Camera> camera) {
    this->camera = std::move(camera);
}

void DrawManager::draw(const std::shared_ptr<Composite> &composite) {
    auto visitor = std::make_shared<DrawVisitor>(this->drawer, this->camera);
    composite->accept(visitor);
}

void DrawManagerCreator::createManager() {
    static auto manager = std::make_shared<DrawManager>();
    this->manager = manager;
}

std::shared_ptr<DrawManager> DrawManagerCreator::getManager() {
    if (this->manager == nullptr) this->createManager();

    return this->manager;
}