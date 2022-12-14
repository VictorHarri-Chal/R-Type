/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** soloScreen.cpp
*/

#include "SoloScreen.hpp"
#include "../../../ecs/System/Draw2D/draw2d.hpp"
#include "../../../ecs/System/Movement/movement.hpp"
#include "../../../ecs/System/Collide/collide.hpp"
#include "../../../ecs/System/Enemypath/enemypath.hpp"
#include "../../../ecs/System/Particles/particles.hpp"
#include "../../../exceptions/ScreensExceptions.hpp"

rtype::menu::SoloScreen::SoloScreen(): _currWave(1), _isGameEnded(false), _condInit(false)
{
}

void rtype::menu::SoloScreen::init()
{
    rtype::ecs::system::ISystem *draw2DSystem = new rtype::ecs::system::Draw2DSystem();
    if (draw2DSystem == nullptr)
        throw ScreensExceptions("SoloScreen: Error while creating Draw2DSystem");
    this->_world.addSystem(draw2DSystem);
    rtype::ecs::system::ISystem *movementSystem = new rtype::ecs::system::MovementSystem();
    if (movementSystem == nullptr)
        throw ScreensExceptions("SoloScreen: Error while creating MovementSystem");
    this->_world.addSystem(movementSystem);
    rtype::ecs::system::ISystem *collideSystem = new rtype::ecs::system::CollideSystem();
    if (collideSystem == nullptr)
        throw ScreensExceptions("SoloScreen: Error while creating CollideSystem");
    this->_world.addSystem(collideSystem);
    rtype::ecs::system::ISystem *enemypathSystem = new rtype::ecs::system::EnemypathSystem();
    if (enemypathSystem == nullptr)
        throw ScreensExceptions("SoloScreen: Error while creating EnemypathSystem");
    this->_world.addSystem(enemypathSystem);
    rtype::ecs::system::ISystem *particleSystem = new rtype::ecs::system::ParticlesSystem();
    if (particleSystem == nullptr)
        throw ScreensExceptions("SoloScreen: Error while creating ParticleSystem");
    this->_world.addSystem(particleSystem);

    rtype::ecs::entity::Entity *bg = new rtype::ecs::entity::Entity(rtype::ecs::entity::STATIC_SPRITE);
    if (bg == nullptr)
        throw ScreensExceptions("SoloScreen: Error while creating Entity (1)");
    bg->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, bg_x, 0.0f, -0.5f, 0.0f);
    bg->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/bg.png", false, sf::Vector2f(1.f, 1.f), 0);
    this->_world.addEntity(bg);
    rtype::ecs::entity::Entity *stars = new rtype::ecs::entity::Entity(rtype::ecs::entity::STATIC_SPRITE);
    if (stars == nullptr)
        throw ScreensExceptions("SoloScreen: Error while creating Entity (2)");
    stars->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, stars_x, 0.0f, -0.7f, 0.0f);
    stars->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/bg2.png", false, sf::Vector2f(1.f, 1.f), 0);
    this->_world.addEntity(stars);
    rtype::ecs::entity::Entity *planets = new rtype::ecs::entity::Entity(rtype::ecs::entity::STATIC_SPRITE);
    if (planets == nullptr)
        throw ScreensExceptions("SoloScreen: Error while creating Entity (3)");
    planets->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, planets_x, 0.0f, -1.0f, 0.0f);
    planets->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/bg3.png", false, sf::Vector2f(1.f, 1.f), 0);
    this->_world.addEntity(planets);
    rtype::ecs::entity::Entity *bigPlanet = new rtype::ecs::entity::Entity(rtype::ecs::entity::STATIC_SPRITE);
    if (bigPlanet == nullptr)
        throw ScreensExceptions("SoloScreen: Error while creating Entity (4)");
    bigPlanet->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, bigPlanet_x, 700.f, -1.2f, 0.0f);
    bigPlanet->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/bg4.png", false, sf::Vector2f(3.f, 3.f), 0);
    this->_world.addEntity(bigPlanet);
    rtype::ecs::entity::Entity *lifebar = new rtype::ecs::entity::Entity(rtype::ecs::entity::HEART);
    if (lifebar == nullptr)
        throw ScreensExceptions("SoloScreen: Error while creating Entity (6)");
    lifebar->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 500.f, 45.f, 0.0f, 0.0f);
    lifebar->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, 80.f, 6.f, sf::Color::Green, false);
    this->_world.addEntity(lifebar);
}

void rtype::menu::SoloScreen::initAllyShip(rtype::Game *gameEngine)
{
    if (gameEngine->_classType == rtype::ecs::component::shipType::SNIPER) {
        rtype::ecs::entity::Entity *ship = new rtype::ecs::entity::Entity(rtype::ecs::entity::PLAYER1);
        if (ship == nullptr)
            throw ScreensExceptions("SoloScreen: Error while creating Entity (5)");
        ship->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 500.f, 500.f, 0.0f, 0.0f);
        ship->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
        ship->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
        ship->addComponent<ecs::component::Sniper>(rtype::ecs::component::SHIP);
        ship->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/ships.png", true, sf::Vector2f(4.f, 4.f), 0, sf::IntRect(0, 0, 33, 17));
        this->_world.addEntity(ship);
        rtype::ecs::entity::Entity *sniperClass = new rtype::ecs::entity::Entity(rtype::ecs::entity::STATIC_SPRITE);
        if (sniperClass == nullptr)
            throw ScreensExceptions("SoloScreen: Error while creating health bonus entity");
        sniperClass->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 20.f, 960.f, 0.0f, 0.0f);
        sniperClass->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
        sniperClass->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/powerup.png", true, sf::Vector2f(0.4f, 0.4f), 0, sf::IntRect(519, 725, 261, 256));
        this->_world.addEntity(sniperClass);
        rtype::ecs::entity::Entity *cooldown = new rtype::ecs::entity::Entity(rtype::ecs::entity::COOLDOWN);
        if (cooldown == nullptr)
            throw ScreensExceptions("IntroScreen: Error while creating cooldown entity");
        cooldown->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 20.f, 960.f, 0.0f, 0.0f);
        cooldown->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, 104.f, 102.f, sf::Color(255, 255, 255, 150), false);
        this->_world.addEntity(cooldown);
    } else if (gameEngine->_classType == rtype::ecs::component::shipType::STEALTHY) {
        rtype::ecs::entity::Entity *ship = new rtype::ecs::entity::Entity(rtype::ecs::entity::PLAYER1);
        if (ship == nullptr)
            throw ScreensExceptions("SoloScreen: Error while creating Entity (5)");
        ship->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 500.f, 500.f, 0.0f, 0.0f);
        ship->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
        ship->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
        ship->addComponent<ecs::component::Stealthy>(rtype::ecs::component::SHIP);
        ship->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/ships.png", true, sf::Vector2f(4.f, 4.f), 0, sf::IntRect(0, 0, 33, 17));
        this->_world.addEntity(ship);
        rtype::ecs::entity::Entity *stealthyClass = new rtype::ecs::entity::Entity(rtype::ecs::entity::STATIC_SPRITE);
        if (stealthyClass == nullptr)
            throw ScreensExceptions("SoloScreen: Error while creating health bonus entity");
        stealthyClass->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 20.f, 960.f, 0.0f, 0.0f);
        stealthyClass->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
        stealthyClass->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/powerup.png", true, sf::Vector2f(0.4f, 0.4f), 0, sf::IntRect(519, 1347, 261, 256));
        this->_world.addEntity(stealthyClass);
        rtype::ecs::entity::Entity *cooldown = new rtype::ecs::entity::Entity(rtype::ecs::entity::COOLDOWN);
        if (cooldown == nullptr)
            throw ScreensExceptions("IntroScreen: Error while creating cooldown entity");
        cooldown->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 20.f, 960.f, 0.0f, 0.0f);
        cooldown->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, 104.f, 102.f, sf::Color(255, 255, 255, 150), false);
        this->_world.addEntity(cooldown);
    } else if (gameEngine->_classType == rtype::ecs::component::shipType::TANK) {
        rtype::ecs::entity::Entity *ship = new rtype::ecs::entity::Entity(rtype::ecs::entity::PLAYER1);
        if (ship == nullptr)
            throw ScreensExceptions("SoloScreen: Error while creating Entity (5)");
        ship->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 500.f, 500.f, 0.0f, 0.0f);
        ship->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
        ship->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
        ship->addComponent<ecs::component::Tank>(rtype::ecs::component::SHIP);
        ship->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/ships.png", true, sf::Vector2f(4.f, 4.f), 0, sf::IntRect(0, 0, 33, 17));
        this->_world.addEntity(ship);
        rtype::ecs::entity::Entity *tankClass = new rtype::ecs::entity::Entity(rtype::ecs::entity::STATIC_SPRITE);
        if (tankClass == nullptr)
            throw ScreensExceptions("SoloScreen: Error while creating health bonus entity");
        tankClass->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 20.f, 960.f, 0.0f, 0.0f);
        tankClass->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
        tankClass->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/powerup.png", true, sf::Vector2f(0.4f, 0.4f), 0, sf::IntRect(1188, 1038, 261, 256));
        this->_world.addEntity(tankClass);
            rtype::ecs::entity::Entity *cooldown = new rtype::ecs::entity::Entity(rtype::ecs::entity::COOLDOWN);
        if (cooldown == nullptr)
            throw ScreensExceptions("IntroScreen: Error while creating cooldown entity");
        cooldown->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 20.f, 960.f, 0.0f, 0.0f);
        cooldown->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, 104.f, 102.f, sf::Color(255, 255, 255, 150), false);
        this->_world.addEntity(cooldown);
    } else if (gameEngine->_classType == rtype::ecs::component::shipType::SUPPORT) {
        rtype::ecs::entity::Entity *ship = new rtype::ecs::entity::Entity(rtype::ecs::entity::PLAYER1);
        if (ship == nullptr)
            throw ScreensExceptions("SoloScreen: Error while creating Entity (5)");
        ship->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 500.f, 500.f, 0.0f, 0.0f);
        ship->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
        ship->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
        ship->addComponent<ecs::component::Support>(rtype::ecs::component::SHIP);
        ship->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/ships.png", true, sf::Vector2f(4.f, 4.f), 0, sf::IntRect(0, 0, 33, 17));
        this->_world.addEntity(ship);
        rtype::ecs::entity::Entity *suppClass = new rtype::ecs::entity::Entity(rtype::ecs::entity::STATIC_SPRITE);
        if (suppClass == nullptr)
            throw ScreensExceptions("SoloScreen: Error while creating health bonus entity");
        suppClass->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 20.f, 960.f, 0.0f, 0.0f);
        suppClass->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
        suppClass->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/powerup.png", true, sf::Vector2f(0.4f, 0.4f), 0, sf::IntRect(519, 1038, 261, 256));
        this->_world.addEntity(suppClass);
        rtype::ecs::entity::Entity *cooldown = new rtype::ecs::entity::Entity(rtype::ecs::entity::COOLDOWN);
        if (cooldown == nullptr)
            throw ScreensExceptions("IntroScreen: Error while creating cooldown entity");
        cooldown->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 20.f, 960.f, 0.0f, 0.0f);
        cooldown->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, 104.f, 102.f, sf::Color(255, 255, 255, 150), false);
        this->_world.addEntity(cooldown);
    } else {
        rtype::ecs::entity::Entity *ship = new rtype::ecs::entity::Entity(rtype::ecs::entity::PLAYER1);
        if (ship == nullptr)
            throw ScreensExceptions("SoloScreen: Error while creating Entity (5)");
        ship->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 500.f, 500.f, 0.0f, 0.0f);
        ship->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
        ship->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
        ship->addComponent<ecs::component::Recruit>(rtype::ecs::component::SHIP);
        ship->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/ships.png", true, sf::Vector2f(4.f, 4.f), 0, sf::IntRect(0, 0, 33, 17));
        this->_world.addEntity(ship);
    }
}

int rtype::menu::SoloScreen::handleEvent(rtype::Event &event, rtype::Game *gameEngine)
{
    (void) gameEngine;
    for (size_t i = 0; i < _world.getEntities().size(); i++) {
        if (_world.getEntity(i)->getEntityType() == rtype::ecs::entity::PLAYER1) {
            managePlayer(i, event);
            break;
        }
    }
    if (_isGameEnded && event.key.enter) {
        saveParalax();
        return 2;
    }
    return 0;
}

void rtype::menu::SoloScreen::update(rtype::Game *gameEngine)
{
    if (!this->_condInit) {
        rtype::Script script(gameEngine->_difficulty);
        _script = script;
        initAllyShip(gameEngine);
        this->_condInit = true;
    }
    if (!_isGameEnded)
        manageGameEnd();
    destroySprites();
    paralax();
    spawnEnemiesFromScript();
    for (size_t i = 0; i < _world.getEntities().size(); i++) {
        if (_world.getEntity(i)->getEntityType() == rtype::ecs::entity::PLAYER1) {
            if (_world.getEntity(i)->getComponent<ecs::component::IShip>(ecs::component::compoType::SHIP)->getIfSkillActive() &&
            (_world.getEntity(i)->getComponent<ecs::component::IShip>(ecs::component::compoType::SHIP)->getShipType() == rtype::ecs::component::shipType::TANK)) {
                break;
            }
            manageEnemiesShooting();
        }
    }
    handleWindowBorder();
    handleHud();
    handleSkillEnd();
    this->_world.update(gameEngine);
    this->_world.draw(gameEngine);
}

bool rtype::menu::SoloScreen::isButtonPressed(size_t index, rtype::Game *gameEngine, rtype::Event &event)
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

bool rtype::menu::SoloScreen::isMouseOnButton(size_t index, rtype::Game *gameEngine, rtype::Event &event)
{
    ecs::component::Drawable2D *rectangleCompo = _world.getEntity(index)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
    ecs::component::Transform *transformCompo = _world.getEntity(index)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
    if (event.global_position.x >= (transformCompo->getX() + gameEngine->_window.getPosition().x) && event.global_position.x <= (transformCompo->getX() + gameEngine->_window.getPosition().x) + rectangleCompo->getWidth() &&
    event.global_position.y >= (transformCompo->getY() + gameEngine->_window.getPosition().y) && event.global_position.y <= (transformCompo->getY() + gameEngine->_window.getPosition().y) + rectangleCompo->getHeight()) {
        return true;
    }
    return false;
}

void rtype::menu::SoloScreen::managePlayer(size_t entityId, rtype::Event &event)
{
    ecs::component::Transform *transformCompo = _world.getEntity(entityId)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
    ecs::component::IShip *shipCompo = _world.getEntity(entityId)->getComponent<ecs::component::IShip>(ecs::component::compoType::SHIP);
    managePlayerMovement(transformCompo, shipCompo, event);
    managePlayerShot(transformCompo, shipCompo, event);
    manageSkill(entityId, shipCompo, event);
}

void rtype::menu::SoloScreen::managePlayerMovement(ecs::component::Transform *transformCompo, ecs::component::IShip *shipCompo, rtype::Event &event)
{
    transformCompo->setSpeedX(0.0f);
    transformCompo->setSpeedY(0.0f);
    if (event.key.right && !event.key.left) {
        transformCompo->setSpeedX(shipCompo->getSpeed());
    }
    if (event.key.left && !event.key.right) {
        transformCompo->setSpeedX(-1 * shipCompo->getSpeed());
    }
    if (event.key.up && !event.key.down) {
        transformCompo->setSpeedY(-1 * shipCompo->getSpeed());
    }
    if (event.key.down && !event.key.up) {
        transformCompo->setSpeedY(shipCompo->getSpeed());
    }
}

void rtype::menu::SoloScreen::managePlayerShot(ecs::component::Transform *transformCompo, ecs::component::IShip *shipCompo, rtype::Event &event)
{
    if (shipCompo->getClock().getElapsedTime() >= shipCompo->getCadency()) {
        if (event.key.code == ' ') {
            rtype::ecs::entity::Entity *shot = new rtype::ecs::entity::Entity(rtype::ecs::entity::ALLY_PROJECTILE);
            if (shot == nullptr)
                throw ScreensExceptions("Error: Can't create a entity (6)");
            shot->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, transformCompo->getX() + 45.f, transformCompo->getY() + 8.f, 25.0f, 0.0f);
            shot->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
            shot->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
            if (shipCompo->getShipType() == rtype::ecs::component::shipType::SNIPER && shipCompo->getIfSkillActive()) {
                shot->addComponent<ecs::component::Projectile>(rtype::ecs::component::PROJECTILE, rtype::ecs::component::projectileType::ALLY_PROJECTILE, shipCompo->getDamage(), true);
                shot->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/projectile.png", true, sf::Vector2f(2.5f, 2.5f), 0, sf::IntRect(165, 133, 50, 17));
            } else {
                shot->addComponent<ecs::component::Projectile>(rtype::ecs::component::PROJECTILE, rtype::ecs::component::projectileType::ALLY_PROJECTILE, shipCompo->getDamage(), false);
                shot->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/projectile.png", true, sf::Vector2f(1.5f, 1.5f), 0, sf::IntRect(165, 133, 50, 17));
            }
            this->_world.addEntity(shot);
            event.key.code = '\0';
            shipCompo->restartClock();
        }
    }
}

void rtype::menu::SoloScreen::manageSkill(size_t entityId, ecs::component::IShip *shipCompo, rtype::Event &event)
{
    if (event.key.code == 'c' && (_clockSkillCooldown.getElapsedTime() >= shipCompo->getSkillCooldown())) {
        shipCompo->setIfSkillActive(true);
        if (shipCompo->getShipType() == rtype::ecs::component::shipType::SUPPORT) {
            _world.getEntity(entityId)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D)->setColor(sf::Color(255, 0, 0, 150));
            shipCompo->setSpeed(7.0f);
            shipCompo->setCadency(sf::seconds(1.0f/8.0f));
        } else if (shipCompo->getShipType() == rtype::ecs::component::shipType::STEALTHY) {
            _world.getEntity(entityId)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D)->setColor(sf::Color(255, 255, 255, 100));
        } else if (shipCompo->getShipType() == rtype::ecs::component::shipType::TANK) {
            for (size_t i = 0; i < _world.getEntities().size(); i++) {
                if (_world.getEntity(i)->getEntityType() == rtype::ecs::entity::ENEMY) {
                    _world.getEntity(i)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D)->setColor(sf::Color(0, 0, 200, 140));
                }
            }
        }
        _clockSkillDuration.restart();
        event.key.code = '\0';
    }
}

void rtype::menu::SoloScreen::handleSkillEnd(void)
{
    for (size_t i = 0; i < _world.getEntities().size(); i++) {
        if (_world.getEntity(i)->getEntityType() == rtype::ecs::entity::PLAYER1) {
            ecs::component::IShip *shipCompo = _world.getEntity(i)->getComponent<ecs::component::IShip>(ecs::component::compoType::SHIP);
            if (shipCompo->getIfSkillActive() == true) {
                if (_clockSkillDuration.getElapsedTime() >= shipCompo->getSkillDuration()) {
                    shipCompo->setIfSkillActive(false);
                    if (shipCompo->getShipType() == rtype::ecs::component::shipType::SUPPORT) {
                        _world.getEntity(i)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D)->setColor(sf::Color(255, 255, 255, 255));
                        shipCompo->setSpeed(5.0f);
                        shipCompo->setCadency(sf::seconds(1.0f/4.0f));
                    } else if (shipCompo->getShipType() == rtype::ecs::component::shipType::STEALTHY) {
                        _world.getEntity(i)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D)->setColor(sf::Color(255, 255, 255, 255));
                    } else if (shipCompo->getShipType() == rtype::ecs::component::shipType::TANK) {
                        for (size_t j = 0; j < _world.getEntities().size(); j++) {
                            if (_world.getEntity(j)->getEntityType() == rtype::ecs::entity::ENEMY) {
                                _world.getEntity(j)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D)->setColor(sf::Color(255, 255, 255, 255));
                            }
                        }
                    }
                    for (size_t k = 0; k < _world.getEntities().size(); k++) {
                        if (_world.getEntity(k)->getEntityType() == rtype::ecs::entity::COOLDOWN)
                            _world.getEntity(k)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D)->setHeight(102.f);
                    }
                    _clockSkillCooldown.restart();
                }
            }
        }
    }
}

void rtype::menu::SoloScreen::destroySprites(void)
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
                if (_world.getEntity(i)->hasCompoType(ecs::component::compoType::SHIP) && (_world.getEntity(i)->getComponent<ecs::component::IShip>(ecs::component::compoType::SHIP)->getShipType() !=
                rtype::ecs::component::shipType::BOSS))
                    createParticle(transformCompo->getX(), transformCompo->getY(), 4.0f, 1);
                else if (_world.getEntity(i)->hasCompoType(ecs::component::compoType::SHIP) && (_world.getEntity(i)->getComponent<ecs::component::IShip>(ecs::component::compoType::SHIP)->getShipType() ==
                rtype::ecs::component::shipType::BOSS)) {
                    createParticle(transformCompo->getX(), transformCompo->getY(), 8.0f, 1);
                    releaseHealthBonus(transformCompo->getX() + 190, transformCompo->getY() + 170);
                }
                else if (_world.getEntity(i)->hasCompoType(ecs::component::compoType::PROJECTILE) &&
                (_world.getEntity(i)->getComponent<ecs::component::Projectile>(ecs::component::compoType::PROJECTILE)->getProjectileType() ==
                rtype::ecs::component::projectileType::ALLY_PROJECTILE))
                    createParticle(transformCompo->getX(), transformCompo->getY(), 4.0f, 2);
                else if (_world.getEntity(i)->hasCompoType(ecs::component::compoType::PROJECTILE) &&
                (_world.getEntity(i)->getComponent<ecs::component::Projectile>(ecs::component::compoType::PROJECTILE)->getProjectileType() ==
                rtype::ecs::component::projectileType::ENEMY_PROJECTILE))
                    createParticle(transformCompo->getX(), transformCompo->getY(), 3.0f, 3);
                _world.removeEntity(i);
            }
        }
    }
}

void rtype::menu::SoloScreen::manageGameEnd(void)
{
    if (_currWave == 11) {
        rtype::ecs::entity::Entity *back = new rtype::ecs::entity::Entity(rtype::ecs::entity::RECTANGLE);
        if (back == nullptr)
            throw ScreensExceptions("IntroScreen: Error while creating Entity (7)");
        back->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 500.f, 200.f, 0.0f, 0.0f);
        sf::Color bgColor(0, 0, 0, 150);
        back->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, 900.f, 500.f, bgColor, true, 3.0f, sf::Color::Magenta);
        this->_world.addEntity(back);
        rtype::ecs::entity::Entity *choose = new rtype::ecs::entity::Entity(rtype::ecs::entity::TEXT);
        if (choose == nullptr)
            throw ScreensExceptions("IntroScreen: Error while creating Entity (8)");
        choose->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 670.f, 450.f, 0.0f, 0.0f);
        sf::Color chooseColor(250, 250, 250, 250);
        choose->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "Press Enter to go back to menu", 40.f, chooseColor, true);
        this->_world.addEntity(choose);
        rtype::ecs::entity::Entity *warning = new rtype::ecs::entity::Entity(rtype::ecs::entity::TEXT);
        if (warning == nullptr)
            throw ScreensExceptions("IntroScreen: Error while creating Entity (9)");
        warning->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 800.f, 300.f, 0.0f, 0.0f);
        sf::Color gameoverColor(0, 0, 250, 250);
        warning->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "You Won", 70.f, gameoverColor, true);
        this->_world.addEntity(warning);
        _isGameEnded = true;
        return;
    }
    for (size_t i = 0; i < _world.getEntities().size(); i++) {
        if (_world.getEntity(i)->getEntityType() == rtype::ecs::entity::PLAYER1)
            return;
    }
    rtype::ecs::entity::Entity *back = new rtype::ecs::entity::Entity(rtype::ecs::entity::RECTANGLE);
    if (back == nullptr)
        throw ScreensExceptions("IntroScreen: Error while creating Entity (??)");
    back->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 500.f, 200.f, 0.0f, 0.0f);
    sf::Color bgColor(0, 0, 0, 150);
    back->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, 900.f, 500.f, bgColor, true, 3.0f, sf::Color::Magenta);
    this->_world.addEntity(back);
    rtype::ecs::entity::Entity *choose = new rtype::ecs::entity::Entity(rtype::ecs::entity::TEXT);
    if (choose == nullptr)
        throw ScreensExceptions("IntroScreen: Error while creating Entity (8)");
    choose->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 670.f, 450.f, 0.0f, 0.0f);
    sf::Color chooseColor(250, 250, 250, 250);
    choose->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "Press Enter to go back to menu", 40.f, chooseColor, true);
    this->_world.addEntity(choose);
    rtype::ecs::entity::Entity *warning = new rtype::ecs::entity::Entity(rtype::ecs::entity::TEXT);
    if (warning == nullptr)
        throw ScreensExceptions("IntroScreen: Error while creating Entity (9)");
    warning->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 800.f, 300.f, 0.0f, 0.0f);
    sf::Color gameoverColor(250, 0, 0, 250);
    warning->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "Game Over", 70.f, gameoverColor, true);
    this->_world.addEntity(warning);
    _isGameEnded = true;
}

void rtype::menu::SoloScreen::createParticle(float x, float y, float scale, int type)
{
    if (type == 1) {
        rtype::ecs::entity::Entity *explosion = new rtype::ecs::entity::Entity(rtype::ecs::entity::PARTICLE);
        if (explosion == nullptr)
            throw ScreensExceptions("SoloScreen: Error while creating particle entity");
        explosion->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, x, y, 0.0f, 0.0f);
        explosion->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
        explosion->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
        explosion->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/explosion.png", true, sf::Vector2f(scale, scale), 0, sf::IntRect(95, 50, 35, 35));
        this->_world.addEntity(explosion);
    } else if (type == 2) {
        rtype::ecs::entity::Entity *hit = new rtype::ecs::entity::Entity(rtype::ecs::entity::HIT);
        if (hit == nullptr)
            throw ScreensExceptions("SoloScreen: Error while creating particle entity");
        hit->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, x + 100.f, y, 0.0f, 0.0f);
        hit->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
        hit->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/hit.png", true, sf::Vector2f(scale, scale), 0, sf::IntRect(246, 303, 20, 18));
        this->_world.addEntity(hit);
    } else if (type == 3) {
        rtype::ecs::entity::Entity *enemyhit = new rtype::ecs::entity::Entity(rtype::ecs::entity::HIT);
        if (enemyhit == nullptr)
            throw ScreensExceptions("SoloScreen: Error while creating particle entity");
        enemyhit->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, x - 100.f, y, 0.0f, 0.0f);
        enemyhit->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
        enemyhit->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/hit.png", true, sf::Vector2f(scale, scale), 0, sf::IntRect(246, 303, 20, 18));
        this->_world.addEntity(enemyhit);
    }
}

void rtype::menu::SoloScreen::manageEnemiesShooting(void)
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
                        throw ScreensExceptions("Error: Can't create an entity (10)");
                    shot->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, transformCompo->getX() - 15.f, transformCompo->getY() + 40.f, -20.0f, 0.0f);
                    shot->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
                    shot->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
                    shot->addComponent<ecs::component::Projectile>(rtype::ecs::component::PROJECTILE, rtype::ecs::component::projectileType::ENEMY_PROJECTILE, shipCompo->getDamage(), false);
                    shot->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/projectile.png", true, sf::Vector2f(1.f, 1.f), 180, sf::IntRect(165, 133, 50, 17));
                    this->_world.addEntity(shot);
                    shipCompo->restartClock();
                }
            } else if (shipCompo->getShipType() == ecs::component::shipType::BOSS) {
                if (shipCompo->getClock().getElapsedTime() >= shipCompo->getCadency()) {
                    ecs::component::Transform *transformCompo = _world.getEntity(i)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
                    rtype::ecs::entity::Entity *mine = new rtype::ecs::entity::Entity(rtype::ecs::entity::ENEMY_PROJECTILE);
                    if (mine == nullptr)
                        throw ScreensExceptions("Error: Can't create an entity (10)");
                    mine->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, transformCompo->getX() + 220.f, transformCompo->getY() + 10.f, 0.0f, -2.0f);
                    mine->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
                    mine->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
                    mine->addComponent<ecs::component::Projectile>(rtype::ecs::component::PROJECTILE, rtype::ecs::component::projectileType::MINE, shipCompo->getDamage(), false);
                    mine->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/mine.png", true, sf::Vector2f(4.f, 4.f), 0, sf::IntRect(0, 0, 18, 18));
                    this->_world.addEntity(mine);
                    shipCompo->restartClock();
                } 
            }
        }
    }
}

void rtype::menu::SoloScreen::generateEnemy(int currWave, int shipType, float x, float y)
{
    if (shipType == 1) {
        rtype::ecs::entity::Entity *enemy = new rtype::ecs::entity::Entity(rtype::ecs::entity::ENEMY);
        if (enemy == nullptr)
            throw ScreensExceptions("SoloScreen: Error while creating enemy entity");
        enemy->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, x, y, 0.0f, 0.15f);
        enemy->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
        enemy->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
        enemy->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/zigzag.png", true, sf::Vector2f(3.f, 3.f), 0, sf::IntRect(34, 34, 32, 32));
        enemy->addComponent<ecs::component::Zigzag>(rtype::ecs::component::SHIP, currWave);
        this->_world.addEntity(enemy);
    } else if (shipType == 2) {
        rtype::ecs::entity::Entity *enemy = new rtype::ecs::entity::Entity(rtype::ecs::entity::ENEMY);
        if (enemy == nullptr)
            throw ScreensExceptions("SoloScreen: Error while creating enemy entity");
        enemy->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, x, y, -5.0f, 0.0f);
        enemy->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
        enemy->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
        enemy->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/rusher.png", true, sf::Vector2f(2.f, 2.f), 0, sf::IntRect(50, 0, 65, 60));
        enemy->addComponent<ecs::component::Rusher>(rtype::ecs::component::SHIP, currWave);
        this->_world.addEntity(enemy);
    } else if (shipType == 3) {
        rtype::ecs::entity::Entity *enemy = new rtype::ecs::entity::Entity(rtype::ecs::entity::ENEMY);
        if (enemy == nullptr)
            throw ScreensExceptions("SoloScreen: Error while creating enemy entity");
        enemy->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, x, y, -8.0f, 0.0f);
        enemy->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
        enemy->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
        enemy->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/kamikaze.png", true, sf::Vector2f(2.f, 2.f), 0, sf::IntRect(75, 50, 60, 50));
        enemy->addComponent<ecs::component::Kamikaze>(rtype::ecs::component::SHIP, currWave);
        this->_world.addEntity(enemy);
    } else if (shipType == 4) {
        rtype::ecs::entity::Entity *enemy = new rtype::ecs::entity::Entity(rtype::ecs::entity::ENEMY);
        if (enemy == nullptr)
            throw ScreensExceptions("SoloScreen: Error while creating enemy entity");
        enemy->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, x, y, -3.0f, 0.0f);
        enemy->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
        enemy->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
        enemy->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/turret.png", true, sf::Vector2f(4.f, 4.f), 0, sf::IntRect(0, 0, 32, 32));
        enemy->addComponent<ecs::component::Turret>(rtype::ecs::component::SHIP, currWave);
        this->_world.addEntity(enemy);
    } else if (shipType == 5) {
        rtype::ecs::entity::Entity *enemy = new rtype::ecs::entity::Entity(rtype::ecs::entity::ENEMY);
        if (enemy == nullptr)
            throw ScreensExceptions("SoloScreen: Error while creating enemy entity");
        enemy->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, x, y, -2.0f, 0.0f);
        enemy->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
        enemy->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
        enemy->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/boss.png", true, sf::Vector2f(2.5f, 2.5f), 0, sf::IntRect(0, 0, 260, 143));
        enemy->addComponent<ecs::component::Boss>(rtype::ecs::component::SHIP, currWave);
        this->_world.addEntity(enemy);
    }
}

void rtype::menu::SoloScreen::spawnEnemiesFromScript(void)
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
            if (_world.getEntity(i)->getEntityType() == rtype::ecs::entity::ENEMY || (_currWave > 10)) {
                return;
            }
        }
        _currWave++;
        printWaveNumber();
        _script.restartClock();
    }
    if (_clockScriptCall.getElapsedTime() >= sf::seconds(1.0f)) {
        for (size_t i = 0; i < _script.getWave(_currWave).size(); i++) {
            if (_script.getWave(_currWave).at(i).size() == 6 && _script.getWave(_currWave).at(i).at(5)) {
                if (_script.getClock().getElapsedTime() >= sf::seconds(static_cast<float>(_script.getWave(_currWave).at(i).at(0)))) {
                    generateEnemy(_script.getWave(_currWave).at(i).at(1),  _script.getWave(_currWave).at(i).at(2),
                    static_cast<float>(_script.getWave(_currWave).at(i).at(3)), static_cast<float>(_script.getWave(_currWave).at(i).at(4)));
                    _script.spriteIsPrinted(_currWave, i);
                }
            }
        }
        _clockScriptCall.restart();
    }
}

void rtype::menu::SoloScreen::printWaveNumber(void)
{
    rtype::ecs::entity::Entity *wave = new rtype::ecs::entity::Entity(rtype::ecs::entity::TEXT);
    if (wave == nullptr)
        throw ScreensExceptions("MultiplayerScreen: Error while creating the wave number entity");
    wave->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 800.f, 450.f, 0.0f, 0.0f);
    sf::Color textColor(250, 250, 250, 150);
    wave->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "Wave " + std::to_string(_currWave), 120.f, textColor, true);
    this->_world.addEntity(wave);
}

sf::Time rtype::menu::SoloScreen::getWaveDuration(void)
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
            tmp = sf::seconds(17.f);
            break;
        case 4:
            tmp = sf::seconds(20.f);
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

void rtype::menu::SoloScreen::handleHud(void)
{
    for (size_t i = 0; i < _world.getEntities().size(); i++) {
        if (_world.getEntity(i)->getEntityType() == rtype::ecs::entity::PLAYER1) {
            auto shipCompo = _world.getEntity(i)->getComponent<ecs::component::IShip>(ecs::component::compoType::SHIP);
            for (size_t j = 0; j < _world.getEntities().size(); j++) {
                if (_world.getEntity(j)->getEntityType() == rtype::ecs::entity::COOLDOWN) {
                    auto drawableCompo = _world.getEntity(j)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
                    sf::Time tmp = _clockSkillCooldown.getElapsedTime();
                    sf::Time cd = shipCompo->getSkillCooldown();
                    if (drawableCompo->getHeight() >= 0)
                        drawableCompo->setHeight(((102.f / cd.asSeconds()) * (cd.asSeconds() - tmp.asSeconds())));
                }
            }
        }
    }
    for (size_t i = 0; i < _world.getEntities().size(); i++) {
        if (_world.getEntity(i)->getEntityType() == rtype::ecs::entity::PLAYER1) {
            auto shipCompo = _world.getEntity(i)->getComponent<ecs::component::IShip>(ecs::component::compoType::SHIP);
            auto transformCompo = _world.getEntity(i)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
            for (size_t j = 0; j < _world.getEntities().size(); j++) {
                if (_world.getEntity(j)->getEntityType() == rtype::ecs::entity::HEART) {
                    auto transformCompo2 = _world.getEntity(j)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
                    auto drawableCompo2 = _world.getEntity(j)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
                    drawableCompo2->setWidth(80.f - ((80.f / shipCompo->getMaxHealth()) * (shipCompo->getMaxHealth() - shipCompo->getHealth())));
                    if (drawableCompo2->getWidth() <= 30.f)
                        drawableCompo2->setColor(sf::Color::Red);
                    else if (drawableCompo2->getWidth() > 30.f && drawableCompo2->getWidth() <= 75.f)
                        drawableCompo2->setColor(sf::Color(250, 125, 0));
                    transformCompo2->setX(transformCompo->getX());
                    transformCompo2->setY(transformCompo->getY());
                    return;
                }
            }
        }
    }
    for (size_t k = 0; k < _world.getEntities().size(); k++) {
        if (_world.getEntity(k)->getEntityType() == rtype::ecs::entity::HEART) {
            _world.removeEntity(k);
        }
    }
}

void rtype::menu::SoloScreen::releaseHealthBonus(float x, float y)
{
    rtype::ecs::entity::Entity *healthBonus = new rtype::ecs::entity::Entity(rtype::ecs::entity::HEALTHBONUS);
    if (healthBonus == nullptr)
        throw ScreensExceptions("SoloScreen: Error while creating health bonus entity");
    healthBonus->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, x, y, 0.0f, 0.0f);
    healthBonus->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
    healthBonus->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
    healthBonus->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/powerup.png", true, sf::Vector2f(0.2f, 0.2f), 0, sf::IntRect(1191, 725, 261, 256));
    this->_world.addEntity(healthBonus);
}

void rtype::menu::SoloScreen::saveParalax(void)
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

void rtype::menu::SoloScreen::paralax(void)
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

void rtype::menu::SoloScreen::handleWindowBorder(void)
{
    for (size_t i = 0; i < _world.getEntities().size(); i++) {
        if (_world.getEntity(i)->getEntityType() == rtype::ecs::entity::PLAYER1) {
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