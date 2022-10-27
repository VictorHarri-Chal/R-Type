/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** CoreScreen.cpp
*/

#include "CoreScreen.hpp"
#include "../../../ecs/System/Draw2D/draw2d.hpp"
#include "../../../ecs/System/Movement/movement.hpp"
#include "../../../ecs/System/Collide/collide.hpp"
#include "../../../ecs/System/Enemypath/enemypath.hpp"
#include "../../../exceptions/ScreensExceptions.hpp"

rtype::menu::CoreScreen::CoreScreen()
{
}

void rtype::menu::CoreScreen::init()
{
    rtype::ecs::system::ISystem *draw2DSystemMenu = new rtype::ecs::system::Draw2DSystem();
    if (draw2DSystemMenu == nullptr)
        throw ScreensExceptions("CoreScreen: Error while creating Draw2DSystem");
    this->_world.addSystem(draw2DSystemMenu);
    rtype::ecs::system::ISystem *movementSystemMenu = new rtype::ecs::system::MovementSystem();
    if (movementSystemMenu == nullptr)
        throw ScreensExceptions("CoreScreen: Error while creating MovementSystem");
    this->_world.addSystem(movementSystemMenu);
    rtype::ecs::system::ISystem *collideSystemMenu = new rtype::ecs::system::CollideSystem();
    if (collideSystemMenu == nullptr)
        throw ScreensExceptions("CoreScreen: Error while creating CollideSystem");
    this->_world.addSystem(collideSystemMenu);
    rtype::ecs::system::ISystem *enemypathSystemMenu = new rtype::ecs::system::EnemypathSystem();
    if (enemypathSystemMenu == nullptr)
        throw ScreensExceptions("CoreScreen: Error while creating EnemypathSystem");
    this->_world.addSystem(enemypathSystemMenu);

    rtype::ecs::entity::Entity *bg = new rtype::ecs::entity::Entity(rtype::ecs::entity::STATIC_SPRITE);
    if (bg == nullptr)
        throw ScreensExceptions("CoreScreen: Error while creating Entity (1)");
    bg->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, bg_x, 0.0f, -0.5f, 0.0f);
    bg->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
    bg->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/bg.png", false, sf::Vector2f(1.f, 1.f), 0);
    this->_world.addEntity(bg);
    rtype::ecs::entity::Entity *stars = new rtype::ecs::entity::Entity(rtype::ecs::entity::STATIC_SPRITE);
    if (stars == nullptr)
        throw ScreensExceptions("CoreScreen: Error while creating Entity (2)");
    stars->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, stars_x, 0.0f, -0.7f, 0.0f);
    stars->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
    stars->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/bg2.png", false, sf::Vector2f(1.f, 1.f), 0);
    this->_world.addEntity(stars);
    rtype::ecs::entity::Entity *planets = new rtype::ecs::entity::Entity(rtype::ecs::entity::STATIC_SPRITE);
    if (planets == nullptr)
        throw ScreensExceptions("CoreScreen: Error while creating Entity (3)");
    planets->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, planets_x, 0.0f, -1.0f, 0.0f);
    planets->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
    planets->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/bg3.png", false, sf::Vector2f(1.f, 1.f), 0);
    this->_world.addEntity(planets);
    rtype::ecs::entity::Entity *bigPlanet = new rtype::ecs::entity::Entity(rtype::ecs::entity::STATIC_SPRITE);
    if (bigPlanet == nullptr)
        throw ScreensExceptions("CoreScreen: Error while creating Entity (4)");
    bigPlanet->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, bigPlanet_x, 700.f, -1.2f, 0.0f);
    bigPlanet->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
    bigPlanet->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/bg4.png", false, sf::Vector2f(3.f, 3.f), 0);
    this->_world.addEntity(bigPlanet);

    rtype::ecs::entity::Entity *ship = new rtype::ecs::entity::Entity(rtype::ecs::entity::PLAYER);
    if (ship == nullptr)
        throw ScreensExceptions("CoreScreen: Error while creating Entity (5)");
    ship->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 500.f, 50.f, 0.0f, 0.0f);
    ship->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
    ship->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
    ship->addComponent<ecs::component::Recruit>(rtype::ecs::component::SHIP);
    ship->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/ships.png", true, sf::Vector2f(4.f, 4.f), 0, sf::IntRect(0, 0, 33, 17));
    this->_world.addEntity(ship);

    generateEnemy(rtype::ecs::component::shipType::ZIGZAG, true, true, 1, 1000.f, 1100.f);
    generateEnemy(rtype::ecs::component::shipType::RUSHER, false, false, 1, 1930.f, 600.f);
    generateEnemy(rtype::ecs::component::shipType::KAMIKAZE, false, false, 1, 1100.f, -100.f);
    // generateEnemy(rtype::ecs::component::shipType::ZIGZAG, true, false, 1, 1100.f, -100.f);
    // generateEnemy(rtype::ecs::component::shipType::ZIGZAG, true, true, 1, 1300.f, 1100.f);
    // generateEnemy(rtype::ecs::component::shipType::ZIGZAG, true, false, 1, 1400.f, -100.f);
}

int rtype::menu::CoreScreen::handleEvent(rtype::Event &event, rtype::Game *gameEngine)
{
    (void) gameEngine;
    for (size_t i = 0; i < _world.getEntities().size(); i++) {
        if (_world.getEntity(i)->getEntityType() == rtype::ecs::entity::PLAYER) {
            managePlayer(i, event);
            break;
        }
    }
    return 0;
}

void rtype::menu::CoreScreen::update(rtype::Game *gameEngine)
{   
    destroySprites();
    paralax();
    manageEnemiesShooting();
    handleWindowBorder();
    this->_world.update(gameEngine);
    this->_world.draw(gameEngine);
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

void rtype::menu::CoreScreen::managePlayer(size_t entityId, rtype::Event &event)
{
    ecs::component::Transform *transformCompo = _world.getEntity(entityId)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
    ecs::component::IShip *shipCompo = _world.getEntity(entityId)->getComponent<ecs::component::IShip>(ecs::component::compoType::SHIP);
    managePlayerMovement(transformCompo, shipCompo, event);
    managePlayerShot(transformCompo, shipCompo, event);
}

void rtype::menu::CoreScreen::managePlayerMovement(ecs::component::Transform *transformCompo, ecs::component::IShip *shipCompo, rtype::Event &event)
{
    transformCompo->setSpeedX(0.0f);
    transformCompo->setSpeedY(0.0f);
    if (event.key.right && !event.key.left )
        transformCompo->setSpeedX(shipCompo->getSpeed());
    if (event.key.left && !event.key.right)
        transformCompo->setSpeedX(-1 * shipCompo->getSpeed());
    if (event.key.up && !event.key.down)
        transformCompo->setSpeedY(-1 * shipCompo->getSpeed());
    if (event.key.down && !event.key.up)
        transformCompo->setSpeedY(shipCompo->getSpeed());
}

void rtype::menu::CoreScreen::managePlayerShot(ecs::component::Transform *transformCompo, ecs::component::IShip *shipCompo, rtype::Event &event)
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
            }
        }
        else if (_world.getEntity(i)->hasCompoType(rtype::ecs::component::compoType::ALIVE)) {
            ecs::component::Alive *aliveCompo = _world.getEntity(i)->getComponent<ecs::component::Alive>(ecs::component::compoType::ALIVE);
            if (!aliveCompo->getAlive()) {
                _world.removeEntity(i);
            }
        }
    }
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
                    shot->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, transformCompo->getX() - 15.f, transformCompo->getY() + 45.f, -20.0f, 0.0f);
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

void rtype::menu::CoreScreen::generateEnemy(rtype::ecs::component::shipType shipType, bool dirHor, bool dirVer, int currWave, float x, float y)
{
    if (shipType == rtype::ecs::component::shipType::ZIGZAG) {
        rtype::ecs::entity::Entity *enemy = new rtype::ecs::entity::Entity(rtype::ecs::entity::ENEMY);
        enemy->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, x, y, 0.0f, 0.15f);
        enemy->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
        enemy->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
        enemy->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/zigzag.png", true, sf::Vector2f(4.f, 4.f), 0, sf::IntRect(34, 33, 32, 32));
        enemy->addComponent<ecs::component::Zigzag>(rtype::ecs::component::SHIP, dirHor, dirVer, currWave);
        this->_world.addEntity(enemy);
    } else if (shipType == rtype::ecs::component::shipType::RUSHER) {
        rtype::ecs::entity::Entity *enemy = new rtype::ecs::entity::Entity(rtype::ecs::entity::ENEMY);
        enemy->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, x, y, -5.0f, 0.0f);
        enemy->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
        enemy->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
        enemy->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/rusher.png", true, sf::Vector2f(2.f, 2.f), 0, sf::IntRect(50, 0, 65, 60));
        enemy->addComponent<ecs::component::Rusher>(rtype::ecs::component::SHIP, currWave);
        this->_world.addEntity(enemy);
    } else if (shipType == rtype::ecs::component::shipType::KAMIKAZE) {
        rtype::ecs::entity::Entity *enemy = new rtype::ecs::entity::Entity(rtype::ecs::entity::ENEMY);
        enemy->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, x, y, -7.0f, 0.0f);
        enemy->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
        enemy->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
        enemy->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/kamikaze.png", true, sf::Vector2f(1.f, 1.f), 0, sf::IntRect(75, 50, 60, 50));
        enemy->addComponent<ecs::component::Kamikaze>(rtype::ecs::component::SHIP, currWave);
        this->_world.addEntity(enemy);
    } else if (shipType == rtype::ecs::component::shipType::TURRET) {
        rtype::ecs::entity::Entity *enemy = new rtype::ecs::entity::Entity(rtype::ecs::entity::ENEMY);
        enemy->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, x, y, -3.0f, 0.0f);
        enemy->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
        enemy->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
        enemy->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/turret.png", true, sf::Vector2f(1.f, 1.f), 0, sf::IntRect(0, 0, 0, 0));
        enemy->addComponent<ecs::component::Turret>(rtype::ecs::component::SHIP, currWave);
        this->_world.addEntity(enemy);
    }
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
        if (_world.getEntity(i)->getEntityType() == rtype::ecs::entity::PLAYER) {
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