/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** MultiplayerScreen.cpp
*/

#include "MultiplayerScreen.hpp"
#include "../../../ecs/System/Draw2D/Draw2D.hpp"

rtype::menu::MultiplayerScreen::MultiplayerScreen()
{
}

void rtype::menu::MultiplayerScreen::init()
{
    rtype::ecs::system::ISystem *draw2DSystemMenu = new rtype::ecs::system::Draw2DSystem();
    this->_world.addSystem(draw2DSystemMenu);
    rtype::ecs::entity::Entity *bg = new rtype::ecs::entity::Entity(rtype::ecs::entity::PLAYER);
    bg->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 0.f, 0.f, 0.0f, 0.0f);
    bg->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/bg.png", true);
    this->_world.addEntity(bg);
    rtype::ecs::entity::Entity *back = new rtype::ecs::entity::Entity(rtype::ecs::entity::UNKNOWN);
    back->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 300.f, 100.f, 0.0f, 0.0f);
    back->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, 1300.f, 800.f, sf::Color::Black, true, 3.0f, sf::Color::Blue);
    this->_world.addEntity(back);
    rtype::ecs::entity::Entity *butt_disconnect = new rtype::ecs::entity::Entity(rtype::ecs::entity::UNKNOWN);
    butt_disconnect->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 500.f, 850.f, 0.0f, 0.0f);
    butt_disconnect->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, 300.f, 100.f, sf::Color::Black, true, 3.0f, sf::Color::Blue);
    this->_world.addEntity(butt_disconnect);
    _buttons.push_back(false);
    rtype::ecs::entity::Entity *disconnect = new rtype::ecs::entity::Entity(rtype::ecs::entity::UNKNOWN);
    disconnect->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 545.f, 870.f, 0.0f, 0.0f);
    disconnect->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "Disconnect", 40.f, sf::Color::Blue, true);
    this->_world.addEntity(disconnect);
    rtype::ecs::entity::Entity *butt_create = new rtype::ecs::entity::Entity(rtype::ecs::entity::UNKNOWN);
    butt_create->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 1100.f, 850.f, 0.0f, 0.0f);
    butt_create->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, 300.f, 100.f, sf::Color::Black, true, 3.0f, sf::Color::Blue);
    this->_world.addEntity(butt_create);
    _buttons.push_back(false);
    rtype::ecs::entity::Entity *create = new rtype::ecs::entity::Entity(rtype::ecs::entity::UNKNOWN);
    create->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 1170.f, 870.f, 0.0f, 0.0f);
    create->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "Create", 40.f, sf::Color::Blue, true);
    this->_world.addEntity(create);

    // rtype::ecs::entity::Entity *text = new rtype::ecs::entity::Entity(rtype::ecs::entity::UNKNOWN);
    // text->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 250.f, 210.f, 0.0f, 0.0f);
    // text->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "Multiplayer", 24.f, sf::Color::Blue, true);
    // this->_world.addEntity(text);
}

void rtype::menu::MultiplayerScreen::draw(rtype::Game *gameEngine)
{
    for (auto &system : this->_world.getSystems())
        system->update(this->_world.getEntities(), gameEngine);
}

int rtype::menu::MultiplayerScreen::handleEvent(rtype::Event &event, rtype::Game *gameEngine)
{
    if (isButtonPressed(2, gameEngine, event)) {
        return 2;
    }
    if (isButtonPressed(4, gameEngine, event)) {
        addRoom();
    }
    isMouseOnButton(2, gameEngine, event) ? _buttons.at(0) = true : _buttons.at(0) = false;
    isMouseOnButton(4, gameEngine, event) ? _buttons.at(1) = true : _buttons.at(1) = false;
    return 0;
}

void rtype::menu::MultiplayerScreen::update()
{
    for (size_t i = 0; i < _rooms.size(); i++) {
        rtype::ecs::entity::Entity *room_test = new rtype::ecs::entity::Entity(rtype::ecs::entity::UNKNOWN);
        room_test->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 320.f, 120.f + (i * 100.f), 0.0f, 0.0f);
        room_test->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, 1260.f, 80.f, sf::Color::Black, true, 3.0f, sf::Color::Blue);
        this->_world.addEntity(room_test);
    }
    if (_buttons.at(0) == true) {
        ecs::component::Drawable2D *disconnectButtonCompo = _world.getEntity(2)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        disconnectButtonCompo->setOutlineColor(sf::Color::Yellow);
        
    } else if (_buttons.at(0) == false) {
        ecs::component::Drawable2D *disconnectButtonCompo = _world.getEntity(2)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        disconnectButtonCompo->setOutlineColor(sf::Color::Blue);
    }
    if (_buttons.at(1) == true) {
        ecs::component::Drawable2D *createButtonCompo = _world.getEntity(4)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        createButtonCompo->setOutlineColor(sf::Color::Yellow);
        
    } else if (_buttons.at(1) == false) {
        ecs::component::Drawable2D *createButtonCompo = _world.getEntity(4)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        createButtonCompo->setOutlineColor(sf::Color::Blue);
    }
}

bool rtype::menu::MultiplayerScreen::isButtonPressed(size_t index, rtype::Game *gameEngine, rtype::Event &event)
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

bool rtype::menu::MultiplayerScreen::isMouseOnButton(size_t index, rtype::Game *gameEngine, rtype::Event &event)
{
    ecs::component::Drawable2D *rectangleCompo = _world.getEntity(index)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
    ecs::component::Transform *transformCompo = _world.getEntity(index)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
    if (event.global_position.x >= (transformCompo->getX() + gameEngine->_window.getPosition().x) && event.global_position.x <= (transformCompo->getX() + gameEngine->_window.getPosition().x) + rectangleCompo->getWidth() &&
    event.global_position.y >= (transformCompo->getY() + gameEngine->_window.getPosition().y + 30) && event.global_position.y <= (transformCompo->getY() + gameEngine->_window.getPosition().y + 30) + rectangleCompo->getHeight()) {
        return true;
    }
    return false;
}

void rtype::menu::MultiplayerScreen::addRoom()
{
    room_t room;

    room.id = _rooms.size();
    room.name = "La Playa";
    room.currPlayers = 0;
    room.isOpen = true;
    _rooms.push_back(room);
}
