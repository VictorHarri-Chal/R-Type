/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** OptionsScreen.cpp
*/

#include "OptionsScreen.hpp"
#include "../../../ecs/System/Draw2D/draw2d.hpp"
#include "../../../ecs/System/Movement/movement.hpp"
#include "../../../exceptions/ScreensExceptions.hpp"

rtype::menu::OptionsScreen::OptionsScreen()
{
}

void rtype::menu::OptionsScreen::init()
{
    rtype::ecs::system::ISystem *draw2DSystemMenu = new rtype::ecs::system::Draw2DSystem();
    if (draw2DSystemMenu == nullptr)
        throw ScreensExceptions("OptionsScreen: Error while creating Draw2DSystem");
    this->_world.addSystem(draw2DSystemMenu);
    rtype::ecs::system::ISystem *movementSystemMenu = new rtype::ecs::system::MovementSystem();
    if (movementSystemMenu == nullptr)
        throw ScreensExceptions("OptionsScreen: Error while creating MovementSystem");
    this->_world.addSystem(movementSystemMenu);

    rtype::ecs::entity::Entity *bg = new rtype::ecs::entity::Entity(rtype::ecs::entity::STATIC_SPRITE);
    if (bg == nullptr)
        throw ScreensExceptions("OptionsScreen: Error while creating Entity (1)");
    bg->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, bg_x, 0.0f, -0.5f, 0.0f);
    bg->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/bg.png", false, sf::Vector2f(1.f, 1.f), 0);
    this->_world.addEntity(bg);
    rtype::ecs::entity::Entity *stars = new rtype::ecs::entity::Entity(rtype::ecs::entity::STATIC_SPRITE);
    if (stars == nullptr)
        throw ScreensExceptions("OptionsScreen: Error while creating Entity (2)");
    stars->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, stars_x, 0.0f, -0.7f, 0.0f);
    stars->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/bg2.png", false, sf::Vector2f(1.f, 1.f), 0);
    this->_world.addEntity(stars);
    rtype::ecs::entity::Entity *planets = new rtype::ecs::entity::Entity(rtype::ecs::entity::STATIC_SPRITE);
    if (planets == nullptr)
        throw ScreensExceptions("OptionsScreen: Error while creating Entity (3)");
    planets->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, planets_x, 0.0f, -1.0f, 0.0f);
    planets->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/bg3.png", false, sf::Vector2f(1.f, 1.f), 0);
    this->_world.addEntity(planets);
    rtype::ecs::entity::Entity *bigPlanet = new rtype::ecs::entity::Entity(rtype::ecs::entity::STATIC_SPRITE);
    if (bigPlanet == nullptr)
        throw ScreensExceptions("OptionsScreen: Error while creating Entity (4)");
    bigPlanet->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, bigPlanet_x, 700.f, -1.2f, 0.0f);
    bigPlanet->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/bg4.png", false, sf::Vector2f(3.f, 3.f), 0);
    this->_world.addEntity(bigPlanet);

}

int rtype::menu::OptionsScreen::handleEvent(rtype::Event &event, rtype::Game *gameEngine)
{
    if (isButtonPressed(4, gameEngine, event)) {
        saveParalax();
        return 2;
    }
    return 0;
}

void rtype::menu::OptionsScreen::update(rtype::Game *gameEngine)
{
    paralax();
    this->_world.update(gameEngine);
    this->_world.draw(gameEngine);
}

bool rtype::menu::OptionsScreen::isButtonPressed(size_t index, rtype::Game *gameEngine, rtype::Event &event)
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

bool rtype::menu::OptionsScreen::isMouseOnButton(size_t index, rtype::Game *gameEngine, rtype::Event &event)
{
    ecs::component::Drawable2D *rectangleCompo = _world.getEntity(index)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
    ecs::component::Transform *transformCompo = _world.getEntity(index)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
    if (event.global_position.x >= (transformCompo->getX() + gameEngine->_window.getPosition().x) && event.global_position.x <= (transformCompo->getX() + gameEngine->_window.getPosition().x) + rectangleCompo->getWidth() &&
    event.global_position.y >= (transformCompo->getY() + gameEngine->_window.getPosition().y) && event.global_position.y <= (transformCompo->getY() + gameEngine->_window.getPosition().y) + rectangleCompo->getHeight()) {
        return true;
    }
    return false;
}

void rtype::menu::OptionsScreen::saveParalax(void)
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

void rtype::menu::OptionsScreen::paralax(void)
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