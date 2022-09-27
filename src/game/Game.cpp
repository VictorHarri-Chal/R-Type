/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Game.cpp
*/

#include "Game.hpp"
#include <iostream>

rtype::Game::Game(size_t baseFps)
{
    _fps = baseFps;
    _actualScreen = Screens::Menu;
    _menu = new rtype::menu::MenuScreen;
    
    _window.create(sf::VideoMode{1080, 720, 16}, "R-Type", sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);
}

rtype::Game::~Game()
{
    delete _menu;
}

void rtype::Game::init()
{
    initScenes();
}

void rtype::Game::initMusic()
{

}

void rtype::Game::initSounds()
{

}

void rtype::Game::initScenes()
{
    _menu->init();
}

bool rtype::Game::processEvents()
{
    Events Event;
    while (_window.pollEvent(_sfmlEvent)) {
        if (_sfmlEvent.type == sf::Event::Closed)
            _window.close();
        bool ret = Event.inputUpdate(_event, _sfmlEvent);
        int swap = handleEvent();
        if (swap == 10)
            return false;
        handleScreensSwap(swap);
        return ret;
    }
    return true;
}

void rtype::Game::update()
{
    switch (_actualScreen) {
        case Screens::Menu: _menu->update(); break;
        default: break;
    }
}

void rtype::Game::draw()
{
    switch (_actualScreen) {
        case Screens::Menu: _menu->draw(); break;
        default: break;
    }
}

int rtype::Game::handleEvent()
{
    switch (_actualScreen) {
        case Screens::Menu: return (_menu->handleEvent(_event));
        default: break;
    }
    return true;
}

void rtype::Game::run()
{
    while (_window.isOpen()) {
        
        if (!processEvents())
            break;
        update();
        draw();
    }
}

void rtype::Game::handleScreensSwap(int ret)
{
    if (ret == 2) {
        reinitGame();
        setActualScreen(Screens::Menu);
    }
    if (ret == 5) {
        setActualScreen(Screens::Game);
    }
}
void rtype::Game::setActualScreen(Screens newScreen)
{
    _actualScreen = newScreen;
}

void rtype::Game::reinitGame()
{
}

void rtype::Game::destroy()
{

}

float rtype::Game::getPercentage(float percent, bool isWidth)
{
    sf::Vector2u size = _window.getSize();
    float windowDim = isWidth ? static_cast<float>(size.x)
                              : static_cast<float>(size.y);

    return (windowDim * percent / 100.f);
}