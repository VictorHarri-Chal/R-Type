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

rtype::menu::CoreScreen::CoreScreen()
{
}

void rtype::menu::CoreScreen::init()
{
    rtype::ecs::system::ISystem *draw2DSystemMenu = new rtype::ecs::system::Draw2DSystem();
    this->_world.addSystem(draw2DSystemMenu);
    rtype::ecs::system::ISystem *movementSystemMenu = new rtype::ecs::system::MovementSystem();
    this->_world.addSystem(movementSystemMenu);
    rtype::ecs::system::ISystem *collideSystemMenu = new rtype::ecs::system::CollideSystem();
    this->_world.addSystem(collideSystemMenu);
    rtype::ecs::system::ISystem *enemypathSystemMenu = new rtype::ecs::system::EnemypathSystem();
    this->_world.addSystem(enemypathSystemMenu);

    rtype::ecs::entity::Entity *bg = new rtype::ecs::entity::Entity(rtype::ecs::entity::STATIC_SPRITE);
    bg->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, bg_x, 0.0f, -0.5f, 0.0f);
    bg->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
    bg->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/bg.png", false, sf::Vector2f(1.f, 1.f), 0);
    this->_world.addEntity(bg);
    rtype::ecs::entity::Entity *stars = new rtype::ecs::entity::Entity(rtype::ecs::entity::STATIC_SPRITE);
    stars->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, stars_x, 0.0f, -0.7f, 0.0f);
    stars->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
    stars->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/bg2.png", false, sf::Vector2f(1.f, 1.f), 0);
    this->_world.addEntity(stars);
    rtype::ecs::entity::Entity *planets = new rtype::ecs::entity::Entity(rtype::ecs::entity::STATIC_SPRITE);
    planets->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, planets_x, 0.0f, -1.0f, 0.0f);
    planets->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
    planets->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/bg3.png", false, sf::Vector2f(1.f, 1.f), 0);
    this->_world.addEntity(planets);
    rtype::ecs::entity::Entity *bigPlanet = new rtype::ecs::entity::Entity(rtype::ecs::entity::STATIC_SPRITE);
    bigPlanet->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, bigPlanet_x, 700.f, -1.2f, 0.0f);
    bigPlanet->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
    bigPlanet->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/bg4.png", false, sf::Vector2f(3.f, 3.f), 0);
    this->_world.addEntity(bigPlanet);

    rtype::ecs::entity::Entity *ship = new rtype::ecs::entity::Entity(rtype::ecs::entity::PLAYER);
    ship->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 500.f, 50.f, 0.0f, 0.0f);
    ship->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
    ship->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
    ship->addComponent<ecs::component::Recruit>(rtype::ecs::component::SHIP);
    ship->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/ships.png", true, sf::Vector2f(4.f, 4.f), 0, sf::IntRect(0, 0, 33, 17));
    this->_world.addEntity(ship);

    generateEnemy(rtype::ecs::component::shipType::ZIGZAG, true, true, 1, 1000.f, 1100.f, "assets/enemy_1.png", true, sf::Vector2f(4.f, 4.f), 0, sf::IntRect(34, 33, 32, 32));
    generateEnemy(rtype::ecs::component::shipType::ZIGZAG, true, true, 1, 1100.f, 1100.f, "assets/enemy_1.png", true, sf::Vector2f(4.f, 4.f), 0, sf::IntRect(34, 33, 32, 32));
    generateEnemy(rtype::ecs::component::shipType::ZIGZAG, true, true, 1, 1300.f, 1100.f, "assets/enemy_1.png", true, sf::Vector2f(4.f, 4.f), 0, sf::IntRect(34, 33, 32, 32));
    generateEnemy(rtype::ecs::component::shipType::ZIGZAG, true, true, 1, 1400.f, 1100.f, "assets/enemy_1.png", true, sf::Vector2f(4.f, 4.f), 0, sf::IntRect(34, 33, 32, 32));
}

int rtype::menu::CoreScreen::handleEvent(rtype::Event &event, rtype::Game *gameEngine)
{
    destroySprites(event, gameEngine);
    managePlayerMovement(event, gameEngine);
    managePlayerShot(event, gameEngine);
    return 0;
}

void rtype::menu::CoreScreen::update(rtype::Game *gameEngine)
{   
    paralax();
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

void rtype::menu::CoreScreen::managePlayerMovement(rtype::Event &event, rtype::Game *gameEngine)
{
    (void) gameEngine;
    ecs::component::Transform *transformCompo = _world.getEntity(4)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
    transformCompo->setSpeedX(0.0f);
    transformCompo->setSpeedY(0.0f);
    if (event.key.right && !event.key.left )
        transformCompo->setSpeedX(5.0f);
    if (event.key.left && !event.key.right)
        transformCompo->setSpeedX(-5.0f);
    if (event.key.up && !event.key.down)
        transformCompo->setSpeedY(-5.0f);
    if (event.key.down && !event.key.up)
        transformCompo->setSpeedY(5.0f);
}

void rtype::menu::CoreScreen::managePlayerShot(rtype::Event &event, rtype::Game *gameEngine)
{
    (void) gameEngine;
    if (_clock.getElapsedTime() >= sf::seconds(1.0/6.0f)) {
        if (event.key.code == ' ') {
            ecs::component::Transform *transformCompo = _world.getEntity(4)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
            rtype::ecs::entity::Entity *shot = new rtype::ecs::entity::Entity(rtype::ecs::entity::ALLY_PROJECTILE);
            shot->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, transformCompo->getX() + 45.f, transformCompo->getY() + 8.f, 25.0f, 0.0f);
            shot->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
            shot->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
            shot->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/projectile.png", true, sf::Vector2f(2.f, 2.f), 0, sf::IntRect(165, 133, 50, 17));
            this->_world.addEntity(shot);
            event.key.code = '\0';
            _clock.restart();
        }
    }
}

void rtype::menu::CoreScreen::destroySprites(rtype::Event &event, rtype::Game *gameEngine)
{
    (void) gameEngine;
    (void) event;
    for (size_t i = 0; i < _world.getEntities().size(); i++) {
        ecs::component::Transform *transformCompo = _world.getEntity(i)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
        if (transformCompo->getX() > 1920) {
            _world.removeEntity(i);
        }
        else if (_world.getEntity(i)->hasCompoType(rtype::ecs::component::compoType::ALIVE)) {
            ecs::component::Alive *aliveCompo = _world.getEntity(i)->getComponent<ecs::component::Alive>(ecs::component::compoType::ALIVE);
            if (!aliveCompo->getAlive()) {
                _world.removeEntity(i);
            }
        }
    }
}

void rtype::menu::CoreScreen::generateEnemy(rtype::ecs::component::shipType shipType, bool dirHor, bool dirVer, int currWave, float x, float y,
    std::string asset, bool isRect, sf::Vector2f scale, int rotation, sf::IntRect rect)
{
    rtype::ecs::entity::Entity *enemy = new rtype::ecs::entity::Entity(rtype::ecs::entity::ENEMY);
    enemy->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, x, y, 0.15f, 0.15f);
    enemy->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
    enemy->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
    enemy->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, asset, isRect, scale, rotation, rect);
    if (shipType == rtype::ecs::component::shipType::ZIGZAG)
        enemy->addComponent<ecs::component::Zigzag>(rtype::ecs::component::SHIP, dirHor, dirVer, currWave);
    this->_world.addEntity(enemy);
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