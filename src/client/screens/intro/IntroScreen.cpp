/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** IntroScreen.cpp
*/

#include "IntroScreen.hpp"
#include "../../../ecs/System/Draw2D/draw2d.hpp"
#include "../../../ecs/System/Movement/movement.hpp"
#include "../../../exceptions/ScreensExceptions.hpp"

rtype::menu::IntroScreen::IntroScreen(): _onWritingFrame(false)
{

}

void rtype::menu::IntroScreen::init()
{
    rtype::ecs::system::ISystem *draw2DSystemMenu = new rtype::ecs::system::Draw2DSystem();
    if (draw2DSystemMenu == nullptr)
        throw ScreensExceptions("IntroScreen: Error while creating Draw2DSystem");
    this->_world.addSystem(draw2DSystemMenu);
    rtype::ecs::system::ISystem *movementSystemMenu = new rtype::ecs::system::MovementSystem();
    if (movementSystemMenu == nullptr)
        throw ScreensExceptions("IntroScreen: Error while creating MovementSystem");
    this->_world.addSystem(movementSystemMenu);

    rtype::ecs::entity::Entity *bg = new rtype::ecs::entity::Entity(rtype::ecs::entity::STATIC_SPRITE);
    if (bg == nullptr)
        throw ScreensExceptions("IntroScreen: Error while creating Entity (1)");
    bg->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, bg_x, 0.0f, -0.5f, 0.0f);
    bg->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
    bg->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/bg.png", false, sf::Vector2f(1.f, 1.f), 0);
    this->_world.addEntity(bg);
    rtype::ecs::entity::Entity *stars = new rtype::ecs::entity::Entity(rtype::ecs::entity::STATIC_SPRITE);
    if (stars == nullptr)
        throw ScreensExceptions("IntroScreen: Error while creating Entity (2)");
    stars->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, stars_x, 0.0f, -0.7f, 0.0f);
    stars->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
    stars->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/bg2.png", false, sf::Vector2f(1.f, 1.f), 0);
    this->_world.addEntity(stars);
    rtype::ecs::entity::Entity *planets = new rtype::ecs::entity::Entity(rtype::ecs::entity::STATIC_SPRITE);
    if (planets == nullptr)
        throw ScreensExceptions("IntroScreen: Error while creating Entity (3)");
    planets->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, planets_x, 0.0f, -1.0f, 0.0f);
    planets->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
    planets->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/bg3.png", false, sf::Vector2f(1.f, 1.f), 0);
    this->_world.addEntity(planets);
    rtype::ecs::entity::Entity *bigPlanet = new rtype::ecs::entity::Entity(rtype::ecs::entity::STATIC_SPRITE);
    if (bigPlanet == nullptr)
        throw ScreensExceptions("IntroScreen: Error while creating Entity (4)");
    bigPlanet->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, bigPlanet_x, 700.f, -1.2f, 0.0f);
    bigPlanet->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
    bigPlanet->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/bg4.png", false, sf::Vector2f(3.f, 3.f), 0);
    this->_world.addEntity(bigPlanet);

    rtype::ecs::entity::Entity *back = new rtype::ecs::entity::Entity(rtype::ecs::entity::RECTANGLE);
    if (back == nullptr)
        throw ScreensExceptions("IntroScreen: Error while creating Entity (5)");
    back->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 500.f, 100.f, 0.0f, 0.0f);
    back->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, 900.f, 800.f, sf::Color::Black, true, 3.0f, sf::Color::Magenta);
    this->_world.addEntity(back);
    rtype::ecs::entity::Entity *butt_validate = new rtype::ecs::entity::Entity(rtype::ecs::entity::RECTANGLE);
    if (butt_validate == nullptr)
        throw ScreensExceptions("IntroScreen: Error while creating Entity (6)");
    butt_validate->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 840.f, 800.f, 0.0f, 0.0f);
    butt_validate->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, 200.f, 50.f, sf::Color::Black, true, 3.0f, sf::Color::Magenta);
    this->_world.addEntity(butt_validate);
    _buttons.push_back(false);
    rtype::ecs::entity::Entity *validate = new rtype::ecs::entity::Entity(rtype::ecs::entity::TEXT);
    if (validate == nullptr)
        throw ScreensExceptions("IntroScreen: Error while creating Entity (7)");
    validate->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 880.f, 810.f, 0.0f, 0.0f);
    validate->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "Validate", 30.f, sf::Color::Magenta, true);
    this->_world.addEntity(validate);
    rtype::ecs::entity::Entity *name_frame = new rtype::ecs::entity::Entity(rtype::ecs::entity::RECTANGLE);
    if (name_frame == nullptr)
        throw ScreensExceptions("IntroScreen: Error while creating Entity (8)");
    name_frame->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 600.f, 200.f, 0.0f, 0.0f);
    name_frame->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, 700.f, 60.f, sf::Color::Black, true, 3.0f, sf::Color::Cyan);
    this->_world.addEntity(name_frame);
    rtype::ecs::entity::Entity *pseudo = new rtype::ecs::entity::Entity(rtype::ecs::entity::TEXT);
    if (pseudo == nullptr)
        throw ScreensExceptions("IntroScreen: Error while creating Entity (9)");
    pseudo->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 610.f, 215.f, 0.0f, 0.0f);
    pseudo->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "", 30.f, sf::Color::White, true);
    this->_world.addEntity(pseudo);
    rtype::ecs::entity::Entity *choose = new rtype::ecs::entity::Entity(rtype::ecs::entity::TEXT);
    if (choose == nullptr)
        throw ScreensExceptions("IntroScreen: Error while creating Entity (10)");
    choose->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 770.f, 140.f, 0.0f, 0.0f);
    choose->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "Choose a nickname", 40.f, sf::Color::White, true);
    this->_world.addEntity(choose);
    rtype::ecs::entity::Entity *warning = new rtype::ecs::entity::Entity(rtype::ecs::entity::TEXT);
    if (warning == nullptr)
        throw ScreensExceptions("IntroScreen: Error while creating Entity (11)");
    warning->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 650.f, 280.f, 0.0f, 0.0f);
    warning->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "Your nickname need to have at least 3 letters", 30.f, sf::Color::Red, true);
    this->_world.addEntity(warning);
}

int rtype::menu::IntroScreen::handleEvent(rtype::Event &event, rtype::Game *gameEngine)
{
    handleNickname(event);
    if (isButtonPressed(5, gameEngine, event) && _pseudo.size() > 2) {
        saveParalax();
        return 2;
    }
    hooverOnButton(event, gameEngine);
    return 0;
}

void rtype::menu::IntroScreen::update(rtype::Game *gameEngine)
{   
    if (_buttons.at(0) == true) {
        ecs::component::Drawable2D *writingFrameCompo = _world.getEntity(5)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        writingFrameCompo->setOutlineColor(sf::Color::Cyan);
    } else if (_buttons.at(0) == false) {
        ecs::component::Drawable2D *writingFrameCompo = _world.getEntity(5)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        writingFrameCompo->setOutlineColor(sf::Color::Magenta);
    }
    paralax();
    this->_world.update(gameEngine);
    this->_world.draw(gameEngine);
}

bool rtype::menu::IntroScreen::isButtonPressed(size_t index, rtype::Game *gameEngine, rtype::Event &event)
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

bool rtype::menu::IntroScreen::isMouseOnButton(size_t index, rtype::Game *gameEngine, rtype::Event &event)
{
    ecs::component::Drawable2D *rectangleCompo = _world.getEntity(index)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
    ecs::component::Transform *transformCompo = _world.getEntity(index)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
    if (event.global_position.x >= (transformCompo->getX() + gameEngine->_window.getPosition().x) && event.global_position.x <= (transformCompo->getX() + gameEngine->_window.getPosition().x) + rectangleCompo->getWidth() &&
    event.global_position.y >= (transformCompo->getY() + gameEngine->_window.getPosition().y) && event.global_position.y <= (transformCompo->getY() + gameEngine->_window.getPosition().y) + rectangleCompo->getHeight()) {
        return true;
    }
    return false;
}

bool rtype::menu::IntroScreen::isSurfaceClicked(float x, float y, float width, float height, rtype::Event &event, rtype::Game *gameEngine)
{
    if (event.position.x >= (x + gameEngine->_window.getPosition().x) && event.position.x <= (x + gameEngine->_window.getPosition().x) + width &&
    event.position.y >= (y + gameEngine->_window.getPosition().y) && event.position.y <= (y + gameEngine->_window.getPosition().y) + height) {
        event.position.x = 0;
        event.position.y = 0;
        return true;
    }
    return false;
}

bool rtype::menu::IntroScreen::isMouseOnSurface(float x, float y, float width, float height, rtype::Event &event, rtype::Game *gameEngine)
{
    return (event.global_position.x >= (x + gameEngine->_window.getPosition().x) && event.global_position.x <= (x + gameEngine->_window.getPosition().x) + width &&
    event.global_position.y >= (y + gameEngine->_window.getPosition().y) && event.global_position.y <= (y + gameEngine->_window.getPosition().y) + height);
}

void rtype::menu::IntroScreen::hooverOnButton(rtype::Event &event, rtype::Game *gameEngine)
{
    isMouseOnButton(5, gameEngine, event) ? _buttons.at(0) = true : _buttons.at(0) = false;
}

bool rtype::menu::IntroScreen::isAlpha(rtype::Event &event)
{
    return (event.key.code == 'a' || event.key.code == 'b'|| event.key.code == 'c'|| event.key.code == 'd'|| event.key.code == 'e'|| event.key.code == 'f'|| event.key.code == 'g'
    || event.key.code == 'h'|| event.key.code == 'i'|| event.key.code == 'j'|| event.key.code == 'k'|| event.key.code == 'l'|| event.key.code == 'm'|| event.key.code == 'n'
    || event.key.code == 'o'|| event.key.code == 'p'|| event.key.code == 'q'|| event.key.code == 'r'|| event.key.code == 's'|| event.key.code == 't'|| event.key.code == 'u'
    || event.key.code == 'v'|| event.key.code == 'w'|| event.key.code == 'x'|| event.key.code == 'y'|| event.key.code == 'z');
}

void rtype::menu::IntroScreen::handleNickname(rtype::Event &event)
{
    ecs::component::Drawable2D *pseudoCompo = _world.getEntity(8)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
    std::string tmp = pseudoCompo->getText();
    if (isAlpha(event)) {
        pseudoCompo->setText(tmp + event.key.code);
        event.key.code = '\0';
    }
    else if (event.key.backspace && (tmp.size() != 0)) {
        tmp.pop_back();
        pseudoCompo->setText(tmp);
        event.key.backspace = false;
    }
    _pseudo = pseudoCompo->getText();
}

void rtype::menu::IntroScreen::saveParalax(void)
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

void rtype::menu::IntroScreen::paralax(void)
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