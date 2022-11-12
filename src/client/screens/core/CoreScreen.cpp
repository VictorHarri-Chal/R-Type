/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** CoreScreen.cpp
*/

#include "CoreScreen.hpp"
#include "../../../ecs/System/Draw2D/draw2d.hpp"
#include "../../../ecs/System/Movement/movement.hpp"
#include "../../../exceptions/ScreensExceptions.hpp"

rtype::menu::CoreScreen::CoreScreen(size_t nbPlayers) : _isPlayerNumInit(false), _currWave(1), _nbPlayers(nbPlayers)
{
}

void rtype::menu::CoreScreen::init()
{
    rtype::ecs::system::ISystem *draw2DSystem = new rtype::ecs::system::Draw2DSystem();
    if (draw2DSystem == nullptr)
        throw ScreensExceptions("CoreScreen: Error while creating Draw2DSystem");
    this->_world.addSystem(draw2DSystem);
    rtype::ecs::system::ISystem *mouvementSystem = new rtype::ecs::system::MovementSystem();
    if (mouvementSystem == nullptr)
        throw ScreensExceptions("CoreScreen: Error while creating MouvementSystem");
    this->_world.addSystem(mouvementSystem);
    rtype::ecs::entity::Entity *bg = new rtype::ecs::entity::Entity(rtype::ecs::entity::STATIC_SPRITE);
    if (bg == nullptr)
        throw ScreensExceptions("SoloScreen: Error while creating Entity (1)");
    bg->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, bg_x, 0.0f, -0.5f, 0.0f);
    bg->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
    bg->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/bg.png", false, sf::Vector2f(1.f, 1.f), 0);
    this->_world.addEntity(bg);
    rtype::ecs::entity::Entity *stars = new rtype::ecs::entity::Entity(rtype::ecs::entity::STATIC_SPRITE);
    if (stars == nullptr)
        throw ScreensExceptions("SoloScreen: Error while creating Entity (2)");
    stars->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, stars_x, 0.0f, -0.7f, 0.0f);
    stars->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
    stars->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/bg2.png", false, sf::Vector2f(1.f, 1.f), 0);
    this->_world.addEntity(stars);
    rtype::ecs::entity::Entity *planets = new rtype::ecs::entity::Entity(rtype::ecs::entity::STATIC_SPRITE);
    if (planets == nullptr)
        throw ScreensExceptions("SoloScreen: Error while creating Entity (3)");
    planets->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, planets_x, 0.0f, -1.0f, 0.0f);
    planets->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
    planets->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/bg3.png", false, sf::Vector2f(1.f, 1.f), 0);
    this->_world.addEntity(planets);
    rtype::ecs::entity::Entity *bigPlanet = new rtype::ecs::entity::Entity(rtype::ecs::entity::STATIC_SPRITE);
    if (bigPlanet == nullptr)
        throw ScreensExceptions("SoloScreen: Error while creating Entity (4)");
    bigPlanet->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, bigPlanet_x, 700.f, -1.2f, 0.0f);
    bigPlanet->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
    bigPlanet->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/bg4.png", false, sf::Vector2f(3.f, 3.f), 0);
    this->_world.addEntity(bigPlanet);
    this->initPlayersEntities();
    // this->createEnemyEntity(650.0f, 50.0f);
}

void rtype::menu::CoreScreen::initPlayersEntities(void)
{
    if (this->_nbPlayers == 2) {
        rtype::ecs::entity::Entity *player1 = new rtype::ecs::entity::Entity(rtype::ecs::entity::PLAYER1);
        rtype::ecs::entity::Entity *player2 = new rtype::ecs::entity::Entity(rtype::ecs::entity::PLAYER2);

        if (player1 == nullptr)
            throw ScreensExceptions("CoreScreen: Error while creating Entity (5)");
        if (player2 == nullptr)
            throw ScreensExceptions("CoreScreen: Error while creating Entity (5)");

        player1->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 500.f, 50.f, 0.0f, 0.0f);
        player1->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
        player1->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
        player1->addComponent<ecs::component::Recruit>(rtype::ecs::component::SHIP);
        player1->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/ships.png", true,
            sf::Vector2f(4.f, 4.f), 0, sf::IntRect(0, 0, 33, 17));
        this->_world.addEntity(player1);
        player2->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 500.f, 250.f, 0.0f, 0.0f);
        player2->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
        player2->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
        player2->addComponent<ecs::component::Recruit>(rtype::ecs::component::SHIP);
        player2->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/ships.png", true,
            sf::Vector2f(4.f, 4.f), 0, sf::IntRect(0, 17, 33, 17));
        this->_world.addEntity(player2);
    }

    if (this->_nbPlayers == 3) {
        rtype::ecs::entity::Entity *player1 = new rtype::ecs::entity::Entity(rtype::ecs::entity::PLAYER1);
        rtype::ecs::entity::Entity *player2 = new rtype::ecs::entity::Entity(rtype::ecs::entity::PLAYER2);
        rtype::ecs::entity::Entity *player3 = new rtype::ecs::entity::Entity(rtype::ecs::entity::PLAYER3);

        if (player1 == nullptr)
            throw ScreensExceptions("CoreScreen: Error while creating Entity (5)");
        if (player2 == nullptr)
            throw ScreensExceptions("CoreScreen: Error while creating Entity (5)");
        if (player3 == nullptr)
            throw ScreensExceptions("CoreScreen: Error while creating Entity (5)");

        player1->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 500.f, 50.f, 0.0f, 0.0f);
        player1->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
        player1->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
        player1->addComponent<ecs::component::Recruit>(rtype::ecs::component::SHIP);
        player1->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/ships.png", true,
            sf::Vector2f(4.f, 4.f), 0, sf::IntRect(0, 0, 33, 17));
        this->_world.addEntity(player1);
        player2->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 500.f, 250.f, 0.0f, 0.0f);
        player2->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
        player2->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
        player2->addComponent<ecs::component::Recruit>(rtype::ecs::component::SHIP);
        player2->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/ships.png", true,
            sf::Vector2f(4.f, 4.f), 0, sf::IntRect(0, 17, 33, 17));
        this->_world.addEntity(player2);
        player3->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 500.f, 450.f, 0.0f, 0.0f);
        player3->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
        player3->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
        player3->addComponent<ecs::component::Recruit>(rtype::ecs::component::SHIP);
        player3->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/ships.png", true,
            sf::Vector2f(4.f, 4.f), 0, sf::IntRect(0, 34, 33, 17));
        this->_world.addEntity(player3);
    }

    if (this->_nbPlayers == 4) {
        rtype::ecs::entity::Entity *player1 = new rtype::ecs::entity::Entity(rtype::ecs::entity::PLAYER1);
        rtype::ecs::entity::Entity *player2 = new rtype::ecs::entity::Entity(rtype::ecs::entity::PLAYER2);
        rtype::ecs::entity::Entity *player3 = new rtype::ecs::entity::Entity(rtype::ecs::entity::PLAYER3);
        rtype::ecs::entity::Entity *player4 = new rtype::ecs::entity::Entity(rtype::ecs::entity::PLAYER4);

        if (player1 == nullptr)
            throw ScreensExceptions("CoreScreen: Error while creating Entity (5)");
        if (player2 == nullptr)
            throw ScreensExceptions("CoreScreen: Error while creating Entity (5)");
        if (player3 == nullptr)
            throw ScreensExceptions("CoreScreen: Error while creating Entity (5)");
        if (player4 == nullptr)
            throw ScreensExceptions("CoreScreen: Error while creating Entity (5)");

        player1->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 500.f, 50.f, 0.0f, 0.0f);
        player1->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
        player1->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
        player1->addComponent<ecs::component::Recruit>(rtype::ecs::component::SHIP);
        player1->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/ships.png", true,
            sf::Vector2f(4.f, 4.f), 0, sf::IntRect(0, 0, 33, 17));
        this->_world.addEntity(player1);
        player2->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 500.f, 250.f, 0.0f, 0.0f);
        player2->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
        player2->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
        player2->addComponent<ecs::component::Recruit>(rtype::ecs::component::SHIP);
        player2->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/ships.png", true,
            sf::Vector2f(4.f, 4.f), 0, sf::IntRect(0, 17, 33, 17));
        this->_world.addEntity(player2);
        player3->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 500.f, 450.f, 0.0f, 0.0f);
        player3->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
        player3->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
        player3->addComponent<ecs::component::Recruit>(rtype::ecs::component::SHIP);
        player3->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/ships.png", true,
            sf::Vector2f(4.f, 4.f), 0, sf::IntRect(0, 34, 33, 17));
        this->_world.addEntity(player3);
        player4->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 500.f, 650.f, 0.0f, 0.0f);
        player4->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
        player4->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
        player4->addComponent<ecs::component::Recruit>(rtype::ecs::component::SHIP);
        player4->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/ships.png", true,
            sf::Vector2f(4.f, 4.f), 0, sf::IntRect(0, 51, 33, 17));
        this->_world.addEntity(player4);
    }
}

void rtype::menu::CoreScreen::createEnemyEntity(float x, float y)
{
    rtype::ecs::entity::Entity *enemy = new rtype::ecs::entity::Entity(rtype::ecs::entity::ENEMY);
    if (enemy == nullptr)
        throw ScreensExceptions("SoloScreen: Error while creating enemy entity");
    enemy->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, x, y, 0.0f, 0.15f);
    enemy->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
    enemy->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
    enemy->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/zigzag.png", true,
        sf::Vector2f(3.f, 3.f), 0, sf::IntRect(34, 34, 32, 32));
    enemy->addComponent<ecs::component::Zigzag>(rtype::ecs::component::SHIP, 1);
    this->_world.addEntity(enemy);
}

int rtype::menu::CoreScreen::handleEvent(rtype::Event &event, rtype::Game *gameEngine)
{
    this->initPlayerNumber(gameEngine);

    for (size_t i = 0; i < _world.getEntities().size(); i++) {
        if (_world.getEntity(i)->getEntityType() == _playerNumber) {
            managePlayer(i, event, gameEngine);
            break;
        }
    }
    return 0;
}

void rtype::menu::CoreScreen::update(rtype::Game *gameEngine)
{
    paralax();
    // spawnEnemiesFromScript();
    // manageEnemiesShooting();
    // handleWindowBorder();
    updateEntities(gameEngine);
    destroySprites();
    this->_world.update(gameEngine);
    this->_world.draw(gameEngine);
}

void rtype::menu::CoreScreen::initPlayerNumber(rtype::Game *gameEngine)
{
    gameEngine->_client->lockMutex();
    if (!_isPlayerNumInit) {
        std::string tmp = gameEngine->_client->getPlayerNumber();
        if (tmp == "1")
            _playerNumber = rtype::ecs::entity::PLAYER1;
        if (tmp == "2")
            _playerNumber = rtype::ecs::entity::PLAYER2;
        if (tmp == "3")
            _playerNumber = rtype::ecs::entity::PLAYER3;
        if (tmp == "4")
            _playerNumber = rtype::ecs::entity::PLAYER4;
        _isPlayerNumInit = true;
    }
    gameEngine->_client->unlockMutex();
}

bool rtype::menu::CoreScreen::isButtonPressed(size_t index, rtype::Game *gameEngine, rtype::Event &event)
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

bool rtype::menu::CoreScreen::isMouseOnButton(size_t index, rtype::Game *gameEngine, rtype::Event &event)
{
    ecs::component::Drawable2D *rectangleCompo = _world.getEntity(index)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
    ecs::component::Transform *transformCompo = _world.getEntity(index)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
    if (event.global_position.x >= (transformCompo->getX() + gameEngine->_window.getPosition().x) && event.global_position.x <= (transformCompo->getX() + gameEngine->_window.getPosition().x) + rectangleCompo->getWidth() &&
    event.global_position.y >= (transformCompo->getY() + gameEngine->_window.getPosition().y) && event.global_position.y <= (transformCompo->getY() + gameEngine->_window.getPosition().y) + rectangleCompo->getHeight()) {
        return true;
    }
    return false;
}

void rtype::menu::CoreScreen::managePlayer(size_t entityId, rtype::Event &event, rtype::Game *gameEngine)
{
    ecs::component::IShip *shipCompo = _world.getEntity(entityId)->getComponent<ecs::component::IShip>(ecs::component::compoType::SHIP);

    managePlayerMovement(event, gameEngine);
    managePlayerShot(shipCompo, event, gameEngine);
}

void rtype::menu::CoreScreen::managePlayerMovement(rtype::Event &event, rtype::Game *gameEngine)
{
    if (event.key.right && !event.key.left) {
        gameEngine->_client->send(message::MOVE, "R");
    }
    if (event.key.left && !event.key.right) {
        gameEngine->_client->send(message::MOVE, "L");
    }
    if (event.key.up && !event.key.down) {
        gameEngine->_client->send(message::MOVE, "U");
    }
    if (event.key.down && !event.key.up) {
        gameEngine->_client->send(message::MOVE, "D");
    }
}

void rtype::menu::CoreScreen::managePlayerShot(ecs::component::IShip *shipCompo, rtype::Event &event, rtype::Game *gameEngine)
{
    if (shipCompo->getClock().getElapsedTime() >= shipCompo->getCadency()) {
        if (event.key.code == ' ') {
            gameEngine->_client->send(message::SHOOT, "S");
            event.key.code = '\0';
            shipCompo->restartClock();
        }
    }
}

void rtype::menu::CoreScreen::destroySprites(void)
{
    for (size_t i = 0; i < _world.getEntities().size(); i++) {
        ecs::component::Transform *transformCompo = _world.getEntity(i)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
        if (_world.getEntity(i)->getEntityType() == rtype::ecs::entity::ENEMY_PROJECTILE ||
        _world.getEntity(i)->getEntityType() == rtype::ecs::entity::ALLY_PROJECTILE) {
            if (transformCompo->getX() > 1920 || transformCompo->getX() < -100 || transformCompo->getY() < -100 || transformCompo->getY() > 1280) {
                _world.removeEntity(i);
                break;
            }
        }
        if (_world.getEntity(i)->hasCompoType(rtype::ecs::component::compoType::ALIVE)) {
            ecs::component::Alive *aliveCompo = _world.getEntity(i)->getComponent<ecs::component::Alive>(ecs::component::compoType::ALIVE);
            if (!aliveCompo->getAlive()) {
                if (_world.getEntity(i)->hasCompoType(ecs::component::compoType::SHIP) )
                    createParticle(transformCompo->getX(), transformCompo->getY());
                _world.removeEntity(i);
            }
        }
    }
}

void rtype::menu::CoreScreen::createParticle(float x, float y)
{
    rtype::ecs::entity::Entity *explosion = new rtype::ecs::entity::Entity(rtype::ecs::entity::PARTICLE);
    if (explosion == nullptr)
        throw ScreensExceptions("Corescreen: Error while creating particle entity");
    explosion->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, x, y, 0.0f, 0.0f);
    explosion->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
    explosion->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
    explosion->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/explosion.png", true, sf::Vector2f(4.f, 4.f), 0, sf::IntRect(95, 50, 35, 35));
    this->_world.addEntity(explosion);
}

void rtype::menu::CoreScreen::manageEnemiesShooting(void)
{
    for (size_t i = 0; i < _world.getEntities().size(); i++) {
        if (_world.getEntity(i)->getEntityType() == rtype::ecs::entity::ENEMY) {
            auto shipCompo = _world.getEntity(i)->getComponent<ecs::component::IShip>(ecs::component::compoType::SHIP);
            if (shipCompo->getShipType() == ecs::component::shipType::ZIGZAG || shipCompo->getShipType() == ecs::component::shipType::RUSHER ||
                shipCompo->getShipType() == ecs::component::shipType::TURRET) {
                  if (shipCompo->getClock().getElapsedTime() >= shipCompo->getCadency()) {
                    ecs::component::Transform *transformCompo = _world.getEntity(i)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
                    rtype::ecs::entity::Entity *shot = new rtype::ecs::entity::Entity(rtype::ecs::entity::ENEMY_PROJECTILE);
                    if (shot == nullptr)
                        throw ScreensExceptions("Error: Can't create a entity (7)");
                    shot->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, transformCompo->getX() - 15.f, transformCompo->getY() + 40.f, -20.0f, 0.0f);
                    shot->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
                    shot->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
                    shot->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/projectile.png", true, sf::Vector2f(1.f, 1.f), 180, sf::IntRect(165, 133, 50, 17));
                    this->_world.addEntity(shot);
                    shipCompo->restartClock();
                }
            } else if (shipCompo->getShipType() == ecs::component::shipType::BOSS) {
                if (shipCompo->getClock().getElapsedTime() >= shipCompo->getCadency()) {
                    ecs::component::Transform *transformCompo = _world.getEntity(i)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
                    rtype::ecs::entity::Entity *mine = new rtype::ecs::entity::Entity(rtype::ecs::entity::ENEMY_PROJECTILE);
                    if (mine == nullptr)
                        throw ScreensExceptions("Error: Can't create a entity (10)");
                    mine->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, transformCompo->getX() + 220.f, transformCompo->getY() + 10.f, 0.0f, -2.0f);
                    mine->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
                    mine->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
                    mine->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/mine.png", true, sf::Vector2f(4.f, 4.f), 0, sf::IntRect(0, 0, 18, 18));
                    this->_world.addEntity(mine);
                    shipCompo->restartClock();
                }
            }
        }
    }
}

void rtype::menu::CoreScreen::generateEnemy(int currWave, int shipType, float x, float y)
{
    if (shipType == 1) {
        rtype::ecs::entity::Entity *enemy = new rtype::ecs::entity::Entity(rtype::ecs::entity::ENEMY);
        if (enemy == nullptr)
            throw ScreensExceptions("SoloScreen: Error while creating enemy entity");
        enemy->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, x, y, 0.0f, 0.0f);
        enemy->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
        enemy->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
        enemy->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/zigzag.png", true, sf::Vector2f(3.f, 3.f), 0, sf::IntRect(34, 34, 32, 32));
        enemy->addComponent<ecs::component::Zigzag>(rtype::ecs::component::SHIP, currWave);
        this->_world.addEntity(enemy);
    } else if (shipType == 2) {
        rtype::ecs::entity::Entity *enemy = new rtype::ecs::entity::Entity(rtype::ecs::entity::ENEMY);
        if (enemy == nullptr)
            throw ScreensExceptions("SoloScreen: Error while creating enemy entity");
        enemy->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, x, y, 0.0f, 0.0f);
        enemy->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
        enemy->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
        enemy->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/rusher.png", true, sf::Vector2f(2.f, 2.f), 0, sf::IntRect(50, 0, 65, 60));
        enemy->addComponent<ecs::component::Rusher>(rtype::ecs::component::SHIP, currWave);
        this->_world.addEntity(enemy);
    } else if (shipType == 3) {
        rtype::ecs::entity::Entity *enemy = new rtype::ecs::entity::Entity(rtype::ecs::entity::ENEMY);
        if (enemy == nullptr)
            throw ScreensExceptions("SoloScreen: Error while creating enemy entity");
        enemy->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, x, y, 0.0f, 0.0f);
        enemy->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
        enemy->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
        enemy->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/kamikaze.png", true, sf::Vector2f(2.f, 2.f), 0, sf::IntRect(75, 50, 60, 50));
        enemy->addComponent<ecs::component::Kamikaze>(rtype::ecs::component::SHIP, currWave);
        this->_world.addEntity(enemy);
    } else if (shipType == 4) {
        rtype::ecs::entity::Entity *enemy = new rtype::ecs::entity::Entity(rtype::ecs::entity::ENEMY);
        if (enemy == nullptr)
            throw ScreensExceptions("SoloScreen: Error while creating enemy entity");
        enemy->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, x, y, 0.0f, 0.0f);
        enemy->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
        enemy->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
        enemy->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/turret.png", true, sf::Vector2f(4.f, 4.f), 0, sf::IntRect(0, 0, 32, 32));
        enemy->addComponent<ecs::component::Turret>(rtype::ecs::component::SHIP, currWave);
        this->_world.addEntity(enemy);
    } else if (shipType == 5) {
        rtype::ecs::entity::Entity *enemy = new rtype::ecs::entity::Entity(rtype::ecs::entity::ENEMY);
        if (enemy == nullptr)
            throw ScreensExceptions("SoloScreen: Error while creating enemy entity");
        enemy->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, x, y, 0.0f, 0.0f);
        enemy->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
        enemy->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
        enemy->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/boss.png", true, sf::Vector2f(2.5f, 2.5f), 0, sf::IntRect(0, 0, 260, 143));
        enemy->addComponent<ecs::component::Boss>(rtype::ecs::component::SHIP, currWave);
        this->_world.addEntity(enemy);
    }
}

void rtype::menu::CoreScreen::spawnEnemiesFromScript(void)
{
    for (size_t i = 0; i < _world.getEntities().size(); i++) {
        if (_world.getEntity(i)->getEntityType() == rtype::ecs::entity::TEXT) {
            ecs::component::Transform *transformCompo = _world.getEntity(i)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
            if (transformCompo->getX() == 800.f && transformCompo->getY() == 450.f) {
                ecs::component::Drawable2D *drawableCompo = _world.getEntity(i)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
                sf::Color tmpColor(250, 250, 250, drawableCompo->getColor().a - 0.01);
                drawableCompo->setColor(tmpColor);
                if (drawableCompo->getColor().a == 0)
                    _world.removeEntity(i);
                break;
            }
        }
    }
    if (_script.getClock().getElapsedTime() >= getWaveDuration()) {
        for (size_t i = 0; i < _world.getEntities().size(); i++) {
            if (_world.getEntity(i)->getEntityType() == rtype::ecs::entity::ENEMY) {
                return;
            }
        }
        _currWave++;
        printWaveNumber();
        _script.restartClock();
    }
    if (_clockScriptCall.getElapsedTime() >= sf::seconds(1.0f)) {
        for (size_t i = 0; i < _script.getLines().size(); i++) {
            if (_script.getLines().at(i).   size() == 6 && _script.getLines().at(i).at(5) && (_script.getLines().at(i).at(1) == _currWave)) {
                if (_script.getClock().getElapsedTime() >= sf::seconds(static_cast<float>(_script.getLines().at(i).at(0)))) {
                    generateEnemy(_script.getLines().at(i).at(1),  _script.getLines().at(i).at(2),
                    static_cast<float>(_script.getLines().at(i).at(3)), static_cast<float>(_script.getLines().at(i).at(4)));
                    _script.spriteIsPrinted(i);
                }
            }
        }
        _clockScriptCall.restart();
    }
}

void rtype::menu::CoreScreen::printWaveNumber(void)
{
    rtype::ecs::entity::Entity *wave = new rtype::ecs::entity::Entity(rtype::ecs::entity::TEXT);
    if (wave == nullptr)
        throw ScreensExceptions("MultiplayerScreen: Error while creating the wave number entity");
    wave->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 800.f, 450.f, 0.0f, 0.0f);
    sf::Color textColor(250, 250, 250, 150);
    wave->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "Wave " + std::to_string(_currWave), 120.f, textColor, true);
    this->_world.addEntity(wave);
}

sf::Time rtype::menu::CoreScreen::getWaveDuration(void)
{
    sf::Time tmp;
    switch (_currWave) {
        case 1:
            tmp = sf::seconds(10.f);
            break;
        case 2:
            tmp = sf::seconds(15.f);
            break;
        case 3:
            tmp = sf::seconds(15.f);
            break;
        case 4:
            tmp = sf::seconds(15.f);
            break;
        case 5:
            tmp = sf::seconds(20.f);
            break;
        case 6:
            tmp = sf::seconds(20.f);
            break;
        case 7:
            tmp = sf::seconds(20.f);
            break;
        case 8:
            tmp = sf::seconds(20.f);
            break;
        case 9:
            tmp = sf::seconds(20.f);
            break;
        case 10:
            tmp = sf::seconds(20.f);
            break;
        default:
            break;
    };
    return tmp;
}

void rtype::menu::CoreScreen::saveParalax(void)
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

void rtype::menu::CoreScreen::paralax(void)
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

void rtype::menu::CoreScreen::handleWindowBorder(void)
{
    for (size_t i = 0; i < _world.getEntities().size(); i++) {
        if (_world.getEntity(i)->getEntityType() == _playerNumber) {
            ecs::component::Transform *transformCompo = _world.getEntity(i)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
            ecs::component::Drawable2D *drawableCompo = _world.getEntity(i)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
            if (transformCompo->getX() < -0.1f)
                transformCompo->setX(0.0f);
            else if (transformCompo->getY() < -0.1f)
                transformCompo->setY(0.0f);
            else if (transformCompo->getX() + drawableCompo->getWidth() > 1920.1f)
                transformCompo->setX(1920.f - drawableCompo->getWidth());
            else if (transformCompo->getY() + drawableCompo->getHeight() > 1080.1f)
                transformCompo->setY(1080.f - drawableCompo->getHeight());
            break;
        }
    }
}

void rtype::menu::CoreScreen::updateEntities(rtype::Game *gameEngine)
{
    if (gameEngine->_client->getEntities().size() < this->_world.getEntities().size())
        return;
    spawnEnemiesFromScript();
    createMissiles(gameEngine);
    // createEnemies(gameEngine);
    gameEngine->_client->lockMutex();
    while (0 < gameEngine->_client->getEntities().size() ) {
        if (this->_world.getEntity(gameEngine->_client->getEntitiesAt(0).id)->getEntityType() != rtype::ecs::entity::TEXT) {
            this->_world.getEntity(gameEngine->_client->getEntitiesAt(0).id)->getComponent<rtype::ecs::component::Transform>(rtype::ecs::component::TRANSFORM)->setX(gameEngine->_client->getEntitiesAt(0).posX);
            this->_world.getEntity(gameEngine->_client->getEntitiesAt(0).id)->getComponent<rtype::ecs::component::Transform>(rtype::ecs::component::TRANSFORM)->setY(gameEngine->_client->getEntitiesAt(0).posY);
            std::cout << "Entity " << gameEngine->_client->getEntitiesAt(0).id << " updated as type " << this->_world.getEntity(gameEngine->_client->getEntitiesAt(0).id)->getEntityType() << std::endl;
        }
        gameEngine->_client->popEntity();
    }
    gameEngine->_client->getEntities().clear();
    gameEngine->_client->unlockMutex();
}

void rtype::menu::CoreScreen::createMissiles(rtype::Game *gameEngine)
{
    gameEngine->_client->lockMutex();
    while (gameEngine->_client->getShoots().size() > 0) {
        ecs::component::Transform *transformCompo =
            _world.getEntity(gameEngine->_client->getShoots().at(0))->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);

        rtype::ecs::entity::Entity *shot = new rtype::ecs::entity::Entity(rtype::ecs::entity::ALLY_PROJECTILE);
        if (shot == nullptr)
            throw ScreensExceptions("Error: Can't create a entity (6)");
        shot->addComponent<ecs::component::Transform>(
            rtype::ecs::component::TRANSFORM, transformCompo->getX() + 45.f, transformCompo->getY() + 8.f, 20.0f, 0.0f);
        shot->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
        shot->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
        shot->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/projectile.png", true,
            sf::Vector2f(1.5f, 1.5f), 0, sf::IntRect(165, 133, 50, 17));
        this->_world.addEntity(shot);

        gameEngine->_client->popShoots();
    }
    gameEngine->_client->unlockMutex();
}
