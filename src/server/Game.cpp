/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Game.cpp
*/

#include "Game.hpp"
#include "../ecs/System/Movement/movement.hpp"
#include "../ecs/System/Collide/collide.hpp"
#include "../ecs/System/Enemypath/enemypath.hpp"
#include "../ecs/System/Particles/particles.hpp"
#include "../exceptions/ScreensExceptions.hpp"

rtype::Game::Game(size_t nbPlayers) : _nbPlayers(nbPlayers), _currWave(1)
{
}

void rtype::Game::init()
{
    this->_world = new rtype::ecs::world::World;
    rtype::ecs::system::ISystem *movementSystem = new rtype::ecs::system::MovementSystem();
    if (movementSystem == nullptr)
        throw ScreensExceptions("CoreScreen: Error while creating MovementSystem");
    this->_world->addSystem(movementSystem);
    rtype::ecs::system::ISystem *collideSystem = new rtype::ecs::system::CollideSystem();
    if (collideSystem == nullptr)
        throw ScreensExceptions("CoreScreen: Error while creating CollideSystem");
    this->_world->addSystem(collideSystem);
    rtype::ecs::system::ISystem *enemypathSystem = new rtype::ecs::system::EnemypathSystem();
    if (enemypathSystem == nullptr)
        throw ScreensExceptions("CoreScreen: Error while creating EnemypathSystem");
    this->_world->addSystem(enemypathSystem);
    rtype::ecs::system::ISystem *particleSystem = new rtype::ecs::system::ParticlesSystem();
    if (particleSystem == nullptr)
        throw ScreensExceptions("CoreScreen: Error while creating ParticleSystem");
    this->_world->addSystem(particleSystem);

    this->initPlayersEntities();
    // this->createEnemyEntity(650.0f, 50.0f);
}

void rtype::Game::initPlayersEntities(void)
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
        player1->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/ships.png", true, sf::Vector2f(4.f, 4.f), 0, sf::IntRect(0, 0, 33, 17));
        this->_world->addEntity(player1);
        player2->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 500.f, 250.f, 0.0f, 0.0f);
        player2->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
        player2->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
        player2->addComponent<ecs::component::Recruit>(rtype::ecs::component::SHIP);
        player2->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/ships.png", true, sf::Vector2f(4.f, 4.f), 0, sf::IntRect(0, 17, 33, 17));
        this->_world->addEntity(player2);
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
        player1->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/ships.png", true, sf::Vector2f(4.f, 4.f), 0, sf::IntRect(0, 0, 33, 17));
        this->_world->addEntity(player1);
        player2->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 500.f, 250.f, 0.0f, 0.0f);
        player2->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
        player2->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
        player2->addComponent<ecs::component::Recruit>(rtype::ecs::component::SHIP);
        player2->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/ships.png", true, sf::Vector2f(4.f, 4.f), 0, sf::IntRect(0, 17, 33, 17));
        this->_world->addEntity(player2);
        player3->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 500.f, 450.f, 0.0f, 0.0f);
        player3->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
        player3->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
        player3->addComponent<ecs::component::Recruit>(rtype::ecs::component::SHIP);
        player3->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/ships.png", true, sf::Vector2f(4.f, 4.f), 0, sf::IntRect(0, 34, 33, 17));
        this->_world->addEntity(player3);
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
        player1->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/ships.png", true, sf::Vector2f(4.f, 4.f), 0, sf::IntRect(0, 0, 33, 17));
        this->_world->addEntity(player1);
        player2->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 500.f, 250.f, 0.0f, 0.0f);
        player2->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
        player2->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
        player2->addComponent<ecs::component::Recruit>(rtype::ecs::component::SHIP);
        player2->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/ships.png", true, sf::Vector2f(4.f, 4.f), 0, sf::IntRect(0, 17, 33, 17));
        this->_world->addEntity(player2);
        player3->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 500.f, 450.f, 0.0f, 0.0f);
        player3->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
        player3->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
        player3->addComponent<ecs::component::Recruit>(rtype::ecs::component::SHIP);
        player3->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/ships.png", true, sf::Vector2f(4.f, 4.f), 0, sf::IntRect(0, 34, 33, 17));
        this->_world->addEntity(player3);
        player4->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 500.f, 650.f, 0.0f, 0.0f);
        player4->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
        player4->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
        player4->addComponent<ecs::component::Recruit>(rtype::ecs::component::SHIP);
        player4->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/ships.png", true, sf::Vector2f(4.f, 4.f), 0, sf::IntRect(0, 51, 33, 17));
        this->_world->addEntity(player4);
    }
}

void rtype::Game::update(void)
{
    this->_world->update();
}

int rtype::Game::handleEvents(std::string direction, size_t playerId)
{
    ecs::component::Transform *transformCompo;
    ecs::component::IShip *shipCompo;

    if (direction == "S")
    {
        for (size_t i = 0; i < _world->getEntities().size(); i++) {
            if (playerId == i) {
                std::cout << "SHOOT PLAYER ID : " << playerId << std::endl;
                direction.clear();
                return 1;
            }
        }
    }
    for (size_t i = 0; i < _world->getEntities().size(); i++)
    {
        transformCompo = _world->getEntity(i)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
        if (playerId == i) {
            transformCompo->setSpeedY(0.0f);
            transformCompo->setSpeedX(0.0f);
            shipCompo = _world->getEntity(i)->getComponent<ecs::component::IShip>(ecs::component::compoType::SHIP);
            if (direction == "R")
                transformCompo->setSpeedX(shipCompo->getSpeed());
            if (direction == "L")
                transformCompo->setSpeedX(-1 *shipCompo->getSpeed());
            if (direction == "U")
                transformCompo->setSpeedY(-1 * shipCompo->getSpeed());
            if (direction == "D")
                transformCompo->setSpeedY(shipCompo->getSpeed());
            direction.clear();
        }
    }
    return 0;
}

void rtype::Game::createShoot(size_t playerId)
{
    ecs::component::Transform *transformCompo =
        _world->getEntity(playerId)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);

    rtype::ecs::entity::Entity *shot = new rtype::ecs::entity::Entity(rtype::ecs::entity::ALLY_PROJECTILE);
    if (shot == nullptr)
        throw ScreensExceptions("Error: Can't create a entity (6)");
    shot->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, transformCompo->getX()
    + 45.f, transformCompo->getY() + 8.f, 20.0f, 0.0f);
    shot->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
    shot->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
    shot->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D,
    "assets/projectile.png", true, sf::Vector2f(1.5f, 1.5f), 0, sf::IntRect(165, 133, 50, 17));
    this->_world->addEntity(shot);
}

void rtype::Game::createEnemyEntity(float x, float y)
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
    this->_world->addEntity(enemy);
}

void rtype::Game::destroySprites(void)
{

    for (size_t i = 0; i < _world->getEntities().size(); i++) {
        ecs::component::Transform *transformCompo = _world->getEntity(i)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
        if (_world->getEntity(i)->getEntityType() == rtype::ecs::entity::ENEMY_PROJECTILE ||
        _world->getEntity(i)->getEntityType() == rtype::ecs::entity::ALLY_PROJECTILE) {
            if (transformCompo->getX() > 1920 || transformCompo->getX() < -100 || transformCompo->getY() < -100 || transformCompo->getY() > 1280) {
                _world->removeEntity(i);
                break;
            }
        }
        if (_world->getEntity(i)->hasCompoType(rtype::ecs::component::compoType::ALIVE)) {
            ecs::component::Alive *aliveCompo =
                _world->getEntity(i)->getComponent<ecs::component::Alive>(ecs::component::compoType::ALIVE);
            if (!aliveCompo->getAlive()) {
                // if (_world->getEntity(i)->hasCompoType(ecs::component::compoType::SHIP))
                //    Particle(transformCompo->getX(), transformCompo->getY());
                _world->removeEntity(i);
            }
        }
    }
}

void rtype::Game::generateEnemy(int currWave, int shipType, float x, float y)
{
    if (shipType == 1) {
        rtype::ecs::entity::Entity *enemy = new rtype::ecs::entity::Entity(rtype::ecs::entity::ENEMY);
        enemy->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, x, y, 0.0f, 0.5f);
        enemy->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
        enemy->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
        enemy->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/zigzag.png", true, sf::Vector2f(3.f, 3.f), 0, sf::IntRect(34, 34, 32, 32));
        enemy->addComponent<ecs::component::Zigzag>(rtype::ecs::component::SHIP, currWave);
        this->_world->addEntity(enemy);
    } else if (shipType == 2) {
        rtype::ecs::entity::Entity *enemy = new rtype::ecs::entity::Entity(rtype::ecs::entity::ENEMY);
        if (enemy == nullptr)
            throw ScreensExceptions("SoloScreen: Error while creating enemy entity");
        enemy->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, x, y, -5.0f, 0.0f);
        enemy->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
        enemy->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
        enemy->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/rusher.png", true, sf::Vector2f(2.f, 2.f), 0, sf::IntRect(50, 0, 65, 60));
        enemy->addComponent<ecs::component::Rusher>(rtype::ecs::component::SHIP, currWave);
        this->_world->addEntity(enemy);
    } else if (shipType == 3) {
        rtype::ecs::entity::Entity *enemy = new rtype::ecs::entity::Entity(rtype::ecs::entity::ENEMY);
        if (enemy == nullptr)
            throw ScreensExceptions("SoloScreen: Error while creating enemy entity");
        enemy->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, x, y, -8.0f, 0.0f);
        enemy->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
        enemy->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
        enemy->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/kamikaze.png", true, sf::Vector2f(2.f, 2.f), 0, sf::IntRect(75, 50, 60, 50));
        enemy->addComponent<ecs::component::Kamikaze>(rtype::ecs::component::SHIP, currWave);
        this->_world->addEntity(enemy);
    } else if (shipType == 4) {
        rtype::ecs::entity::Entity *enemy = new rtype::ecs::entity::Entity(rtype::ecs::entity::ENEMY);
        if (enemy == nullptr)
            throw ScreensExceptions("SoloScreen: Error while creating enemy entity");
        enemy->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, x, y, -3.0f, 0.0f);
        enemy->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
        enemy->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
        enemy->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/turret.png", true, sf::Vector2f(4.f, 4.f), 0, sf::IntRect(0, 0, 32, 32));
        enemy->addComponent<ecs::component::Turret>(rtype::ecs::component::SHIP, currWave);
        this->_world->addEntity(enemy);
    } else if (shipType == 5) {
        rtype::ecs::entity::Entity *enemy = new rtype::ecs::entity::Entity(rtype::ecs::entity::ENEMY);
        if (enemy == nullptr)
            throw ScreensExceptions("SoloScreen: Error while creating enemy entity");
        enemy->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, x, y, -2.0f, 0.0f);
        enemy->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
        enemy->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
        enemy->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/boss.png", true, sf::Vector2f(2.5f, 2.5f), 0, sf::IntRect(0, 0, 260, 143));
        enemy->addComponent<ecs::component::Boss>(rtype::ecs::component::SHIP, currWave);
        this->_world->addEntity(enemy);
    }
}

void rtype::Game::spawnEnemiesFromScript(void)
{
    for (size_t i = 0; i < _world->getEntities().size(); i++) {
        if (_world->getEntity(i)->getEntityType() == rtype::ecs::entity::TEXT) {
            ecs::component::Transform *transformCompo = _world->getEntity(i)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
            if (transformCompo->getX() == 800.f && transformCompo->getY() == 450.f) {
                ecs::component::Drawable2D *drawableCompo = _world->getEntity(i)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
                sf::Color tmpColor(250, 250, 250, drawableCompo->getColor().a - 0.01);
                drawableCompo->setColor(tmpColor);
                if (drawableCompo->getColor().a == 0)
                    _world->removeEntity(i);
                break;
            }
        }
    }
    if (_script.getClock().getElapsedTime() >= getWaveDuration()) {
        for (size_t i = 0; i < _world->getEntities().size(); i++) {
            if (_world->getEntity(i)->getEntityType() == rtype::ecs::entity::ENEMY) {
                return;
            }
        }
        _currWave++;
        printWaveNumber();
        _script.restartClock();
    }
    if (_clockScriptCall.getElapsedTime() >= sf::seconds(1.0f)) {
        for (size_t i = 0; i < _script.getLines().size(); i++) {
            if (_script.getLines().at(i).size() == 6 && _script.getLines().at(i).at(5) && (_script.getLines().at(i).at(1) == _currWave)) {
                if (_script.getClock().getElapsedTime() >= sf::seconds(static_cast<float>(_script.getLines().at(i).at(0)))) {
                    std::cout << "x = " << _script.getLines().at(i).at(1) << " y = " << _script.getLines().at(i).at(2) << std::endl;
                    generateEnemy(_script.getLines().at(i).at(1),  _script.getLines().at(i).at(2),
                    static_cast<float>(_script.getLines().at(i).at(3)), static_cast<float>(_script.getLines().at(i).at(4)));
                    _script.spriteIsPrinted(i);
                }
            }
        }
        _clockScriptCall.restart();
    }
}

void rtype::Game::printWaveNumber(void)
{
    rtype::ecs::entity::Entity *wave = new rtype::ecs::entity::Entity(rtype::ecs::entity::TEXT);
    if (wave == nullptr)
        throw ScreensExceptions("MultiplayerScreen: Error while creating the wave number entity");
    wave->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 800.f, 450.f, 0.0f, 0.0f);
    sf::Color textColor(250, 250, 250, 150);
    wave->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "Wave " + std::to_string(_currWave), 120.f, textColor, true);
    this->_world->addEntity(wave);
}

sf::Time rtype::Game::getWaveDuration(void)
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
