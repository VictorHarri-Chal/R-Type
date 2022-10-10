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
    butt_solo->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, 70.f, 50.f, sf::Color::Transparent, true, 3.0f, sf::Color::Transparent);
    this->_world.addEntity(butt_solo);
    _buttons.push_back(false);
    rtype::ecs::entity::Entity *solo = new rtype::ecs::entity::Entity(rtype::ecs::entity::UNKNOWN);
    solo->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 870.f, 400.f, 0.0f, 0.0f);
    solo->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "Solo", 30.f, sf::Color::Blue, true);
    this->_world.addEntity(solo);

    rtype::ecs::entity::Entity *butt_multi = new rtype::ecs::entity::Entity(rtype::ecs::entity::UNKNOWN);
    butt_multi->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 870.f, 460.f, 0.0f, 0.0f);
    butt_multi->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, 170.f, 50.f, sf::Color::Transparent, true, 3.0f, sf::Color::Transparent);
    this->_world.addEntity(butt_multi);
    _buttons.push_back(false);
    rtype::ecs::entity::Entity *multi = new rtype::ecs::entity::Entity(rtype::ecs::entity::UNKNOWN);
    multi->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 870.f, 470.f, 0.0f, 0.0f);
    multi->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "Multiplayer", 30.f, sf::Color::Blue, true);
    this->_world.addEntity(multi);

    rtype::ecs::entity::Entity *butt_htp = new rtype::ecs::entity::Entity(rtype::ecs::entity::UNKNOWN);
    butt_htp->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 870.f, 530.f, 0.0f, 0.0f);
    butt_htp->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, 190.f, 50.f, sf::Color::Transparent, true, 3.0f, sf::Color::Transparent);
    this->_world.addEntity(butt_htp);
    _buttons.push_back(false);
    rtype::ecs::entity::Entity *htp = new rtype::ecs::entity::Entity(rtype::ecs::entity::UNKNOWN);
    htp->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 870.f, 540.f, 0.0f, 0.0f);
    htp->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "How to play", 30.f, sf::Color::Blue, true);
    this->_world.addEntity(htp);

    rtype::ecs::entity::Entity *butt_options = new rtype::ecs::entity::Entity(rtype::ecs::entity::UNKNOWN);
    butt_options->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 870.f, 600.f, 0.0f, 0.0f);
    butt_options->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, 120.f, 50.f, sf::Color::Transparent, true, 3.0f, sf::Color::Transparent);
    this->_world.addEntity(butt_options);
    _buttons.push_back(false);
    rtype::ecs::entity::Entity *options = new rtype::ecs::entity::Entity(rtype::ecs::entity::UNKNOWN);
    options->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 870.f, 610.f, 0.0f, 0.0f);
    options->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "Options", 30.f, sf::Color::Blue, true);
    this->_world.addEntity(options);

    rtype::ecs::entity::Entity *butt_quit = new rtype::ecs::entity::Entity(rtype::ecs::entity::UNKNOWN);
    butt_quit->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 870.f, 670.f, 0.0f, 0.0f);
    butt_quit->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, 70.f, 50.f, sf::Color::Transparent, true, 3.0f, sf::Color::Transparent);
    this->_world.addEntity(butt_quit);
    _buttons.push_back(false);
    rtype::ecs::entity::Entity *quit = new rtype::ecs::entity::Entity(rtype::ecs::entity::UNKNOWN);
    quit->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 870.f, 680.f, 0.0f, 0.0f);
    quit->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "Quit", 30.f, sf::Color::Blue, true);
    this->_world.addEntity(quit);
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
    isMouseOnButton(0, gameEngine, event) ? _buttons.at(0) = true : _buttons.at(0) = false;
    isMouseOnButton(2, gameEngine, event) ? _buttons.at(1) = true : _buttons.at(1) = false;
    isMouseOnButton(4, gameEngine, event) ? _buttons.at(2) = true : _buttons.at(2) = false;
    isMouseOnButton(6, gameEngine, event) ? _buttons.at(3) = true : _buttons.at(3) = false;
    isMouseOnButton(8, gameEngine, event) ? _buttons.at(4) = true : _buttons.at(4) = false;
    return 0;
}

void rtype::menu::MenuScreen::update(rtype::Game *gameEngine)
{
    if (_buttons.at(0) == true) {
        ecs::component::Drawable2D *soloButtonCompo = _world.getEntity(0)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        soloButtonCompo->setOutlineColor(sf::Color::Yellow);
        
    } else if (_buttons.at(0) == false) {
        ecs::component::Drawable2D *soloButtonCompo = _world.getEntity(0)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        soloButtonCompo->setOutlineColor(sf::Color::Transparent);
    }
    if (_buttons.at(1) == true) {
        ecs::component::Drawable2D *multiButtonCompo = _world.getEntity(2)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        multiButtonCompo->setOutlineColor(sf::Color::Yellow);
        
    } else if (_buttons.at(1) == false) {
        ecs::component::Drawable2D *multiButtonCompo = _world.getEntity(2)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        multiButtonCompo->setOutlineColor(sf::Color::Transparent);
    }
    if (_buttons.at(2) == true) {
        ecs::component::Drawable2D *htpButtonCompo = _world.getEntity(4)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        htpButtonCompo->setOutlineColor(sf::Color::Yellow);
        
    } else if (_buttons.at(2) == false) {
        ecs::component::Drawable2D *htpButtonCompo = _world.getEntity(4)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        htpButtonCompo->setOutlineColor(sf::Color::Transparent);
    }
    if (_buttons.at(3) == true) {
        ecs::component::Drawable2D *optionsButtonCompo = _world.getEntity(6)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        optionsButtonCompo->setOutlineColor(sf::Color::Yellow);
        
    } else if (_buttons.at(3) == false) {
        ecs::component::Drawable2D *optionsButtonCompo = _world.getEntity(6)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        optionsButtonCompo->setOutlineColor(sf::Color::Transparent);
    }
    if (_buttons.at(4) == true) {
        ecs::component::Drawable2D *quitButtonCompo = _world.getEntity(8)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        quitButtonCompo->setOutlineColor(sf::Color::Yellow);
        
    } else if (_buttons.at(4) == false) {
        ecs::component::Drawable2D *quitButtonCompo = _world.getEntity(8)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        quitButtonCompo->setOutlineColor(sf::Color::Transparent);
    }
    this->_world.draw(gameEngine);
}

bool rtype::menu::MenuScreen::isButtonPressed(size_t index, rtype::Game *gameEngine, rtype::Event &event)
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

bool rtype::menu::MenuScreen::isMouseOnButton(size_t index, rtype::Game *gameEngine, rtype::Event &event)
{
    ecs::component::Drawable2D *rectangleCompo = _world.getEntity(index)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
    ecs::component::Transform *transformCompo = _world.getEntity(index)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
    if (event.global_position.x >= (transformCompo->getX() + gameEngine->_window.getPosition().x) && event.global_position.x <= (transformCompo->getX() + gameEngine->_window.getPosition().x) + rectangleCompo->getWidth() &&
    event.global_position.y >= (transformCompo->getY() + gameEngine->_window.getPosition().y) && event.global_position.y <= (transformCompo->getY() + gameEngine->_window.getPosition().y) + rectangleCompo->getHeight()) {
        return true;
    }
    return false;
}
