/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** MenuScreen.cpp
*/

#include "MenuScreen.hpp"
#include "../../../ecs/System/Draw2D/Draw2D.hpp"

rtype::menu::MenuScreen::MenuScreen() : _cursorPosition(SOLO)
{
}

void rtype::menu::MenuScreen::init()
{
    rtype::ecs::system::ISystem *draw2DSystemMenu = new rtype::ecs::system::Draw2DSystem();
    this->_world.addSystem(draw2DSystemMenu);
    rtype::ecs::entity::Entity *rectangle = new rtype::ecs::entity::Entity(rtype::ecs::entity::UNKNOWN);
    rectangle->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 200.f, 200.f, 0.0f, 0.0f);
    rectangle->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, 250.f, 50.f, sf::Color::White, false);
    this->_world.addEntity(rectangle);
    rtype::ecs::entity::Entity *text = new rtype::ecs::entity::Entity(rtype::ecs::entity::UNKNOWN);
    text->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 250.f, 210.f, 0.0f, 0.0f);
    text->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "Options", 24.f, sf::Color::Blue, true);
    this->_world.addEntity(text);
}

void rtype::menu::MenuScreen::draw(rtype::Game *gameEngine)
{
    for (auto &system : this->_world.getSystems())
        system->update(this->_world.getEntities(), gameEngine);
}

int rtype::menu::MenuScreen::handleEvent(rtype::Event &event, rtype::Game *gameEngine)
{
    if (isButtonPressed(0, gameEngine, event)) {
        return 4;
    }
    return 0;
}

void rtype::menu::MenuScreen::update()
{
    
}

bool rtype::menu::MenuScreen::isButtonPressed(size_t index, rtype::Game *gameEngine, rtype::Event &event)
{
    ecs::component::Drawable2D *rectangleCompo = _world.getEntity(index)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
    ecs::component::Transform *transformCompo = _world.getEntity(index)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
    if (event.position.x >= (transformCompo->getX() + gameEngine->_window.getPosition().x) && event.position.x <= (transformCompo->getX() + gameEngine->_window.getPosition().x) + rectangleCompo->getWidth() &&
    event.position.y >= (transformCompo->getY() + gameEngine->_window.getPosition().y + 30) && event.position.y <= (transformCompo->getY() + gameEngine->_window.getPosition().y + 30) + rectangleCompo->getHeight()) {
        event.position.x = 0;
        event.position.y = 0;
        return true;
    }
    return false;
}
