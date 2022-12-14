/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** MultiplayerScreen.cpp
*/

#include "MultiplayerScreen.hpp"
#include "../../../ecs/System/Draw2D/draw2d.hpp"
#include "../../../ecs/System/Movement/movement.hpp"
#include "../../../exceptions/ScreensExceptions.hpp"

rtype::menu::MultiplayerScreen::MultiplayerScreen(): _roomId(0), _actualNbRooms(0)
{
    _slots.push_back(true);
    _slots.push_back(true);
    _slots.push_back(true);
    _slots.push_back(true);
    _slots.push_back(true);
    _slots.push_back(true);
    _slots.push_back(true);
}

void rtype::menu::MultiplayerScreen::initRoom(rtype::Event &event, rtype::Game *gameEngine)
{
    for (size_t i = this->_actualNbRooms; i < gameEngine->_client->getNbRoom(); i++)
        createRoom(event, gameEngine);
    for (size_t i = this->_actualNbRooms; i > gameEngine->_client->getNbRoom(); i--)
        deleteRoom(static_cast<int>(i - 1), 120.f + ((i - 1) * 100.f), event, gameEngine);
    this->_actualNbRooms = gameEngine->_client->getNbRoom();
}

void rtype::menu::MultiplayerScreen::init()
{
    rtype::ecs::system::ISystem *draw2DSystemMenu = new rtype::ecs::system::Draw2DSystem();
    if (draw2DSystemMenu == nullptr)
        throw ScreensExceptions("MultiplayerScreen: Error while creating Draw2DSystem");
    this->_world.addSystem(draw2DSystemMenu);
    rtype::ecs::system::ISystem *movementSystemMenu = new rtype::ecs::system::MovementSystem();
    if (movementSystemMenu == nullptr)
        throw ScreensExceptions("MultiplayerScreen: Error while creating MovementSystem");
    this->_world.addSystem(movementSystemMenu);

    rtype::ecs::entity::Entity *bg = new rtype::ecs::entity::Entity(rtype::ecs::entity::STATIC_SPRITE);
    if (bg == nullptr)
        throw ScreensExceptions("MultiplayerScreen: Error while creating Entity (1)");
    bg->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, bg_x, 0.0f, -0.5f, 0.0f);
    bg->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/bg.png", false, sf::Vector2f(1.f, 1.f), 0);
    this->_world.addEntity(bg);
    rtype::ecs::entity::Entity *stars = new rtype::ecs::entity::Entity(rtype::ecs::entity::STATIC_SPRITE);
    if (stars == nullptr)
        throw ScreensExceptions("MultiplayerScreen: Error while creating Entity (2)");
    stars->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, stars_x, 0.0f, -0.7f, 0.0f);
    stars->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/bg2.png", false, sf::Vector2f(1.f, 1.f), 0);
    this->_world.addEntity(stars);
    rtype::ecs::entity::Entity *planets = new rtype::ecs::entity::Entity(rtype::ecs::entity::STATIC_SPRITE);
    if (planets == nullptr)
        throw ScreensExceptions("MultiplayerScreen: Error while creating Entity (3)");
    planets->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, planets_x, 0.0f, -1.0f, 0.0f);
    planets->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/bg3.png", false, sf::Vector2f(1.f, 1.f), 0);
    this->_world.addEntity(planets);
    rtype::ecs::entity::Entity *bigPlanet = new rtype::ecs::entity::Entity(rtype::ecs::entity::STATIC_SPRITE);
    if (bigPlanet == nullptr)
        throw ScreensExceptions("MultiplayerScreen: Error while creating Entity (4)");
    bigPlanet->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, bigPlanet_x, 700.f, -1.2f, 0.0f);
    bigPlanet->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/bg4.png", false, sf::Vector2f(3.f, 3.f), 0);
    this->_world.addEntity(bigPlanet);
    rtype::ecs::entity::Entity *back = new rtype::ecs::entity::Entity(rtype::ecs::entity::RECTANGLE);
    if (back == nullptr)
        throw ScreensExceptions("MultiplayerScreen: Error while creating Entity (5)");
    back->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 300.f, 100.f, 0.0f, 0.0f);
    sf::Color bgColor(0, 0, 0, 150);
    back->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, 1300.f, 800.f, bgColor, true, 3.0f, sf::Color::Blue);
    this->_world.addEntity(back);
    rtype::ecs::entity::Entity *butt_disconnect = new rtype::ecs::entity::Entity(rtype::ecs::entity::RECTANGLE);
    if (butt_disconnect == nullptr)
        throw ScreensExceptions("MultiplayerScreen: Error while creating Entity (6)");
    butt_disconnect->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 500.f, 850.f, 0.0f, 0.0f);
    butt_disconnect->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, 300.f, 100.f, sf::Color::Black, true, 3.0f, sf::Color::Blue);
    this->_world.addEntity(butt_disconnect);
    _buttons.push_back(false);
    rtype::ecs::entity::Entity *disconnect = new rtype::ecs::entity::Entity(rtype::ecs::entity::TEXT);
    if (disconnect == nullptr)
        throw ScreensExceptions("MultiplayerScreen: Error while creating Entity (7)");
    disconnect->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 545.f, 870.f, 0.0f, 0.0f);
    disconnect->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "Disconnect", 40.f, sf::Color::Blue, true);
    this->_world.addEntity(disconnect);
    rtype::ecs::entity::Entity *butt_create = new rtype::ecs::entity::Entity(rtype::ecs::entity::RECTANGLE);
    if (butt_create == nullptr)
        throw ScreensExceptions("MultiplayerScreen: Error while creating Entity (8)");
    butt_create->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 1100.f, 850.f, 0.0f, 0.0f);
    butt_create->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, 300.f, 100.f, sf::Color::Black, true, 3.0f, sf::Color::Blue);
    this->_world.addEntity(butt_create);
    _buttons.push_back(false);
    rtype::ecs::entity::Entity *create = new rtype::ecs::entity::Entity(rtype::ecs::entity::TEXT);
    if (create == nullptr)
        throw ScreensExceptions("MultiplayerScreen: Error while creating Entity (9)");
    create->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 1170.f, 870.f, 0.0f, 0.0f);
    create->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "Create", 40.f, sf::Color::Blue, true);
    this->_world.addEntity(create);
    for (int i = 0; i < 7; i++) {
        rtype::ecs::entity::Entity *emplySlot = new rtype::ecs::entity::Entity(rtype::ecs::entity::TEXT);
        if (emplySlot == nullptr)
            throw ScreensExceptions("MultiplayerScreen: Error while creating Entity (10)");
        emplySlot->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 860.f, 140.f + (i * 100.f), 0.0f, 0.0f);
        emplySlot->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "Empty Slot", 30.f, sf::Color::White, false);
        this->_world.addEntity(emplySlot);
    }
}

int rtype::menu::MultiplayerScreen::handleEvent(rtype::Event &event, rtype::Game *gameEngine)
{
    if (this->_actualNbRooms != gameEngine->_client->getNbRoom())
        initRoom(event, gameEngine);
    // for (size_t i = 0; i < _slots.size(); i++)
    //     // if (!_slots.at(static_cast<int>(i)) && isSurfaceClicked(1400.f, 120.f + (i * 100.f) + 20.f, 150.f, 40.f, event, gameEngine)) {
    //     //     // gameEngine->_client->send(message::request::DELETE, static_cast<int>(i));
    //     //     // deleteRoom(static_cast<int>(i), 120.f + (i * 100.f), event, gameEngine);
    //     // }
    // for (size_t j = 0; j < _slots.size(); j++)
    //     if (joinRoom(static_cast<int>(j), 120.f + (j * 100.f), event, gameEngine)) {
    //         gameEngine->_client->send(message::JOIN, j);
    //         return 6;
    //     }
    // if (isButtonPressed(7, gameEngine, event))
    //     gameEngine->_client->send(message::CREATE);
    hooverOnButton(event, gameEngine);
    if (isButtonPressed(5, gameEngine, event))
        return 2;
    return 0;
}

void rtype::menu::MultiplayerScreen::update(rtype::Game *gameEngine)
{
    // gameEngine->_client->receive()
    if (_buttons.at(0)) {
        ecs::component::Drawable2D *disconnectButtonCompo = _world.getEntity(5)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        disconnectButtonCompo->setOutlineColor(sf::Color::Cyan);

    } else if (!_buttons.at(0)) {
        ecs::component::Drawable2D *disconnectButtonCompo = _world.getEntity(5)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        disconnectButtonCompo->setOutlineColor(sf::Color::Blue);
    }
    if (_buttons.at(1)) {
        ecs::component::Drawable2D *createButtonCompo = _world.getEntity(7)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        createButtonCompo->setOutlineColor(sf::Color::Cyan);

    } else if (!_buttons.at(1)) {
        ecs::component::Drawable2D *createButtonCompo = _world.getEntity(7)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        createButtonCompo->setOutlineColor(sf::Color::Blue);
    }
    paralax();
    this->_world.update(gameEngine);
    this->_world.draw(gameEngine);
}

bool rtype::menu::MultiplayerScreen::isButtonPressed(size_t index, rtype::Game *gameEngine, rtype::Event &event)
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

bool rtype::menu::MultiplayerScreen::isMouseOnButton(size_t index, rtype::Game *gameEngine, rtype::Event &event)
{
    ecs::component::Drawable2D *rectangleCompo = _world.getEntity(index)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
    ecs::component::Transform *transformCompo = _world.getEntity(index)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
    if (event.global_position.x >= (transformCompo->getX() + gameEngine->_window.getPosition().x) && event.global_position.x <= (transformCompo->getX() + gameEngine->_window.getPosition().x) + rectangleCompo->getWidth() &&
    event.global_position.y >= (transformCompo->getY() + gameEngine->_window.getPosition().y) && event.global_position.y <= (transformCompo->getY() + gameEngine->_window.getPosition().y) + rectangleCompo->getHeight()) {
        return true;
    }
    return false;
}

bool rtype::menu::MultiplayerScreen::isSurfaceClicked(float x, float y, float width, float height, rtype::Event &event, rtype::Game *gameEngine)
{
    return (event.position.x >= (x + gameEngine->_window.getPosition().x) && event.position.x <= (x + gameEngine->_window.getPosition().x) + width &&
    event.position.y >= (y + gameEngine->_window.getPosition().y) && event.position.y <= (y + gameEngine->_window.getPosition().y) + height);
}

bool rtype::menu::MultiplayerScreen::isMouseOnSurface(float x, float y, float width, float height, rtype::Event &event, rtype::Game *gameEngine)
{
    return (event.global_position.x >= (x + gameEngine->_window.getPosition().x) && event.global_position.x <= (x + gameEngine->_window.getPosition().x) + width &&
    event.global_position.y >= (y + gameEngine->_window.getPosition().y) && event.global_position.y <= (y + gameEngine->_window.getPosition().y) + height);
}

int rtype::menu::MultiplayerScreen::addRoom(float slot)
{
    room_t room;

    switch (static_cast<int>(slot)) {
        case 120:
            room.slot = 0;
            break;
        case 220:
            room.slot = 1;
            break;
        case 320:
            room.slot = 2;
            break;
        case 420:
            room.slot = 3;
            break;
        case 520:
            room.slot = 4;
            break;
        case 620:
            room.slot = 5;
            break;
        case 720:
            room.slot = 6;
            break;
        default:
            break;
    };
    room.id = _roomId;
    _roomId++;
    room.name = "Room " + std::to_string(room.id);
    room.currPlayers = 0;
    room.isOpen = true;
    _rooms.push_back(room);
    return room.slot;
}

float rtype::menu::MultiplayerScreen::checkForFreeSlot()
{
    if (_slots.at(0)) {
        _slots.at(0) = false;
        return 120.f;
    }
    if (_slots.at(1)) {
        _slots.at(1) = false;
        return 220.f;
    }
    if (_slots.at(2)) {
        _slots.at(2) = false;
        return 320.f;
    }
    if (_slots.at(3)) {
        _slots.at(3) = false;
        return 420.f;
    }
    if (_slots.at(4)) {
        _slots.at(4) = false;
        return 520.f;
    }
    if (_slots.at(5)) {
        _slots.at(5) = false;
        return 620.f;
    }
    if (_slots.at(6)) {
        _slots.at(6) = false;
        return 720.f;
    }
    return 0.f;
}

void rtype::menu::MultiplayerScreen::createRoom(rtype::Event &event, rtype::Game *gameEngine)
{
    (void)event;
    (void)gameEngine;
    float freeSpot = checkForFreeSlot();
    if (freeSpot != 0.f) {
        int slot = addRoom(freeSpot);
        std::string roomName;
        for (size_t i = 0; i < _rooms.size(); i++) {
            if (_rooms.at(i).slot == slot)
                roomName = _rooms.at(i).name;
        }
        rtype::ecs::entity::Entity *butt_room = new rtype::ecs::entity::Entity(rtype::ecs::entity::UNKNOWN);
        if (butt_room == nullptr)
            throw ScreensExceptions("RoomScreen: Error while creating entity (11)");
        butt_room->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 320.f, freeSpot, 0.0f, 0.0f);
        butt_room->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, 1260.f, 80.f, sf::Color::Black, true, 3.0f, sf::Color::Blue);
        this->_world.addEntity(butt_room);
        rtype::ecs::entity::Entity *del_room = new rtype::ecs::entity::Entity(rtype::ecs::entity::UNKNOWN);
        if (del_room == nullptr)
            throw ScreensExceptions("RoomScreen: Error while creating entity (12)");
        del_room->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 1400.f, freeSpot + 20.f, 0.0f, 0.0f);
        del_room->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, 150.f, 40.f, sf::Color::Black, true, 3.0f, sf::Color::Blue);
        this->_world.addEntity(del_room);
        rtype::ecs::entity::Entity *del = new rtype::ecs::entity::Entity(rtype::ecs::entity::UNKNOWN);
        if (del == nullptr)
            throw ScreensExceptions("RoomScreen: Error while creating entity (13)");
        del->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 1440.f, freeSpot + 25.f, 0.0f, 0.0f);
        del->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "Delete", 25.f, sf::Color::White, false);
        this->_world.addEntity(del);
        rtype::ecs::entity::Entity *name = new rtype::ecs::entity::Entity(rtype::ecs::entity::UNKNOWN);
        if (name == nullptr)
            throw ScreensExceptions("RoomScreen: Error while creating entity (14)");
        name->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 400.f, freeSpot + 25.f, 0.0f, 0.0f);
        name->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, roomName, 40.f, sf::Color::White, false);
        this->_world.addEntity(name);
    }
}

bool rtype::menu::MultiplayerScreen::joinRoom(int slotPos, float offset, rtype::Event &event, rtype::Game *gameEngine)
{
    if (!_slots.at(slotPos) && isSurfaceClicked(320.f, offset, 1260.f, 80.f, event, gameEngine) && !isSurfaceClicked(1400.f, offset + 20.f, 150.f, 40.f, event, gameEngine)) {
        return true;
        event.position.x = 0;
        event.position.y = 0;
    }
    return false;
}

void rtype::menu::MultiplayerScreen::deleteRoom(int slotPos, float offset, rtype::Event &event, rtype::Game *gameEngine)
{
    (void)gameEngine;
    for (size_t i = 0; i < _world.getEntities().size(); i++) {
        ecs::component::Transform *transformCompo = _world.getEntity(i)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
        if ((transformCompo->getY() == offset) && (transformCompo->getX() == 320.f))
            _world.removeEntity(i);
    }
    for (size_t i = 0; i < _world.getEntities().size(); i++) {
        ecs::component::Transform *transformCompo = _world.getEntity(i)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
        if ((transformCompo->getY() == (offset + 20.f)) && (transformCompo->getX() == 1400.f))
            _world.removeEntity(i);
    }
    for (size_t i = 0; i < _world.getEntities().size(); i++) {
        ecs::component::Transform *transformCompo = _world.getEntity(i)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
        if ((transformCompo->getY() == (offset + 25.f)) && (transformCompo->getX() == 1440.f))
            _world.removeEntity(i);
    }
    for (size_t i = 0; i < _world.getEntities().size(); i++) {
        ecs::component::Transform *transformCompo = _world.getEntity(i)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
        if ((transformCompo->getY() == (offset + 25.f)) && (transformCompo->getX() == 400.f))
            _world.removeEntity(i);
    }
    for (size_t j = 0; j < _rooms.size(); j++) {
        if (_rooms.at(j).slot == slotPos)
            _rooms.erase(_rooms.begin()+j);
    }
    _slots.at(slotPos) = true;
    event.position.x = 0;
    event.position.y = 0;
}

void rtype::menu::MultiplayerScreen::hooverOnButton(rtype::Event &event, rtype::Game *gameEngine)
{
    isMouseOnButton(5, gameEngine, event) ? _buttons.at(0) = true : _buttons.at(0) = false;
    isMouseOnButton(7, gameEngine, event) ? _buttons.at(1) = true : _buttons.at(1) = false;
    for (size_t i = 0; i < _slots.size(); i++) {
        for (size_t j = 0; j < _world.getEntities().size(); j++) {
            ecs::component::Transform *transformCompo = _world.getEntity(j)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
            if ((transformCompo->getY() ==  (120.f + (i * 100.f)) + 20.f) && (transformCompo->getX() == 1400.f)) {
                ecs::component::Drawable2D *delButtonCompo = _world.getEntity(j)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
                delButtonCompo->setOutlineColor(sf::Color::Blue);
            }
        }
        for (size_t k = 0; k < _world.getEntities().size(); k++) {
                ecs::component::Transform *transformCompo = _world.getEntity(k)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
                if ((transformCompo->getY() == (120.f + (i * 100.f))) && (transformCompo->getX() == 320.f)) {
                    ecs::component::Drawable2D *roomButtonCompo = _world.getEntity(k)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
                    roomButtonCompo->setOutlineColor(sf::Color::Blue);
                }
            }
        if (!_slots.at(i) && isMouseOnSurface(1400.f, (120.f + (i * 100.f)) + 20.f, 150.f, 40.f, event, gameEngine)) {
            for (size_t j = 0; j < _world.getEntities().size(); j++) {
                ecs::component::Transform *transformCompo = _world.getEntity(j)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
                if ((transformCompo->getY() ==  (120.f + (i * 100.f)) + 20.f) && (transformCompo->getX() == 1400.f)) {
                    ecs::component::Drawable2D *delButtonCompo = _world.getEntity(j)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
                    delButtonCompo->setOutlineColor(sf::Color::Magenta);
                }
            }
        }
        if (!_slots.at(i) && isMouseOnSurface(320.f, (120.f + (i * 100.f)), 1260.f, 80.f, event, gameEngine)) {
            for (size_t k = 0; k < _world.getEntities().size(); k++) {
                ecs::component::Transform *transformCompo = _world.getEntity(k)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
                if ((transformCompo->getY() == (120.f + (i * 100.f))) && (transformCompo->getX() == 320.f)) {
                    ecs::component::Drawable2D *roomButtonCompo = _world.getEntity(k)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
                    roomButtonCompo->setOutlineColor(sf::Color::Cyan);
                }
            }
        }
    }
}

void rtype::menu::MultiplayerScreen::saveParalax(void)
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

void rtype::menu::MultiplayerScreen::paralax(void)
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