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
    _window.create(sf::VideoMode{1920, 1080, 16}, "R-Type", sf::Style::Close | sf::Style::Fullscreen);
}

rtype::Game::~Game()
{
}

void rtype::Game::init()
{
    _actualScreen = Screens::Intro;
    _intro = new rtype::menu::IntroScreen;
    _lastScene = Screens::Intro;
    _intro->init();
}

void rtype::Game::initMusic()
{

}

void rtype::Game::initSounds()
{

}

bool rtype::Game::processEvents(rtype::Game *gameEngine)
{
    Events Event;
    bool ret = true;
    int swap = 0;

    while (_window.pollEvent(_sfmlEvent)) {
        ret = Event.inputUpdate(_event, _sfmlEvent);
        if (_sfmlEvent.type == sf::Event::Closed || !ret)
            _window.close();
        swap = handleEvent(gameEngine);
        if (swap == 10)
            return false;
        handleScreensSwap(swap);
    }
    return true;
}

void rtype::Game::update(rtype::Game *gameEngine)
{
    switch (_actualScreen) {
        case Screens::Intro: _intro->update(); break;
        case Screens::Menu: _menu->update(); break;
        case Screens::Options: _options->update(); break;
        case Screens::Multiplayer: _multiplayer->update(); break;
        default: break;
    }
}

int rtype::Game::handleEvent(rtype::Game *gameEngine)
{
    switch (_actualScreen) {
        case Screens::Intro: return (_intro->handleEvent(_event, gameEngine));
        case Screens::Menu: return (_menu->handleEvent(_event, gameEngine));
        case Screens::Options: return (_options->handleEvent(_event, gameEngine));
        case Screens::Multiplayer: return (_multiplayer->handleEvent(_event, gameEngine));
        default: break;
    }
    return true;
}

void rtype::Game::run()
{

    while (_window.isOpen()) {
        if(!processEvents(this))
            break;
        _window.clear(sf::Color::Black);
        update(this);
        _window.display();
    }
}

void rtype::Game::handleScreensSwap(int ret)
{
    switch (ret) {
        case 2:
            destroyLastScene();
            _menu = new rtype::menu::MenuScreen;
            _lastScene = Screens::Menu;
            _menu->init();
            setActualScreen(Screens::Menu);
            break;
        case 3:
            destroyLastScene();
            setActualScreen(Screens::Htp);
            break;
        case 4:
            destroyLastScene();
            _options = new rtype::menu::OptionsScreen;
            _lastScene = Screens::Options;
            _options->init();
            setActualScreen(Screens::Options);
            break;
        case 5:
            destroyLastScene();
            _multiplayer = new rtype::menu::MultiplayerScreen;
            _lastScene = Screens::Multiplayer;
            _multiplayer->init();
            setActualScreen(Screens::Multiplayer);
            break;
        case 6:
            destroyLastScene();
            setActualScreen(Screens::Game);
            break;
        default:
            break;
    }
}

void rtype::Game::setActualScreen(Screens newScreen)
{
    _actualScreen = newScreen;
}

void rtype::Game::destroyLastScene()
{
    if (_lastScene == Screens::Intro)
        delete _intro;
    if (_lastScene == Screens::Menu)
        delete _menu;
    if (_lastScene == Screens::Options)
        delete _options;
    if (_lastScene == Screens::Multiplayer)
        delete _multiplayer;
}

void rtype::Game::destroy()
{
    destroyLastScene();
}
