/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** OptionsScreen.cpp
*/

#include "OptionsScreen.hpp"
#include "../../../ecs/System/Draw2D/draw2d.hpp"

rtype::menu::OptionsScreen::OptionsScreen()
{
}

void rtype::menu::OptionsScreen::init()
{
    rtype::ecs::system::ISystem *draw2DSystemMenu = new rtype::ecs::system::Draw2DSystem();
    this->_world.addSystem(draw2DSystemMenu);
    rtype::ecs::entity::Entity *rectangle = new rtype::ecs::entity::Entity(rtype::ecs::entity::RECTANGLE);
    rectangle->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 200.f, 200.f, 0.0f, 0.0f);
    rectangle->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, 250.f, 50.f, sf::Color::White, false);
    this->_world.addEntity(rectangle);
    rtype::ecs::entity::Entity *text = new rtype::ecs::entity::Entity(rtype::ecs::entity::TEXT);
    text->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 250.f, 210.f, 0.0f, 0.0f);
    text->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "Menu", 24.f, sf::Color::Blue, true);
    this->_world.addEntity(text);
    rtype::ecs::entity::Entity *poke = new rtype::ecs::entity::Entity(rtype::ecs::entity::STATIC_SPRITE);
    poke->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 500.f, 50.f, 0.0f, 0.0f);
    poke->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/poke.png", false, sf::Vector2f(1.5f, 1.5f), 0);
    this->_world.addEntity(poke);
}

int rtype::menu::OptionsScreen::handleEvent(rtype::Event &event, rtype::Game *gameEngine)
{
    if (isButtonPressed(0, gameEngine, event)) {
        return 2;
    }
    return 0;
}

void rtype::menu::OptionsScreen::update(rtype::Game *gameEngine)
{
    this->_world.draw(gameEngine);
}

bool rtype::menu::OptionsScreen::isButtonPressed(size_t index, rtype::Game *gameEngine, rtype::Event &event)
{
    ecs::component::Drawable2D *rectangleCompo = _world.getEntity(index)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
    ecs::component::Transform *transformCompo = _world.getEntity(index)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
    if (event.position.x >= (transformCompo->getX() + gameEngine->_window.getPosition().x) && event.position.x <= (transformCompo->getX() + gameEngine->_window.getPosition().x) + rectangleCompo->getWidth() &&
    event.position.y >= (transformCompo->getY() + gameEngine->_window.getPosition().y) && event.position.y <= (transformCompo->getY() + gameEngine->_window.getPosition().y) + rectangleCompo->getHeight()) {
        event.position.x = 0;
        event.position.y = 0;
        return true;
    }
    return false;
}

bool rtype::menu::OptionsScreen::isMouseOnButton(size_t index, rtype::Game *gameEngine, rtype::Event &event)
{
    ecs::component::Drawable2D *rectangleCompo = _world.getEntity(index)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
    ecs::component::Transform *transformCompo = _world.getEntity(index)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
    if (event.global_position.x >= (transformCompo->getX() + gameEngine->_window.getPosition().x) && event.global_position.x <= (transformCompo->getX() + gameEngine->_window.getPosition().x) + rectangleCompo->getWidth() &&
    event.global_position.y >= (transformCompo->getY() + gameEngine->_window.getPosition().y) && event.global_position.y <= (transformCompo->getY() + gameEngine->_window.getPosition().y) + rectangleCompo->getHeight()) {
        return true;
    }
    return false;
}
