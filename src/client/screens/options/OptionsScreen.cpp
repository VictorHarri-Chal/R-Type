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
    rtype::ecs::entity::Entity *back = new rtype::ecs::entity::Entity(rtype::ecs::entity::RECTANGLE);
    if (back == nullptr)
        throw ScreensExceptions("IntroScreen: Error while creating Entity (5)");
    back->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 500.f, 100.f, 0.0f, 0.0f);
    sf::Color bgColor(0, 0, 0, 150);
    back->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, 900.f, 700.f, bgColor, true, 3.0f, sf::Color::Magenta);
    this->_world.addEntity(back);
    rtype::ecs::entity::Entity *easyButton = new rtype::ecs::entity::Entity(rtype::ecs::entity::RECTANGLE);
    if (easyButton == nullptr)
        throw ScreensExceptions("IntroScreen: Error while creating Entity (6)");
    easyButton->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 600.f, 200.f, 0.0f, 0.0f);
    sf::Color bgColor2(0, 0, 0, 150);
    easyButton->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, 300.f, 100.f, bgColor2, true, 3.0f, sf::Color::Magenta);
    this->_world.addEntity(easyButton);
    _buttons.push_back(false);
    rtype::ecs::entity::Entity *hardButton = new rtype::ecs::entity::Entity(rtype::ecs::entity::RECTANGLE);
    if (hardButton == nullptr)
        throw ScreensExceptions("IntroScreen: Error while creating Entity (7)");
    hardButton->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 1000.f, 200.f, 0.0f, 0.0f);
    sf::Color bgColor3(0, 0, 0, 150);
    hardButton->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, 300.f, 100.f, bgColor3, true, 3.0f, sf::Color::Magenta);
    this->_world.addEntity(hardButton);
    _buttons.push_back(false);
    rtype::ecs::entity::Entity *easyText = new rtype::ecs::entity::Entity(rtype::ecs::entity::TEXT);
    if (easyText == nullptr)
        throw ScreensExceptions("MenuScreen: Error while creating Entity (8)");
    easyText->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 700.f, 220.f, 0.0f, 0.0f);
    easyText->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "Easy", 50.f, sf::Color::Cyan, true);
    this->_world.addEntity(easyText);
    rtype::ecs::entity::Entity *hardText = new rtype::ecs::entity::Entity(rtype::ecs::entity::TEXT);
    if (hardText == nullptr)
        throw ScreensExceptions("MenuScreen: Error while creating Entity (9)");
    hardText->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 1100.f, 220.f, 0.0f, 0.0f);
    hardText->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "Hard", 50.f, sf::Color::Cyan, true);
    this->_world.addEntity(hardText);
    rtype::ecs::entity::Entity *changeNickButton = new rtype::ecs::entity::Entity(rtype::ecs::entity::RECTANGLE);
    if (changeNickButton == nullptr)
        throw ScreensExceptions("MenuScreen: Error while creating Entity (10)");
    changeNickButton->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 800.f, 400.f, 0.0f, 0.0f);
    sf::Color bgColor4(0, 0, 0, 150);
    changeNickButton->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, 300.f, 100.f, bgColor4, true, 3.0f, sf::Color::Magenta);
    this->_world.addEntity(changeNickButton);
    _buttons.push_back(false);
    rtype::ecs::entity::Entity *changeNickText = new rtype::ecs::entity::Entity(rtype::ecs::entity::TEXT);
    if (changeNickText == nullptr)
        throw ScreensExceptions("MenuScreen: Error while creating Entity (11)");
    changeNickText->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 830.f, 430.f, 0.0f, 0.0f);
    changeNickText->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "Change nickname", 30.f, sf::Color::Cyan, true);
    this->_world.addEntity(changeNickText);
    rtype::ecs::entity::Entity *backToMenuButton = new rtype::ecs::entity::Entity(rtype::ecs::entity::RECTANGLE);
    if (backToMenuButton == nullptr)
        throw ScreensExceptions("MenuScreen: Error while creating Entity (12)");
    backToMenuButton->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 800.f, 600.f, 0.0f, 0.0f);
    sf::Color bgColor5(0, 0, 0, 150);
    backToMenuButton->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, 300.f, 100.f, bgColor5, true, 3.0f, sf::Color::Magenta);
    this->_world.addEntity(backToMenuButton);
    _buttons.push_back(false);
    rtype::ecs::entity::Entity *backToMenuText = new rtype::ecs::entity::Entity(rtype::ecs::entity::TEXT);
    if (backToMenuText == nullptr)
        throw ScreensExceptions("MenuScreen: Error while creating Entity (13)");
    backToMenuText->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 850.f, 630.f, 0.0f, 0.0f);
    backToMenuText->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "Back to menu", 30.f, sf::Color::Cyan, true);
    this->_world.addEntity(backToMenuText);
}

int rtype::menu::OptionsScreen::handleEvent(rtype::Event &event, rtype::Game *gameEngine)
{
    if (isButtonPressed(5, gameEngine, event)) {
        gameEngine->_difficulty = false;
    }
    if (isButtonPressed(6, gameEngine, event)) {
        gameEngine->_difficulty = true;
    }
    if (isButtonPressed(9, gameEngine, event)) {
        saveParalax();
        return 1;
    }
    if (isButtonPressed(11, gameEngine, event)) {
        saveParalax();
        return 2;
    }
    isMouseOnButton(5, gameEngine, event) ? _buttons.at(0) = true : _buttons.at(0) = false;
    isMouseOnButton(6, gameEngine, event) ? _buttons.at(1) = true : _buttons.at(1) = false;
    isMouseOnButton(9, gameEngine, event) ? _buttons.at(2) = true : _buttons.at(2) = false;
    isMouseOnButton(11, gameEngine, event) ? _buttons.at(3) = true : _buttons.at(3) = false;
    return 0;
}

void rtype::menu::OptionsScreen::update(rtype::Game *gameEngine)
{
    if (_buttons.at(0) == true) {
        ecs::component::Drawable2D *easyButtonCompo = _world.getEntity(5)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        easyButtonCompo->setColor(sf::Color::Cyan);
        ecs::component::Drawable2D *easyCompo = _world.getEntity(7)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        easyCompo->setColor(sf::Color(0, 0, 0, 255));

    } else if (_buttons.at(0) == false) {
        ecs::component::Drawable2D *easyButtonCompo = _world.getEntity(5)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        easyButtonCompo->setColor(sf::Color(0, 0, 0, 150));
        ecs::component::Drawable2D *easyCompo = _world.getEntity(7)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        easyCompo->setColor(sf::Color::Cyan);
    }
    if (_buttons.at(1) == true) {
        ecs::component::Drawable2D *hardButtonCompo = _world.getEntity(6)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        hardButtonCompo->setColor(sf::Color::Cyan);
        ecs::component::Drawable2D *hardCompo = _world.getEntity(8)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        hardCompo->setColor(sf::Color(0, 0, 0, 255));

    } else if (_buttons.at(1) == false) {
        ecs::component::Drawable2D *hardButtonCompo = _world.getEntity(6)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        hardButtonCompo->setColor(sf::Color(0, 0, 0, 150));
        ecs::component::Drawable2D *hardCompo = _world.getEntity(8)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        hardCompo->setColor(sf::Color::Cyan);
    }
    if (_buttons.at(2) == true) {
        ecs::component::Drawable2D *changeNicknameButtonCompo = _world.getEntity(9)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        changeNicknameButtonCompo->setColor(sf::Color::Cyan);
        ecs::component::Drawable2D *changeNicknameCompo = _world.getEntity(10)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        changeNicknameCompo->setColor(sf::Color(0, 0, 0, 255));

    } else if (_buttons.at(2) == false) {
        ecs::component::Drawable2D *changeNicknameButtonCompo = _world.getEntity(9)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        changeNicknameButtonCompo->setColor(sf::Color(0, 0, 0, 150));
        ecs::component::Drawable2D *changeNicknameCompo = _world.getEntity(10)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        changeNicknameCompo->setColor(sf::Color::Cyan);
    }
    if (_buttons.at(3) == true) {
        ecs::component::Drawable2D *backToMenuButtonCompo = _world.getEntity(11)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        backToMenuButtonCompo->setColor(sf::Color::Cyan);
        ecs::component::Drawable2D *backToMenuCompo = _world.getEntity(12)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        backToMenuCompo->setColor(sf::Color(0, 0, 0, 255));

    } else if (_buttons.at(3) == false) {
        ecs::component::Drawable2D *backToMenuButtonCompo = _world.getEntity(11)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        backToMenuButtonCompo->setColor(sf::Color(0, 0, 0, 150));
        ecs::component::Drawable2D *backToMenuCompo = _world.getEntity(12)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        backToMenuCompo->setColor(sf::Color::Cyan);
    }
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