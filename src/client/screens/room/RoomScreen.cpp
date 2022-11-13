/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** RoomScreen.cpp
*/

#include "RoomScreen.hpp"
#include "../../../ecs/System/Draw2D/draw2d.hpp"
#include "../../../ecs/System/Movement/movement.hpp"
#include "../../../exceptions/ScreensExceptions.hpp"

rtype::menu::RoomScreen::RoomScreen(): _nbPlayers(0), _nbReadyPlayers(0), _isReady(false)
{
}

void rtype::menu::RoomScreen::init()
{
    rtype::ecs::system::ISystem *draw2DSystemMenu = new rtype::ecs::system::Draw2DSystem();
    if (draw2DSystemMenu == nullptr)
        throw ScreensExceptions("RoomScreen: Error while creating Draw2DSystem");
    this->_world.addSystem(draw2DSystemMenu);
    rtype::ecs::system::ISystem *movementSystemMenu = new rtype::ecs::system::MovementSystem();
    if (movementSystemMenu == nullptr)
        throw ScreensExceptions("RoomScreen: Error while creating MovementSystem");
    this->_world.addSystem(movementSystemMenu);

    rtype::ecs::entity::Entity *bg = new rtype::ecs::entity::Entity(rtype::ecs::entity::STATIC_SPRITE);
    if (bg == nullptr)
        throw ScreensExceptions("RoomScreen: Error while creating Entity (1)");
    bg->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, bg_x, 0.0f, -0.5f, 0.0f);
    bg->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/bg.png", false, sf::Vector2f(1.f, 1.f), 0);
    this->_world.addEntity(bg);
    rtype::ecs::entity::Entity *stars = new rtype::ecs::entity::Entity(rtype::ecs::entity::STATIC_SPRITE);
    if (stars == nullptr)
        throw ScreensExceptions("RoomScreen: Error while creating Entity (2)");
    stars->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, stars_x, 0.0f, -0.7f, 0.0f);
    stars->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/bg2.png", false, sf::Vector2f(1.f, 1.f), 0);
    this->_world.addEntity(stars);
    rtype::ecs::entity::Entity *planets = new rtype::ecs::entity::Entity(rtype::ecs::entity::STATIC_SPRITE);
    if (planets == nullptr)
        throw ScreensExceptions("RoomScreen: Error while creating Entity (3)");
    planets->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, planets_x, 0.0f, -1.0f, 0.0f);
    planets->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/bg3.png", false, sf::Vector2f(1.f, 1.f), 0);
    this->_world.addEntity(planets);
    rtype::ecs::entity::Entity *bigPlanet = new rtype::ecs::entity::Entity(rtype::ecs::entity::STATIC_SPRITE);
    if (bigPlanet == nullptr)
        throw ScreensExceptions("RoomScreen: Error while creating Entity (4)");
    bigPlanet->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, bigPlanet_x, 700.f, -1.2f, 0.0f);
    bigPlanet->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/bg4.png", false, sf::Vector2f(3.f, 3.f), 0);
    this->_world.addEntity(bigPlanet);

    rtype::ecs::entity::Entity *back = new rtype::ecs::entity::Entity(rtype::ecs::entity::RECTANGLE);
    if (back == nullptr)
        throw ScreensExceptions("RoomScreen: Error while creating Entity (5)");
    back->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 300.f, 100.f, 0.0f, 0.0f);
    sf::Color bgColor(0, 0, 0, 150);
    back->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, 1300.f, 800.f, bgColor, true, 3.0f, sf::Color::Blue);
    this->_world.addEntity(back);
    rtype::ecs::entity::Entity *butt_leave = new rtype::ecs::entity::Entity(rtype::ecs::entity::RECTANGLE);
    if (butt_leave == nullptr)
        throw ScreensExceptions("RoomScreen: Error while creating Entity (6)");
    butt_leave->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 500.f, 850.f, 0.0f, 0.0f);
    butt_leave->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, 300.f, 100.f, sf::Color::Black, true, 3.0f, sf::Color::Blue);
    this->_world.addEntity(butt_leave);
    _buttons.push_back(false);
    rtype::ecs::entity::Entity *leave = new rtype::ecs::entity::Entity(rtype::ecs::entity::TEXT);
    if (leave == nullptr)
        throw ScreensExceptions("RoomScreen: Error while creating Entity (7)");
    leave->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 565.f, 870.f, 0.0f, 0.0f);
    leave->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "Leave", 40.f, sf::Color::Blue, true);
    this->_world.addEntity(leave);
    rtype::ecs::entity::Entity *butt_ready = new rtype::ecs::entity::Entity(rtype::ecs::entity::RECTANGLE);
    if (butt_ready == nullptr)
        throw ScreensExceptions("RoomScreen: Error while creating Entity (8)");
    butt_ready->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 1100.f, 850.f, 0.0f, 0.0f);
    butt_ready->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, 300.f, 100.f, sf::Color::Black, true, 3.0f, sf::Color::Blue);
    this->_world.addEntity(butt_ready);
    _buttons.push_back(false);
    rtype::ecs::entity::Entity *create = new rtype::ecs::entity::Entity(rtype::ecs::entity::TEXT);
    if (create == nullptr)
        throw ScreensExceptions("RoomScreen: Error while creating Entity (9)");
    create->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 1180.f, 870.f, 0.0f, 0.0f);
    create->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "Ready", 40.f, sf::Color::Blue, true);
    this->_world.addEntity(create);
}

int rtype::menu::RoomScreen::handleEvent(rtype::Event &event, rtype::Game *gameEngine)
{
    cleanPlayers();
    if (gameEngine->_client->getGameStart())
        return 7;
    if (gameEngine->_client->getNbPeopleInRoom() != this->_nbPlayers)
        this->_nbPlayers = gameEngine->_client->getNbPeopleInRoom();
    for (size_t i = 0; i < _nbPlayers; i++) {
        rtype::ecs::entity::Entity *player = new rtype::ecs::entity::Entity(rtype::ecs::entity::UNKNOWN);
        if (player == nullptr)
            throw ScreensExceptions("RoomScreen: Error while creating Entity (10)");
        player->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 320.f, 120.f + (i * 100.f), 0.0f, 0.0f);
        player->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, 1260.f, 80.f, sf::Color::Black, true, 3.0f, sf::Color::Blue);
        this->_world.addEntity(player);
        rtype::ecs::entity::Entity *nickname = new rtype::ecs::entity::Entity(rtype::ecs::entity::TEXT);
        if (nickname == nullptr)
            throw ScreensExceptions("RoomScreen: Error while creating Entity (9)");
        nickname->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 360.f, 120.f + (i * 100.f), 0.0f, 0.0f);
        nickname->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "Player " + std::to_string(i), 40.f, sf::Color::Blue, true);
        this->_world.addEntity(nickname);
    }
    if (isButtonPressed(5, gameEngine, event)) {
        _nbPlayers--;
        if (_isReady)
            _nbReadyPlayers--;
        gameEngine->_client->send(message::DISCONNECT);
        saveParalax();
        return 2;
    }
    if (isButtonPressed(7, gameEngine, event) && !_isReady) {
        _isReady = true;
        gameEngine->_client->send(message::READY);
        saveParalax();
    }
    hooverOnButton(event, gameEngine);
    return 0;
}

void rtype::menu::RoomScreen::update(rtype::Game *gameEngine)
{
    if (_buttons.at(0) == true) {
        ecs::component::Drawable2D *leaveButtonCompo = _world.getEntity(5)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        leaveButtonCompo->setOutlineColor(sf::Color::Cyan);

    } else if (_buttons.at(0) == false) {
        ecs::component::Drawable2D *leaveButtonCompo = _world.getEntity(5)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        leaveButtonCompo->setOutlineColor(sf::Color::Blue);
    }
    if (_buttons.at(1) == true) {
        ecs::component::Drawable2D *readyButtonCompo = _world.getEntity(7)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        readyButtonCompo->setOutlineColor(sf::Color::Cyan);

    } else if (_buttons.at(1) == false) {
        ecs::component::Drawable2D *readyButtonCompo = _world.getEntity(7)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        readyButtonCompo->setOutlineColor(sf::Color::Blue);
    }
    paralax();
    this->_world.update(gameEngine);
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

void rtype::menu::RoomScreen::cleanPlayers(void)
{
    if (_world.getEntities().size() == 11) {
        _world.removeEntity(10);
    } else if (_world.getEntities().size() == 12) {
        _world.removeEntity(11);
        _world.removeEntity(10);
    } else if (_world.getEntities().size() == 13) {
        _world.removeEntity(12);
        _world.removeEntity(11);
        _world.removeEntity(10);
    } else if (_world.getEntities().size() == 14) {
        _world.removeEntity(13);
        _world.removeEntity(12);
        _world.removeEntity(11);
        _world.removeEntity(10);
    }
}

void rtype::menu::RoomScreen::hooverOnButton(rtype::Event &event, rtype::Game *gameEngine)
{
    isMouseOnButton(5, gameEngine, event) ? _buttons.at(0) = true : _buttons.at(0) = false;
    isMouseOnButton(7, gameEngine, event) ? _buttons.at(1) = true : _buttons.at(1) = false;
}

void rtype::menu::RoomScreen::saveParalax(void)
{
    ecs::component::Transform *transformCompo = _world.getEntity(0)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
    ecs::component::Transform *transformCompo1 = _world.getEntity(1)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
    ecs::component::Transform *transformCompo2 = _world.getEntity(2)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
    ecs::component::Transform *transformCompo3 = _world.getEntity(3)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
    bg_x = transformCompo->getX();
    stars_x = transformCompo1->getX();
    planets_x = transformCompo2->getX();
    bigPlanet_x = transformCompo3->getX();
}

void rtype::menu::RoomScreen::paralax(void)
{
    ecs::component::Transform *transformCompo = _world.getEntity(0)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
    ecs::component::Transform *transformCompo1 = _world.getEntity(1)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
    ecs::component::Transform *transformCompo2 = _world.getEntity(2)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
    ecs::component::Transform *transformCompo3 = _world.getEntity(3)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
    if (transformCompo->getX() <= -1920) {
        transformCompo->setX(0);
    }
    if (transformCompo1->getX() <= -1920) {
        transformCompo1->setX(0);
    }
    if (transformCompo2->getX() <= -1920) {
        transformCompo2->setX(0);
    }
    if (transformCompo3->getX() <= -264) {
        transformCompo3->setX(1920);
    }
}