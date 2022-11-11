/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** HtpScreen.cpp
*/

#include "HtpScreen.hpp"
#include "../../../ecs/System/Draw2D/draw2d.hpp"
#include "../../../ecs/System/Movement/movement.hpp"
#include "../../../ecs/System/Enemypath/enemypath.hpp"
#include "../../../exceptions/ScreensExceptions.hpp"

rtype::menu::HtpScreen::HtpScreen()
{
}

void rtype::menu::HtpScreen::init()
{
    rtype::ecs::system::ISystem *draw2DSystemMenu = new rtype::ecs::system::Draw2DSystem();
    if (draw2DSystemMenu == nullptr)
        throw ScreensExceptions("HtpScreen: Error while creating Draw2DSystem");
    this->_world.addSystem(draw2DSystemMenu);
    rtype::ecs::system::ISystem *movementSystemMenu = new rtype::ecs::system::MovementSystem();
    if (movementSystemMenu == nullptr)
        throw ScreensExceptions("HtpScreen: Error while creating MovementSystem");
    this->_world.addSystem(movementSystemMenu);
    rtype::ecs::system::ISystem *enemypathSystemMenu = new rtype::ecs::system::EnemypathSystem();
    if (enemypathSystemMenu == nullptr)
        throw ScreensExceptions("HtpScreen: Error while creating EnemypathSystem");
    this->_world.addSystem(enemypathSystemMenu);

    rtype::ecs::entity::Entity *bg = new rtype::ecs::entity::Entity(rtype::ecs::entity::STATIC_SPRITE);
    if (bg == nullptr)
        throw ScreensExceptions("HtpScreen: Error while creating Entity (1)");
    bg->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, bg_x, 0.0f, -0.5f, 0.0f);
    bg->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
    bg->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/bg.png", false, sf::Vector2f(1.f, 1.f), 0);
    this->_world.addEntity(bg);
    rtype::ecs::entity::Entity *stars = new rtype::ecs::entity::Entity(rtype::ecs::entity::STATIC_SPRITE);
    if (stars == nullptr)
        throw ScreensExceptions("HtpScreen: Error while creating Entity (2)");
    stars->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, stars_x, 0.0f, -0.7f, 0.0f);
    stars->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
    stars->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/bg2.png", false, sf::Vector2f(1.f, 1.f), 0);
    this->_world.addEntity(stars);
    rtype::ecs::entity::Entity *planets = new rtype::ecs::entity::Entity(rtype::ecs::entity::STATIC_SPRITE);
    if (planets == nullptr)
        throw ScreensExceptions("HtpScreen: Error while creating Entity (3)");
    planets->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, planets_x, 0.0f, -1.0f, 0.0f);
    planets->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
    planets->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/bg3.png", false, sf::Vector2f(1.f, 1.f), 0);
    this->_world.addEntity(planets);
    rtype::ecs::entity::Entity *bigPlanet = new rtype::ecs::entity::Entity(rtype::ecs::entity::STATIC_SPRITE);
    if (bigPlanet == nullptr)
        throw ScreensExceptions("HtpScreen: Error while creating Entity (4)");
    bigPlanet->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, bigPlanet_x, 700.f, -1.2f, 0.0f);
    bigPlanet->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
    bigPlanet->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/bg4.png", false, sf::Vector2f(3.f, 3.f), 0);
    this->_world.addEntity(bigPlanet);

    rtype::ecs::entity::Entity *quit = new rtype::ecs::entity::Entity(rtype::ecs::entity::STATIC_SPRITE);
    if (quit == nullptr)
        throw ScreensExceptions("HtpScreen: Error while creating Entity (5)");
    quit->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 1760.f, 10.f, 0.0f, 0.0f);
    quit->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/cross.png", false, sf::Vector2f(0.3f, 0.3f), 0);
    this->_world.addEntity(quit);
    rtype::ecs::entity::Entity *ship = new rtype::ecs::entity::Entity(rtype::ecs::entity::PLAYER1);
    if (ship == nullptr)
        throw ScreensExceptions("SoloScreen: Error while creating Entity (6)");
    ship->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 500.f, 500.f, 0.0f, 0.0f);
    ship->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
    ship->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/ships.png", true, sf::Vector2f(4.f, 4.f), 0, sf::IntRect(0, 0, 33, 17));
    this->_world.addEntity(ship);
    rtype::ecs::entity::Entity *lifebar = new rtype::ecs::entity::Entity(rtype::ecs::entity::HEART);
    if (lifebar == nullptr)
        throw ScreensExceptions("SoloScreen: Error while creating Entity (7)");
    lifebar->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 500.f, 495.f, 0.0f, 0.0f);
    lifebar->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, 80.f, 6.f, sf::Color::Green, false);
    this->_world.addEntity(lifebar);
    rtype::ecs::entity::Entity *arrow = new rtype::ecs::entity::Entity(rtype::ecs::entity::STATIC_SPRITE);
    if (arrow == nullptr)
        throw ScreensExceptions("HtpScreen: Error while creating Entity (8)");
    arrow->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 100.f, 700.f, 0.0f, 0.0f);
    arrow->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/arrow.png", false, sf::Vector2f(0.5f, 0.5f), 0);
    this->_world.addEntity(arrow);
    rtype::ecs::entity::Entity *space = new rtype::ecs::entity::Entity(rtype::ecs::entity::STATIC_SPRITE);
    if (space == nullptr)
        throw ScreensExceptions("HtpScreen: Error while creating Entity (9)");
    space->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 600.f, 730.f, 0.0f, 0.0f);
    space->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/space.png", false, sf::Vector2f(0.6f, 0.6f), 0);
    this->_world.addEntity(space);
    rtype::ecs::entity::Entity *moveText = new rtype::ecs::entity::Entity(rtype::ecs::entity::TEXT);
    if (moveText == nullptr)
        throw ScreensExceptions("MenuScreen: Error while creating Entity (10)");
    moveText->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 220.f, 860.f, 0.0f, 0.0f);
    moveText->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "Move", 30.f, sf::Color::Cyan, true);
    this->_world.addEntity(moveText);
    rtype::ecs::entity::Entity *shootText = new rtype::ecs::entity::Entity(rtype::ecs::entity::TEXT);
    if (shootText == nullptr)
        throw ScreensExceptions("MenuScreen: Error while creating Entity (11)");
    shootText->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 630.f, 860.f, 0.0f, 0.0f);
    shootText->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "Shoot", 30.f, sf::Color::Cyan, true);
    this->_world.addEntity(shootText);
    rtype::ecs::entity::Entity *enemy = new rtype::ecs::entity::Entity(rtype::ecs::entity::ENEMY);
    if (enemy == nullptr)
        throw ScreensExceptions("SoloScreen: Error while creating enemy entity");
    enemy->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 1000.f, 1100.f, 0.0f, 0.15f);
    enemy->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
    enemy->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
    enemy->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/zigzag.png", true, sf::Vector2f(3.f, 3.f), 0, sf::IntRect(34, 34, 32, 32));
    enemy->addComponent<ecs::component::Zigzag>(rtype::ecs::component::SHIP, 1);
    this->_world.addEntity(enemy);
    rtype::ecs::entity::Entity *enemy2 = new rtype::ecs::entity::Entity(rtype::ecs::entity::ENEMY);
    if (enemy2 == nullptr)
        throw ScreensExceptions("SoloScreen: Error while creating enemy entity");
    enemy2->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 1200.f, -100.f, 0.0f, 0.15f);
    enemy2->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
    enemy2->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
    enemy2->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/zigzag.png", true, sf::Vector2f(3.f, 3.f), 0, sf::IntRect(34, 34, 32, 32));
    enemy2->addComponent<ecs::component::Zigzag>(rtype::ecs::component::SHIP, 1);
    this->_world.addEntity(enemy2);
    rtype::ecs::entity::Entity *enemy3 = new rtype::ecs::entity::Entity(rtype::ecs::entity::ENEMY);
    if (enemy3 == nullptr)
        throw ScreensExceptions("SoloScreen: Error while creating enemy entity");
    enemy3->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 1400.f, 1100.f, 0.0f, 0.15f);
    enemy3->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
    enemy3->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
    enemy3->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/zigzag.png", true, sf::Vector2f(3.f, 3.f), 0, sf::IntRect(34, 34, 32, 32));
    enemy3->addComponent<ecs::component::Zigzag>(rtype::ecs::component::SHIP, 1);
    this->_world.addEntity(enemy3);

}

int rtype::menu::HtpScreen::handleEvent(rtype::Event &event, rtype::Game *gameEngine)
{
    if (isButtonPressed(4, gameEngine, event)) {
        saveParalax();
        return 2;
    }
    return 0;
}

void rtype::menu::HtpScreen::update(rtype::Game *gameEngine)
{
    paralax();
    this->_world.update(gameEngine);
    this->_world.draw(gameEngine);
}

bool rtype::menu::HtpScreen::isButtonPressed(size_t index, rtype::Game *gameEngine, rtype::Event &event)
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

bool rtype::menu::HtpScreen::isMouseOnButton(size_t index, rtype::Game *gameEngine, rtype::Event &event)
{
    ecs::component::Drawable2D *rectangleCompo = _world.getEntity(index)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
    ecs::component::Transform *transformCompo = _world.getEntity(index)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
    if (event.global_position.x >= (transformCompo->getX() + gameEngine->_window.getPosition().x) && event.global_position.x <= (transformCompo->getX() + gameEngine->_window.getPosition().x) + rectangleCompo->getWidth() &&
    event.global_position.y >= (transformCompo->getY() + gameEngine->_window.getPosition().y) && event.global_position.y <= (transformCompo->getY() + gameEngine->_window.getPosition().y) + rectangleCompo->getHeight()) {
        return true;
    }
    return false;
}

void rtype::menu::HtpScreen::saveParalax(void)
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

void rtype::menu::HtpScreen::paralax(void)
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