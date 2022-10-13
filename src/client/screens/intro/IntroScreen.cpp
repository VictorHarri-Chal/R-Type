/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** IntroScreen.cpp
*/

#include "IntroScreen.hpp"
#include "../../../ecs/System/Draw2D/Draw2D.hpp"

rtype::menu::IntroScreen::IntroScreen(): _onWritingFrame(false)
{

}

void rtype::menu::IntroScreen::init()
{
    rtype::ecs::system::ISystem *draw2DSystemMenu = new rtype::ecs::system::Draw2DSystem();
    this->_world.addSystem(draw2DSystemMenu);
    rtype::ecs::entity::Entity *back = new rtype::ecs::entity::Entity(rtype::ecs::entity::UNKNOWN);
    back->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 500.f, 100.f, 0.0f, 0.0f);
    back->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, 900.f, 800.f, sf::Color::Black, true, 3.0f, sf::Color::Blue);
    this->_world.addEntity(back);
    rtype::ecs::entity::Entity *butt_validate = new rtype::ecs::entity::Entity(rtype::ecs::entity::UNKNOWN);
    butt_validate->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 840.f, 800.f, 0.0f, 0.0f);
    butt_validate->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, 200.f, 50.f, sf::Color::Black, true, 3.0f, sf::Color::Blue);
    this->_world.addEntity(butt_validate);
    _buttons.push_back(false);
    rtype::ecs::entity::Entity *validate = new rtype::ecs::entity::Entity(rtype::ecs::entity::UNKNOWN);
    validate->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 880.f, 810.f, 0.0f, 0.0f);
    validate->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "Validate", 30.f, sf::Color::Blue, true);
    this->_world.addEntity(validate);
    rtype::ecs::entity::Entity *name_frame = new rtype::ecs::entity::Entity(rtype::ecs::entity::UNKNOWN);
    name_frame->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 600.f, 200.f, 0.0f, 0.0f);
    name_frame->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, 700.f, 60.f, sf::Color::Black, true, 3.0f, sf::Color::Red);
    this->_world.addEntity(name_frame);
    _buttons.push_back(false);
    rtype::ecs::entity::Entity *pseudo = new rtype::ecs::entity::Entity(rtype::ecs::entity::UNKNOWN);
    pseudo->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 610.f, 215.f, 0.0f, 0.0f);
    pseudo->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "", 30.f, sf::Color::White, true);
    this->_world.addEntity(pseudo);
    rtype::ecs::entity::Entity *choose = new rtype::ecs::entity::Entity(rtype::ecs::entity::UNKNOWN);
    choose->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 770.f, 140.f, 0.0f, 0.0f);
    choose->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "Choose a nickname", 40.f, sf::Color::White, true);
    this->_world.addEntity(choose);



}

int rtype::menu::IntroScreen::handleEvent(rtype::Event &event, rtype::Game *gameEngine)
{
    if (_onWritingFrame) {
        ecs::component::Drawable2D *pseudoCompo = _world.getEntity(4)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
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
    } else if (!_onWritingFrame && (_pseudo.size() > 2)) {
        if (isButtonPressed(1, gameEngine, event)) {
            return 2;
        }
    }
    hooverOnButton(event, gameEngine);
    return 0;
}

void rtype::menu::IntroScreen::update(rtype::Game *gameEngine)
{   
    if (_buttons.at(0) == true) {
        ecs::component::Drawable2D *writingFrameCompo = _world.getEntity(1)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        writingFrameCompo->setOutlineColor(sf::Color::Yellow);
    } else if (_buttons.at(0) == false) {
        ecs::component::Drawable2D *writingFrameCompo = _world.getEntity(1)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        writingFrameCompo->setOutlineColor(sf::Color::Blue);
    }
    if (_buttons.at(1) == true) {
        ecs::component::Drawable2D *writingFrameCompo = _world.getEntity(3)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        writingFrameCompo->setOutlineColor(sf::Color::Yellow);
    } else if (_buttons.at(1) == false && (_pseudo.size() < 3)) {
        ecs::component::Drawable2D *writingFrameCompo = _world.getEntity(3)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        writingFrameCompo->setOutlineColor(sf::Color::Red);
    } else if (_buttons.at(1) == false && (_pseudo.size() > 2)) {
        ecs::component::Drawable2D *writingFrameCompo = _world.getEntity(3)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        writingFrameCompo->setOutlineColor(sf::Color::Green);
    }
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
    return (event.position.x >= (x + gameEngine->_window.getPosition().x) && event.position.x <= (x + gameEngine->_window.getPosition().x) + width &&
    event.position.y >= (y + gameEngine->_window.getPosition().y) && event.position.y <= (y + gameEngine->_window.getPosition().y) + height);
}

bool rtype::menu::IntroScreen::isMouseOnSurface(float x, float y, float width, float height, rtype::Event &event, rtype::Game *gameEngine)
{
    return (event.global_position.x >= (x + gameEngine->_window.getPosition().x) && event.global_position.x <= (x + gameEngine->_window.getPosition().x) + width &&
    event.global_position.y >= (y + gameEngine->_window.getPosition().y) && event.global_position.y <= (y + gameEngine->_window.getPosition().y) + height);
}

void rtype::menu::IntroScreen::hooverOnButton(rtype::Event &event, rtype::Game *gameEngine)
{
    isMouseOnButton(1, gameEngine, event) ? _buttons.at(0) = true : _buttons.at(0) = false;
    if (isButtonPressed(3, gameEngine, event)) {
        _onWritingFrame = true;
        _buttons.at(1) = true;
    } else if (!isButtonPressed(3, gameEngine, event) && isButtonPressed(0, gameEngine, event)) {
        _onWritingFrame = false;
        _buttons.at(1) = false;
    }
}

bool rtype::menu::IntroScreen::isAlpha(rtype::Event &event)
{
    return (event.key.code == 'a' || event.key.code == 'b'|| event.key.code == 'c'|| event.key.code == 'd'|| event.key.code == 'e'|| event.key.code == 'f'|| event.key.code == 'g'
    || event.key.code == 'h'|| event.key.code == 'i'|| event.key.code == 'j'|| event.key.code == 'k'|| event.key.code == 'l'|| event.key.code == 'm'|| event.key.code == 'n'
    || event.key.code == 'o'|| event.key.code == 'p'|| event.key.code == 'q'|| event.key.code == 'r'|| event.key.code == 's'|| event.key.code == 't'|| event.key.code == 'u'
    || event.key.code == 'v'|| event.key.code == 'w'|| event.key.code == 'x'|| event.key.code == 'y'|| event.key.code == 'z');
}