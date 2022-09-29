/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** MenuScreen.cpp
*/

#include "MenuScreen.hpp"
#include "../../../ecs/System/Draw2D/Draw2D.hpp"

rtype::menu::MenuScreen::MenuScreen() : _cursorPosition(NEW_GAME)
{
}

void rtype::menu::MenuScreen::init()
{
    std::string textString = "Hello World !";

    rtype::ecs::system::ISystem *draw2DSystemMenu = new rtype::ecs::system::Draw2DSystem();
    this->_world.addSystem(draw2DSystemMenu);
    rtype::ecs::entity::Entity *rectangle = new rtype::ecs::entity::Entity(rtype::ecs::entity::UNKNOWN);
    rectangle->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 200.f, 200.f, 0.0f, 0.0f);
    rectangle->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, 250.f, 50.f, sf::Color::White, false);
    this->_world.addEntity(rectangle);
    rtype::ecs::entity::Entity *text = new rtype::ecs::entity::Entity(rtype::ecs::entity::UNKNOWN);
    text->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 250.f, 210.f, 0.0f, 0.0f);
    text->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, textString, 24.f, sf::Color::Blue, true);
    this->_world.addEntity(text);
    rtype::ecs::entity::Entity *poke = new rtype::ecs::entity::Entity(rtype::ecs::entity::PLAYER);
    poke->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 500.f, 50.f, 0.0f, 0.0f);
    poke->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/poke.png", true);
    this->_world.addEntity(poke);
}

void rtype::menu::MenuScreen::draw(rtype::Game *gameEngine)
{
    for (auto &system : this->_world.getSystems())
        system->update(this->_world.getEntities(), gameEngine);
}

int rtype::menu::MenuScreen::handleEvent(rtype::Event &event)
{
    
    return 0;
}

void rtype::menu::MenuScreen::update()
{
    
}

int rtype::menu::MenuScreen::checkCursorPosition(bool direction)
{
    // if (direction) {
    //     if (_cursorPosition == NEW_GAME) {
    //         _cursorPosition = LOAD_GAME;
    //         return this->_positionsCursor[_cursorPosition];
    //     }
    //     if (_cursorPosition == LOAD_GAME) {
    //         _cursorPosition = EXIT;
    //         return this->_positionsCursor[_cursorPosition];
    //     }
    //     if (_cursorPosition == EXIT)
    //         return this->_positionsCursor[_cursorPosition];
    // } else if (!direction) {
    //     if (_cursorPosition == NEW_GAME)
    //         return this->_positionsCursor[_cursorPosition];
    //     if (_cursorPosition == LOAD_GAME) {
    //         _cursorPosition = NEW_GAME;
    //         return this->_positionsCursor[_cursorPosition];
    //     }
    //     if (_cursorPosition == EXIT) {
    //         _cursorPosition = LOAD_GAME;
    //         return this->_positionsCursor[_cursorPosition];
    //     }
    // }
    return 0;
}
