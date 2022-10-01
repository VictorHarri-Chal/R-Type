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
    _window.create(sf::VideoMode{1720, 1080, 16}, "R-Type", sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);
}

rtype::Game::~Game()
{
}

void rtype::Game::init()
{
    _actualScreen = Screens::Menu;
    _menu = new rtype::menu::MenuScreen;
    _lastScene = Screens::Menu;
    _menu->init();
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

void rtype::Game::update()
{
    switch (_actualScreen) {
        case Screens::Menu: _menu->update(); break;
        case Screens::Options: _options->update(); break;
        case Screens::Multiplayer: _multiplayer->update(); break;
        default: break;
    }
}

void rtype::Game::draw(rtype::Game *gameEngine)
{
    switch (_actualScreen) {
        case Screens::Menu: _menu->draw(gameEngine); break;
        case Screens::Options: _options->draw(gameEngine); break;
        case Screens::Multiplayer: _multiplayer->draw(gameEngine); break;
        default: break;
    }
}

int rtype::Game::handleEvent(rtype::Game *gameEngine)
{
    switch (_actualScreen) {
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
        update();
        draw(this);
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
