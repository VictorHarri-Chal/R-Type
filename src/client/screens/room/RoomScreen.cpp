/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** RoomScreen.cpp
*/

#include "RoomScreen.hpp"
#include "../../../ecs/System/Draw2D/draw2d.hpp"

rtype::menu::RoomScreen::RoomScreen(): _nbPlayers(2), _nbReadyPlayers(0), _isReady(false)
{

}

void rtype::menu::RoomScreen::init()
{
    rtype::ecs::system::ISystem *draw2DSystemMenu = new rtype::ecs::system::Draw2DSystem();
    this->_world.addSystem(draw2DSystemMenu);
    rtype::ecs::entity::Entity *bg = new rtype::ecs::entity::Entity(rtype::ecs::entity::STATIC_SPRITE);
    bg->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 0.f, 0.f, 0.0f, 0.0f);
    bg->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/bg.png", false, sf::Vector2f(1.f, 1.f), 0);
    this->_world.addEntity(bg);
    rtype::ecs::entity::Entity *back = new rtype::ecs::entity::Entity(rtype::ecs::entity::RECTANGLE);
    back->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 300.f, 100.f, 0.0f, 0.0f);
    back->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, 1300.f, 800.f, sf::Color::Black, true, 3.0f, sf::Color::Blue);
    this->_world.addEntity(back);
    rtype::ecs::entity::Entity *butt_leave = new rtype::ecs::entity::Entity(rtype::ecs::entity::RECTANGLE);
    butt_leave->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 500.f, 850.f, 0.0f, 0.0f);
    butt_leave->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, 300.f, 100.f, sf::Color::Black, true, 3.0f, sf::Color::Blue);
    this->_world.addEntity(butt_leave);
    _buttons.push_back(false);
    rtype::ecs::entity::Entity *leave = new rtype::ecs::entity::Entity(rtype::ecs::entity::TEXT);
    leave->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 565.f, 870.f, 0.0f, 0.0f);
    leave->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "Leave", 40.f, sf::Color::Blue, true);
    this->_world.addEntity(leave);
    rtype::ecs::entity::Entity *butt_ready = new rtype::ecs::entity::Entity(rtype::ecs::entity::RECTANGLE);
    butt_ready->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 1100.f, 850.f, 0.0f, 0.0f);
    butt_ready->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, 300.f, 100.f, sf::Color::Black, true, 3.0f, sf::Color::Blue);
    this->_world.addEntity(butt_ready);
    _buttons.push_back(false);
    rtype::ecs::entity::Entity *create = new rtype::ecs::entity::Entity(rtype::ecs::entity::TEXT);
    create->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 1180.f, 870.f, 0.0f, 0.0f);
    create->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "Ready", 40.f, sf::Color::Blue, true);
    this->_world.addEntity(create);
}

int rtype::menu::RoomScreen::handleEvent(rtype::Event &event, rtype::Game *gameEngine)
{
    cleanPlayers();
    for (int i = 0; i < _nbPlayers; i++) {
        rtype::ecs::entity::Entity *player = new rtype::ecs::entity::Entity(rtype::ecs::entity::UNKNOWN);
        player->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 320.f, 120.f + (i * 100.f), 0.0f, 0.0f);
        player->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, 1260.f, 80.f, sf::Color::Black, true, 3.0f, sf::Color::Blue);
        this->_world.addEntity(player);
    }
    if (_nbPlayers >= 2 && _nbReadyPlayers == _nbPlayers)
        return 7;
    if (isButtonPressed(2, gameEngine, event)) {
        _nbPlayers--;
        if (_isReady)
            _nbReadyPlayers--;
        return 5;
    }
    if (isButtonPressed(4, gameEngine, event)) {
        _isReady = true;
        _nbReadyPlayers++;
    }
    hooverOnButton(event, gameEngine);
    return 0;
}

void rtype::menu::RoomScreen::update(rtype::Game *gameEngine)
{
    if (_buttons.at(0) == true) {
        ecs::component::Drawable2D *leaveButtonCompo = _world.getEntity(2)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        leaveButtonCompo->setOutlineColor(sf::Color::Yellow);

    } else if (_buttons.at(0) == false) {
        ecs::component::Drawable2D *leaveButtonCompo = _world.getEntity(2)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        leaveButtonCompo->setOutlineColor(sf::Color::Blue);
    }
    if (_buttons.at(1) == true) {
        ecs::component::Drawable2D *readyButtonCompo = _world.getEntity(4)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        readyButtonCompo->setOutlineColor(sf::Color::Yellow);

    } else if (_buttons.at(1) == false) {
        ecs::component::Drawable2D *readyButtonCompo = _world.getEntity(4)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        readyButtonCompo->setOutlineColor(sf::Color::Blue);
    }
    this->_world.draw(gameEngine);
}

bool rtype::menu::RoomScreen::isButtonPressed(size_t index, rtype::Game *gameEngine, rtype::Event &event)
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

bool rtype::menu::RoomScreen::isMouseOnButton(size_t index, rtype::Game *gameEngine, rtype::Event &event)
{
    ecs::component::Drawable2D *rectangleCompo = _world.getEntity(index)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
    ecs::component::Transform *transformCompo = _world.getEntity(index)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
    if (event.global_position.x >= (transformCompo->getX() + gameEngine->_window.getPosition().x) && event.global_position.x <= (transformCompo->getX() + gameEngine->_window.getPosition().x) + rectangleCompo->getWidth() &&
    event.global_position.y >= (transformCompo->getY() + gameEngine->_window.getPosition().y) && event.global_position.y <= (transformCompo->getY() + gameEngine->_window.getPosition().y) + rectangleCompo->getHeight()) {
        return true;
    }
    return false;
}

bool rtype::menu::RoomScreen::isSurfaceClicked(float x, float y, float width, float height, rtype::Event &event, rtype::Game *gameEngine)
{
    return (event.position.x >= (x + gameEngine->_window.getPosition().x) && event.position.x <= (x + gameEngine->_window.getPosition().x) + width &&
    event.position.y >= (y + gameEngine->_window.getPosition().y) && event.position.y <= (y + gameEngine->_window.getPosition().y) + height);
}

bool rtype::menu::RoomScreen::isMouseOnSurface(float x, float y, float width, float height, rtype::Event &event, rtype::Game *gameEngine)
{
    return (event.global_position.x >= (x + gameEngine->_window.getPosition().x) && event.global_position.x <= (x + gameEngine->_window.getPosition().x) + width &&
    event.global_position.y >= (y + gameEngine->_window.getPosition().y) && event.global_position.y <= (y + gameEngine->_window.getPosition().y) + height);
}

void rtype::menu::RoomScreen::cleanPlayers()
{
    if (_world.getEntities().size() == 7) {
        _world.removeEntity(6);
    } else if (_world.getEntities().size() == 8) {
        _world.removeEntity(7);
        _world.removeEntity(6);
    } else if (_world.getEntities().size() == 9) {
        _world.removeEntity(8);
        _world.removeEntity(7);
        _world.removeEntity(6);
    } else if (_world.getEntities().size() == 10) {
        _world.removeEntity(9);
        _world.removeEntity(8);
        _world.removeEntity(7);
        _world.removeEntity(6);
    }
}

void rtype::menu::RoomScreen::hooverOnButton(rtype::Event &event, rtype::Game *gameEngine)
{
    isMouseOnButton(2, gameEngine, event) ? _buttons.at(0) = true : _buttons.at(0) = false;
    isMouseOnButton(4, gameEngine, event) ? _buttons.at(1) = true : _buttons.at(1) = false;
}