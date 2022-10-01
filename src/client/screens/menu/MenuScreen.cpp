/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** MenuScreen.cpp
*/

#include "MenuScreen.hpp"
#include "../../../ecs/System/Draw2D/Draw2D.hpp"

rtype::menu::MenuScreen::MenuScreen()
{
}

void rtype::menu::MenuScreen::init()
{
    rtype::ecs::system::ISystem *draw2DSystemMenu = new rtype::ecs::system::Draw2DSystem();
    this->_world.addSystem(draw2DSystemMenu);

    rtype::ecs::entity::Entity *butt_solo = new rtype::ecs::entity::Entity(rtype::ecs::entity::UNKNOWN);
    butt_solo->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 870.f, 390.f, 0.0f, 0.0f);
    butt_solo->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, 70.f, 50.f, sf::Color::Transparent, false);
    this->_world.addEntity(butt_solo);
    rtype::ecs::entity::Entity *solo = new rtype::ecs::entity::Entity(rtype::ecs::entity::UNKNOWN);
    solo->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 870.f, 400.f, 0.0f, 0.0f);
    solo->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "Solo", 30.f, sf::Color::Blue, true);
    this->_world.addEntity(solo);
    rtype::ecs::entity::Entity *butt_multi = new rtype::ecs::entity::Entity(rtype::ecs::entity::UNKNOWN);
    butt_multi->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 870.f, 460.f, 0.0f, 0.0f);
    butt_multi->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, 170.f, 50.f, sf::Color::Transparent, false);
    this->_world.addEntity(butt_multi);
    rtype::ecs::entity::Entity *multi = new rtype::ecs::entity::Entity(rtype::ecs::entity::UNKNOWN);
    multi->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 870.f, 470.f, 0.0f, 0.0f);
    multi->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "Multiplayer", 30.f, sf::Color::Blue, true);
    this->_world.addEntity(multi);
    rtype::ecs::entity::Entity *butt_htp = new rtype::ecs::entity::Entity(rtype::ecs::entity::UNKNOWN);
    butt_htp->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 870.f, 530.f, 0.0f, 0.0f);
    butt_htp->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, 180.f, 50.f, sf::Color::Transparent, false);
    this->_world.addEntity(butt_htp);
    rtype::ecs::entity::Entity *htp = new rtype::ecs::entity::Entity(rtype::ecs::entity::UNKNOWN);
    htp->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 870.f, 540.f, 0.0f, 0.0f);
    htp->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "How to play", 30.f, sf::Color::Blue, true);
    this->_world.addEntity(htp);
    rtype::ecs::entity::Entity *butt_options = new rtype::ecs::entity::Entity(rtype::ecs::entity::UNKNOWN);
    butt_options->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 870.f, 600.f, 0.0f, 0.0f);
    butt_options->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, 120.f, 50.f, sf::Color::Transparent, false);
    this->_world.addEntity(butt_options);
    rtype::ecs::entity::Entity *options = new rtype::ecs::entity::Entity(rtype::ecs::entity::UNKNOWN);
    options->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 870.f, 610.f, 0.0f, 0.0f);
    options->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "Options", 30.f, sf::Color::Blue, true);
    this->_world.addEntity(options);
    rtype::ecs::entity::Entity *butt_quit = new rtype::ecs::entity::Entity(rtype::ecs::entity::UNKNOWN);
    butt_quit->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 870.f, 670.f, 0.0f, 0.0f);
    butt_quit->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, 70.f, 50.f, sf::Color::Transparent, false);
    this->_world.addEntity(butt_quit);
    rtype::ecs::entity::Entity *quit = new rtype::ecs::entity::Entity(rtype::ecs::entity::UNKNOWN);
    quit->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 870.f, 680.f, 0.0f, 0.0f);
    quit->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "Quit", 30.f, sf::Color::Blue, true);
    this->_world.addEntity(quit);
}

void rtype::menu::MenuScreen::draw(rtype::Game *gameEngine)
{
    for (auto &system : this->_world.getSystems())
        system->update(this->_world.getEntities(), gameEngine);
}

int rtype::menu::MenuScreen::handleEvent(rtype::Event &event, rtype::Game *gameEngine)
{
    if (isButtonPressed(2, gameEngine, event)) {
        return 5;
    }
    if (isButtonPressed(6, gameEngine, event)) {
        return 4;
    }
    if (isButtonPressed(8, gameEngine, event)) {
        return 10;
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
