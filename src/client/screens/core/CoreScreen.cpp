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

rtype::menu::CoreScreen::CoreScreen(size_t nbPlayers): _nbPlayers(nbPlayers), _isPlayerNumInit(false), _currWave(1)
{
}

void rtype::menu::CoreScreen::init()
{
    rtype::ecs::system::ISystem *draw2DSystem = new rtype::ecs::system::Draw2DSystem();
    if (draw2DSystem == nullptr)
        throw ScreensExceptions("CoreScreen: Error while creating Draw2DSystem");
    this->_world.addSystem(draw2DSystem);

    this->initPlayersEntities();
}

void rtype::menu::CoreScreen::initPlayersEntities(void)
{
    if (this->_nbPlayers == 2) {
        rtype::ecs::entity::Entity *player1 = new rtype::ecs::entity::Entity(rtype::ecs::entity::PLAYER2);
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
        player2->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 500.f, 300.f, 0.0f, 0.0f);
        player2->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
        player2->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
        player2->addComponent<ecs::component::Recruit>(rtype::ecs::component::SHIP);
        player2->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/ships.png", true,
            sf::Vector2f(4.f, 4.f), 0, sf::IntRect(0, 0, 33, 17));
        this->_world.addEntity(player2);
    }

    if (this->_nbPlayers == 3) {
        rtype::ecs::entity::Entity *player1 = new rtype::ecs::entity::Entity(rtype::ecs::entity::PLAYER3);
        rtype::ecs::entity::Entity *player2 = new rtype::ecs::entity::Entity(rtype::ecs::entity::PLAYER3);
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
        player2->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 500.f, 300.f, 0.0f, 0.0f);
        player2->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
        player2->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
        player2->addComponent<ecs::component::Recruit>(rtype::ecs::component::SHIP);
        player2->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/ships.png", true,
            sf::Vector2f(4.f, 4.f), 0, sf::IntRect(0, 0, 33, 17));
        this->_world.addEntity(player2);
        player3->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 500.f, 550.f, 0.0f, 0.0f);
        player3->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
        player3->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
        player3->addComponent<ecs::component::Recruit>(rtype::ecs::component::SHIP);
        player3->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/ships.png", true,
            sf::Vector2f(4.f, 4.f), 0, sf::IntRect(0, 0, 33, 17));
        this->_world.addEntity(player3);
    }

    if (this->_nbPlayers == 4) {
        rtype::ecs::entity::Entity *player1 = new rtype::ecs::entity::Entity(rtype::ecs::entity::PLAYER4);
        rtype::ecs::entity::Entity *player2 = new rtype::ecs::entity::Entity(rtype::ecs::entity::PLAYER4);
        rtype::ecs::entity::Entity *player3 = new rtype::ecs::entity::Entity(rtype::ecs::entity::PLAYER4);
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
        player2->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 500.f, 300.f, 0.0f, 0.0f);
        player2->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
        player2->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
        player2->addComponent<ecs::component::Recruit>(rtype::ecs::component::SHIP);
        player2->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/ships.png", true,
            sf::Vector2f(4.f, 4.f), 0, sf::IntRect(0, 0, 33, 17));
        this->_world.addEntity(player2);
        player3->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 500.f, 550.f, 0.0f, 0.0f);
        player3->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
        player3->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
        player3->addComponent<ecs::component::Recruit>(rtype::ecs::component::SHIP);
        player3->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/ships.png", true,
            sf::Vector2f(4.f, 4.f), 0, sf::IntRect(0, 0, 33, 17));
        this->_world.addEntity(player3);
        player3->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 500.f, 700.f, 0.0f, 0.0f);
        player3->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
        player3->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
        player3->addComponent<ecs::component::Recruit>(rtype::ecs::component::SHIP);
        player3->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/ships.png", true,
            sf::Vector2f(4.f, 4.f), 0, sf::IntRect(0, 0, 33, 17));
        this->_world.addEntity(player4);
    }
}

int rtype::menu::CoreScreen::handleEvent(rtype::Event &event, rtype::Game *gameEngine)
{
    // this->initPlayerNumber(gameEngine);
    std::cout << "nbPlayers: " << this->_nbPlayers << std::endl;
    std::cout << "layernbumber: " << this->_playerNumber << std::endl;
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
    // destroySprites();
    // paralax();
    // spawnEnemiesFromScript();
    // manageEnemiesShooting();
    // handleWindowBorder();
    this->_world.update(gameEngine);
    this->_world.draw(gameEngine);
}

// void rtype::menu::CoreScreen::initPlayerNumber(rtype::Game *gameEngine)
// {
//     if (!_isPlayerNumInit) {
//         std::string tmp = gameEngine->_client->getPlayerNumber();
//         if (tmp == "1")
//             _playerNumber = rtype::ecs::entity::PLAYER1;
//         if (tmp == "2")
//             _playerNumber = rtype::ecs::entity::PLAYER2;
//         if (tmp == "3")
//             _playerNumber = rtype::ecs::entity::PLAYER3;
//         if (tmp == "4")
//             _playerNumber = rtype::ecs::entity::PLAYER4;
//         _isPlayerNumInit = true;
//     }
// }

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
    ecs::component::Transform *transformCompo = _world.getEntity(entityId)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
    ecs::component::IShip *shipCompo = _world.getEntity(entityId)->getComponent<ecs::component::IShip>(ecs::component::compoType::SHIP);
    managePlayerMovement(transformCompo, shipCompo, event, gameEngine);
    managePlayerShot(transformCompo, shipCompo, event, gameEngine);
}

void rtype::menu::CoreScreen::managePlayerMovement(ecs::component::Transform *transformCompo, ecs::component::IShip *shipCompo, rtype::Event &event, rtype::Game *gameEngine)
{
    transformCompo->setSpeedX(0.0f);
    transformCompo->setSpeedY(0.0f);
    if (event.key.right && !event.key.left) {
        transformCompo->setSpeedX(shipCompo->getSpeed());
        gameEngine->_client->send(message::MOVE, "R");
    }
    if (event.key.left && !event.key.right) {
        transformCompo->setSpeedX(-1 * shipCompo->getSpeed());
        gameEngine->_client->send(message::MOVE, "L");
    }
    if (event.key.up && !event.key.down) {
        transformCompo->setSpeedY(-1 * shipCompo->getSpeed());
        gameEngine->_client->send(message::MOVE, "U");
    }
    if (event.key.down && !event.key.up) {
        transformCompo->setSpeedY(shipCompo->getSpeed());
        gameEngine->_client->send(message::MOVE, "D");
    }
}

void rtype::menu::CoreScreen::managePlayerShot(ecs::component::Transform *transformCompo, ecs::component::IShip *shipCompo, rtype::Event &event, rtype::Game *gameEngine)
{
    if (shipCompo->getClock().getElapsedTime() >= shipCompo->getCadency()) {
        if (event.key.code == ' ') {
            rtype::ecs::entity::Entity *shot = new rtype::ecs::entity::Entity(rtype::ecs::entity::ALLY_PROJECTILE);
            if (shot == nullptr)
                throw ScreensExceptions("Error: Can't create a entity (6)");
            shot->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, transformCompo->getX() + 45.f, transformCompo->getY() + 8.f, 25.0f, 0.0f);
            shot->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
            shot->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
            shot->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/projectile.png", true, sf::Vector2f(1.5f, 1.5f), 0, sf::IntRect(165, 133, 50, 17));
            this->_world.addEntity(shot);
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
            if (transformCompo->getX() > 1920 || transformCompo->getX() < 0) {
                _world.removeEntity(i);
                break;
            }
        }
        if (_world.getEntity(i)->hasCompoType(rtype::ecs::component::compoType::ALIVE)) {
            ecs::component::Alive *aliveCompo = _world.getEntity(i)->getComponent<ecs::component::Alive>(ecs::component::compoType::ALIVE);
            if (!aliveCompo->getAlive()) {
                if (_world.getEntity(i)->hasCompoType(ecs::component::compoType::SHIP) ) {
                    ecs::component::IShip *shipCompo = _world.getEntity(i)->getComponent<ecs::component::IShip>(ecs::component::compoType::SHIP);
                    if (shipCompo->getShipType() == ecs::component::shipType::KAMIKAZE) {
                        createParticle(transformCompo->getX(), transformCompo->getY());
                    }
                }
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
            }
        }
    }
}

void rtype::menu::CoreScreen::generateEnemy(int currWave, int shipType, bool dirHor, bool dirVer, float x, float y)
{
    if (shipType == 1) {
        rtype::ecs::entity::Entity *enemy = new rtype::ecs::entity::Entity(rtype::ecs::entity::ENEMY);
        if (enemy == nullptr)
            throw ScreensExceptions("Corescreen: Error while creating enemy entity");
        enemy->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, x, y, 0.0f, 0.15f);
        enemy->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
        enemy->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
        enemy->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/zigzag.png", true, sf::Vector2f(3.f, 3.f), 0, sf::IntRect(34, 34, 32, 32));
        enemy->addComponent<ecs::component::Zigzag>(rtype::ecs::component::SHIP, dirHor, dirVer, currWave);
        this->_world.addEntity(enemy);
    } else if (shipType == 2) {
        rtype::ecs::entity::Entity *enemy = new rtype::ecs::entity::Entity(rtype::ecs::entity::ENEMY);
        if (enemy == nullptr)
            throw ScreensExceptions("Corescreen: Error while creating enemy entity");
        enemy->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, x, y, -5.0f, 0.0f);
        enemy->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
        enemy->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
        enemy->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/rusher.png", true, sf::Vector2f(2.f, 2.f), 0, sf::IntRect(50, 0, 65, 60));
        enemy->addComponent<ecs::component::Rusher>(rtype::ecs::component::SHIP, currWave);
        this->_world.addEntity(enemy);
    } else if (shipType == 3) {
        rtype::ecs::entity::Entity *enemy = new rtype::ecs::entity::Entity(rtype::ecs::entity::ENEMY);
        if (enemy == nullptr)
            throw ScreensExceptions("Corescreen: Error while creating enemy entity");
        enemy->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, x, y, -8.0f, 0.0f);
        enemy->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
        enemy->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
        enemy->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/kamikaze.png", true, sf::Vector2f(2.f, 2.f), 0, sf::IntRect(75, 50, 60, 50));
        enemy->addComponent<ecs::component::Kamikaze>(rtype::ecs::component::SHIP, currWave);
        this->_world.addEntity(enemy);
    } else if (shipType == 4) {
        rtype::ecs::entity::Entity *enemy = new rtype::ecs::entity::Entity(rtype::ecs::entity::ENEMY);
        if (enemy == nullptr)
            throw ScreensExceptions("Corescreen: Error while creating enemy entity");
        enemy->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, x, y, -3.0f, 0.0f);
        enemy->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
        enemy->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
        enemy->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/turret.png", true, sf::Vector2f(4.f, 4.f), 0, sf::IntRect(0, 0, 32, 32));
        enemy->addComponent<ecs::component::Turret>(rtype::ecs::component::SHIP, currWave);
        this->_world.addEntity(enemy);
    }
}

void rtype::menu::CoreScreen::spawnEnemiesFromScript(void)
{
    for (size_t i = 0; i < _world.getEntities().size(); i++) {
        if (_world.getEntity(i)->getEntityType() == rtype::ecs::entity::TEXT) {
            ecs::component::Drawable2D *drawableCompo = _world.getEntity(i)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
            sf::Color tmpColor(250, 250, 250, drawableCompo->getColor().a - 0.1);
            drawableCompo->setColor(tmpColor);
            if (drawableCompo->getColor().a == 0)
                _world.removeEntity(i);
            break;
        }
    }
    if (_script.getClock().getElapsedTime() >= getWaveDuration()) {
        for (size_t i = 0; i < _world.getEntities().size(); i++) {
            if (_world.getEntity(i)->getEntityType() == rtype::ecs::entity::ENEMY ||
            _world.getEntity(i)->getEntityType() == rtype::ecs::entity::BOSS) {
                return;
            }
        }
        _currWave++;
        printWaveNumber();
        _script.restartClock();
    }
    for (size_t i = 0; i < _script.getLines().size(); i++) {
        if (_script.getLines().at(i).at(7) && (_script.getLines().at(i).at(1) == _currWave)) {
            sf::Time time = sf::seconds(static_cast<float>(_script.getLines().at(i).at(0)));
            if (_script.getClock().getElapsedTime() >= time) {
                generateEnemy(_script.getLines().at(i).at(1),  _script.getLines().at(i).at(2),
                static_cast<bool>(_script.getLines().at(i).at(3)), static_cast<bool>( _script.getLines().at(i).at(4)),
                static_cast<float>(_script.getLines().at(i).at(5)), static_cast<float>(_script.getLines().at(i).at(6)));
                _script.spriteIsPrinted(i);
            }
        }
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
            tmp = sf::seconds(5.f);
            break;
        case 2:
            tmp = sf::seconds(5.f);
            break;
        case 3:
            tmp = sf::seconds(50.f);
            break;
        case 4:
            tmp = sf::seconds(60.f);
            break;
        case 5:
            tmp = sf::seconds(30.f);
            break;
        case 6:
            tmp = sf::seconds(40.f);
            break;
        case 7:
            tmp = sf::seconds(50.f);
            break;
        case 8:
            tmp = sf::seconds(60.f);
            break;
        case 9:
            tmp = sf::seconds(70.f);
            break;
        case 10:
            tmp = sf::seconds(60.f);
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
