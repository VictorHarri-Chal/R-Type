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

rtype::Game::Game(size_t nbPlayers) : _nbPlayers(nbPlayers)
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
    this->createEnemyEntity(650.0f, 50.0f);
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
                //     createParticle(transformCompo->getX(), transformCompo->getY());
                _world->removeEntity(i);
            }
        }
    }
}
