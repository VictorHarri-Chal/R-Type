/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** IntroScreen.cpp
*/

#include "IntroScreen.hpp"
#include "../../../ecs/System/Draw2D/Draw2D.hpp"

rtype::menu::IntroScreen::IntroScreen()
{

}

void rtype::menu::IntroScreen::init()
{
    rtype::ecs::system::ISystem *draw2DSystemMenu = new rtype::ecs::system::Draw2DSystem();
    this->_world.addSystem(draw2DSystemMenu);
    rtype::ecs::entity::Entity *back = new rtype::ecs::entity::Entity(rtype::ecs::entity::UNKNOWN);
    back->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 300.f, 100.f, 0.0f, 0.0f);
    back->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, 1300.f, 800.f, sf::Color::Black, true, 3.0f, sf::Color::Blue);
    this->_world.addEntity(back);
    rtype::ecs::entity::Entity *butt_validate = new rtype::ecs::entity::Entity(rtype::ecs::entity::UNKNOWN);
    butt_validate->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 840.f, 800.f, 0.0f, 0.0f);
    butt_validate->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, 200.f, 50.f, sf::Color::Black, true, 3.0f, sf::Color::Blue);
    this->_world.addEntity(butt_validate);
    rtype::ecs::entity::Entity *validate = new rtype::ecs::entity::Entity(rtype::ecs::entity::UNKNOWN);
    validate->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 880.f, 810.f, 0.0f, 0.0f);
    validate->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "Validate", 30.f, sf::Color::Blue, true);
    this->_world.addEntity(validate);
}

void rtype::menu::IntroScreen::draw(rtype::Game *gameEngine)
{
    for (auto &system : this->_world.getSystems())
        system->update(this->_world.getEntities(), gameEngine);
}

int rtype::menu::IntroScreen::handleEvent(rtype::Event &event, rtype::Game *gameEngine)
{
    hooverOnButton(event, gameEngine);
    if (isButtonPressed(1, gameEngine, event)) {
        return 2;
    }
    return 0;
}

void rtype::menu::IntroScreen::update()
{   

    
}

bool rtype::menu::IntroScreen::isButtonPressed(size_t index, rtype::Game *gameEngine, rtype::Event &event)
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

bool rtype::menu::IntroScreen::isMouseOnButton(size_t index, rtype::Game *gameEngine, rtype::Event &event)
{
    ecs::component::Drawable2D *rectangleCompo = _world.getEntity(index)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
    ecs::component::Transform *transformCompo = _world.getEntity(index)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
    if (event.global_position.x >= (transformCompo->getX() + gameEngine->_window.getPosition().x) && event.global_position.x <= (transformCompo->getX() + gameEngine->_window.getPosition().x) + rectangleCompo->getWidth() &&
    event.global_position.y >= (transformCompo->getY() + gameEngine->_window.getPosition().y) && event.global_position.y <= (transformCompo->getY() + gameEngine->_window.getPosition().y) + rectangleCompo->getHeight()) {
        return true;
    }
    return false;
}

bool rtype::menu::IntroScreen::isSurfaceClicked(float x, float y, float width, float height, rtype::Event &event, rtype::Game *gameEngine)
{
    return (event.position.x >= (x + gameEngine->_window.getPosition().x) && event.position.x <= (x + gameEngine->_window.getPosition().x) + width &&
    event.position.y >= (y + gameEngine->_window.getPosition().y) && event.position.y <= (y + gameEngine->_window.getPosition().y) + height);
}

bool rtype::menu::IntroScreen::isMouseOnSurface(float x, float y, float width, float height, rtype::Event &event, rtype::Game *gameEngine)
{
    return (event.global_position.x >= (x + gameEngine->_window.getPosition().x) && event.global_position.x <= (x + gameEngine->_window.getPosition().x) + width &&
    event.global_position.y >= (y + gameEngine->_window.getPosition().y) && event.global_position.y <= (y + gameEngine->_window.getPosition().y) + height);
}

void rtype::menu::IntroScreen::hooverOnButton(rtype::Event &event, rtype::Game *gameEngine)
{

}