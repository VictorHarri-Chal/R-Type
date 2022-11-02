/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** MenuScreen.cpp
*/

#include "MenuScreen.hpp"
#include "../../../ecs/System/Draw2D/draw2d.hpp"
#include "../../../ecs/System/Movement/movement.hpp"
#include "../../../exceptions/ScreensExceptions.hpp"

rtype::menu::MenuScreen::MenuScreen()
{
}

void rtype::menu::MenuScreen::init()
{
    rtype::ecs::system::ISystem *draw2DSystemMenu = new rtype::ecs::system::Draw2DSystem();
    if (draw2DSystemMenu == nullptr)
        throw ScreensExceptions("MenuScreen: Error while creating Draw2DSystem");
    this->_world.addSystem(draw2DSystemMenu);
    rtype::ecs::system::ISystem *movementSystemMenu = new rtype::ecs::system::MovementSystem();
    if (movementSystemMenu == nullptr)
        throw ScreensExceptions("MenuScreen: Error while creating MovementSystem");
    this->_world.addSystem(movementSystemMenu);

    rtype::ecs::entity::Entity *bg = new rtype::ecs::entity::Entity(rtype::ecs::entity::STATIC_SPRITE);
    if (bg == nullptr)
        throw ScreensExceptions("MenuScreen: Error while creating Entity (1)");
    bg->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, bg_x, 0.0f, -0.5f, 0.0f);
    bg->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
    bg->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/bg.png", false, sf::Vector2f(1.f, 1.f), 0);
    this->_world.addEntity(bg);
    rtype::ecs::entity::Entity *stars = new rtype::ecs::entity::Entity(rtype::ecs::entity::STATIC_SPRITE);
    if (stars == nullptr)
        throw ScreensExceptions("MenuScreen: Error while creating Entity (2)");
    stars->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, stars_x, 0.0f, -0.7f, 0.0f);
    stars->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
    stars->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/bg2.png", false, sf::Vector2f(1.f, 1.f), 0);
    this->_world.addEntity(stars);
    rtype::ecs::entity::Entity *planets = new rtype::ecs::entity::Entity(rtype::ecs::entity::STATIC_SPRITE);
    if (planets == nullptr)
        throw ScreensExceptions("MenuScreen: Error while creating Entity (3)");
    planets->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, planets_x, 0.0f, -1.0f, 0.0f);
    planets->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
    planets->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/bg3.png", false, sf::Vector2f(1.f, 1.f), 0);
    this->_world.addEntity(planets);
    rtype::ecs::entity::Entity *bigPlanet = new rtype::ecs::entity::Entity(rtype::ecs::entity::STATIC_SPRITE);
    if (bigPlanet == nullptr)
        throw ScreensExceptions("MenuScreen: Error while creating Entity (4)");
    bigPlanet->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, bigPlanet_x, 700.f, -1.2f, 0.0f);
    bigPlanet->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
    bigPlanet->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/bg4.png", false, sf::Vector2f(3.f, 3.f), 0);
    this->_world.addEntity(bigPlanet);

    rtype::ecs::entity::Entity *butt_solo = new rtype::ecs::entity::Entity(rtype::ecs::entity::RECTANGLE);
    if (butt_solo == nullptr)
        throw ScreensExceptions("MenuScreen: Error while creating Entity (5)");
    butt_solo->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 870.f, 390.f, 0.0f, 0.0f);
    butt_solo->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, 70.f, 50.f, sf::Color::Transparent, true, 3.0f, sf::Color::Transparent);
    this->_world.addEntity(butt_solo);
    _buttons.push_back(false);
    rtype::ecs::entity::Entity *solo = new rtype::ecs::entity::Entity(rtype::ecs::entity::TEXT);
    if (solo == nullptr)
        throw ScreensExceptions("MenuScreen: Error while creating Entity (6)");
    solo->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 870.f, 400.f, 0.0f, 0.0f);
    solo->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "Solo", 30.f, sf::Color::Blue, true);
    this->_world.addEntity(solo);

    rtype::ecs::entity::Entity *butt_multi = new rtype::ecs::entity::Entity(rtype::ecs::entity::RECTANGLE);
    if (butt_multi == nullptr)
        throw ScreensExceptions("MenuScreen: Error while creating Entity (7)");
    butt_multi->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 870.f, 460.f, 0.0f, 0.0f);
    butt_multi->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, 170.f, 50.f, sf::Color::Transparent, true, 3.0f, sf::Color::Transparent);
    this->_world.addEntity(butt_multi);
    _buttons.push_back(false);
    rtype::ecs::entity::Entity *multi = new rtype::ecs::entity::Entity(rtype::ecs::entity::TEXT);
    if (multi == nullptr)
        throw ScreensExceptions("MenuScreen: Error while creating Entity (8)");
    multi->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 870.f, 470.f, 0.0f, 0.0f);
    multi->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "Multiplayer", 30.f, sf::Color::Blue, true);
    this->_world.addEntity(multi);

    rtype::ecs::entity::Entity *butt_htp = new rtype::ecs::entity::Entity(rtype::ecs::entity::RECTANGLE);
    if (butt_htp == nullptr)
        throw ScreensExceptions("MenuScreen: Error while creating Entity (9)");
    butt_htp->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 870.f, 530.f, 0.0f, 0.0f);
    butt_htp->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, 190.f, 50.f, sf::Color::Transparent, true, 3.0f, sf::Color::Transparent);
    this->_world.addEntity(butt_htp);
    _buttons.push_back(false);
    rtype::ecs::entity::Entity *htp = new rtype::ecs::entity::Entity(rtype::ecs::entity::TEXT);
    if (htp == nullptr)
        throw ScreensExceptions("MenuScreen: Error while creating Entity (10)");
    htp->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 870.f, 540.f, 0.0f, 0.0f);
    htp->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "How to play", 30.f, sf::Color::Blue, true);
    this->_world.addEntity(htp);

    rtype::ecs::entity::Entity *butt_options = new rtype::ecs::entity::Entity(rtype::ecs::entity::RECTANGLE);
    if (butt_options == nullptr)
        throw ScreensExceptions("MenuScreen: Error while creating Entity (11)");
    butt_options->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 870.f, 600.f, 0.0f, 0.0f);
    butt_options->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, 120.f, 50.f, sf::Color::Transparent, true, 3.0f, sf::Color::Transparent);
    this->_world.addEntity(butt_options);
    _buttons.push_back(false);
    rtype::ecs::entity::Entity *options = new rtype::ecs::entity::Entity(rtype::ecs::entity::TEXT);
    if (options == nullptr)
        throw ScreensExceptions("MenuScreen: Error while creating Entity (12)");
    options->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 870.f, 610.f, 0.0f, 0.0f);
    options->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "Options", 30.f, sf::Color::Blue, true);
    this->_world.addEntity(options);

    rtype::ecs::entity::Entity *butt_quit = new rtype::ecs::entity::Entity(rtype::ecs::entity::RECTANGLE);
    if (butt_quit == nullptr)
        throw ScreensExceptions("MenuScreen: Error while creating Entity (13)");
    butt_quit->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 870.f, 670.f, 0.0f, 0.0f);
    butt_quit->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, 70.f, 50.f, sf::Color::Transparent, true, 3.0f, sf::Color::Transparent);
    this->_world.addEntity(butt_quit);
    _buttons.push_back(false);
    rtype::ecs::entity::Entity *quit = new rtype::ecs::entity::Entity(rtype::ecs::entity::TEXT);
    if (quit == nullptr)
        throw ScreensExceptions("MenuScreen: Error while creating Entity (14)");
    quit->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 870.f, 680.f, 0.0f, 0.0f);
    quit->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "Quit", 30.f, sf::Color::Blue, true);
    this->_world.addEntity(quit);
}

int rtype::menu::MenuScreen::handleEvent(rtype::Event &event, rtype::Game *gameEngine)
{

    if (isButtonPressed(4, gameEngine, event)) {
        saveParalax();
        return 7;
    }
    if (isButtonPressed(6, gameEngine, event)) {
        gameEngine->_client->send(message::JOIN);
        saveParalax();
        return 6;
    }
    if (isButtonPressed(10, gameEngine, event)) {
        saveParalax();
        return 4;
    }
    if (isButtonPressed(12, gameEngine, event)) {
        return 10;
    }
    isMouseOnButton(4, gameEngine, event) ? _buttons.at(0) = true : _buttons.at(0) = false;
    isMouseOnButton(6, gameEngine, event) ? _buttons.at(1) = true : _buttons.at(1) = false;
    isMouseOnButton(8, gameEngine, event) ? _buttons.at(2) = true : _buttons.at(2) = false;
    isMouseOnButton(10, gameEngine, event) ? _buttons.at(3) = true : _buttons.at(3) = false;
    isMouseOnButton(12, gameEngine, event) ? _buttons.at(4) = true : _buttons.at(4) = false;
    return 0;
}

void rtype::menu::MenuScreen::update(rtype::Game *gameEngine)
{
    if (_buttons.at(0) == true) {
        ecs::component::Drawable2D *soloButtonCompo = _world.getEntity(5)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        soloButtonCompo->setColor(sf::Color::Cyan);

    } else if (_buttons.at(0) == false) {
        ecs::component::Drawable2D *soloButtonCompo = _world.getEntity(5)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        soloButtonCompo->setColor(sf::Color::Blue);
    }
    if (_buttons.at(1) == true) {
        ecs::component::Drawable2D *multiButtonCompo = _world.getEntity(7)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        multiButtonCompo->setColor(sf::Color::Cyan);

    } else if (_buttons.at(1) == false) {
        ecs::component::Drawable2D *multiButtonCompo = _world.getEntity(7)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        multiButtonCompo->setColor(sf::Color::Blue);
    }
    if (_buttons.at(2) == true) {
        ecs::component::Drawable2D *htpButtonCompo = _world.getEntity(9)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        htpButtonCompo->setColor(sf::Color::Cyan);

    } else if (_buttons.at(2) == false) {
        ecs::component::Drawable2D *htpButtonCompo = _world.getEntity(9)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        htpButtonCompo->setColor(sf::Color::Blue);
    }
    if (_buttons.at(3) == true) {
        ecs::component::Drawable2D *optionsButtonCompo = _world.getEntity(11)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        optionsButtonCompo->setColor(sf::Color::Cyan);

    } else if (_buttons.at(3) == false) {
        ecs::component::Drawable2D *optionsButtonCompo = _world.getEntity(11)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        optionsButtonCompo->setColor(sf::Color::Blue);
    }
    if (_buttons.at(4) == true) {
        ecs::component::Drawable2D *quitButtonCompo = _world.getEntity(13)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        quitButtonCompo->setColor(sf::Color::Cyan);

    } else if (_buttons.at(4) == false) {
        ecs::component::Drawable2D *quitButtonCompo = _world.getEntity(13)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        quitButtonCompo->setColor(sf::Color::Blue);
    }
    paralax();
    this->_world.update(gameEngine);
    this->_world.draw(gameEngine);
}

bool rtype::menu::MenuScreen::isButtonPressed(size_t index, rtype::Game *gameEngine, rtype::Event &event)
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

bool rtype::menu::MenuScreen::isMouseOnButton(size_t index, rtype::Game *gameEngine, rtype::Event &event)
{
    ecs::component::Drawable2D *rectangleCompo = _world.getEntity(index)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
    ecs::component::Transform *transformCompo = _world.getEntity(index)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
    if (event.global_position.x >= (transformCompo->getX() + gameEngine->_window.getPosition().x) && event.global_position.x <= (transformCompo->getX() + gameEngine->_window.getPosition().x) + rectangleCompo->getWidth() &&
    event.global_position.y >= (transformCompo->getY() + gameEngine->_window.getPosition().y) && event.global_position.y <= (transformCompo->getY() + gameEngine->_window.getPosition().y) + rectangleCompo->getHeight()) {
        return true;
    }
    return false;
}

void rtype::menu::MenuScreen::saveParalax(void)
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

void rtype::menu::MenuScreen::paralax(void)
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