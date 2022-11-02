/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Game.cpp
*/

#include "Game.hpp"
#include "../Globals.hpp"

float bg_x = 0.0f;
float stars_x = 0.0f;
float planets_x = 0.0f;
float bigPlanet_x = 1600.f;

rtype::Game::Game(size_t baseFps)
{
    _fps = baseFps;
    _client = new Client(_ioService, "localhost", "4242");
}

rtype::Game::~Game()
{
}

void rtype::Game::init(std::string flag)
{
    _window.create(sf::VideoMode{1920, 1080, 16}, "R-Type", sf::Style::Close | sf::Style::Fullscreen);
    boost::thread t(boost::bind(&boost::asio::io_service::run, &_ioService));
    _eventClass.initEvents(_event);
    if (flag == "-g") {
        _actualScreen = Screens::Core;
        _core = new rtype::menu::CoreScreen;
        _lastScene = Screens::Core;
        _core->init();
    } else {
        _actualScreen = Screens::Intro;
        _intro = new rtype::menu::IntroScreen;
        _lastScene = Screens::Intro;
        _intro->init();
    }
}

void rtype::Game::initMusic()
{

}

void rtype::Game::initSounds()
{

}

bool rtype::Game::processEvents(rtype::Game *gameEngine)
{
    bool ret = true;
    int swap = 0;

    if (_window.pollEvent(_sfmlEvent)) {
        ret = _eventClass.inputUpdate(_event, _sfmlEvent);
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
        case Screens::Intro: _intro->update(gameEngine); break;
        case Screens::Menu: _menu->update(gameEngine); break;
        case Screens::Options: _options->update(gameEngine); break;
        case Screens::Room: _room->update(gameEngine); break;
        case Screens::Core: _core->update(gameEngine); break;
        default: break;
    }
}

int rtype::Game::handleEvent(rtype::Game *gameEngine)
{
    switch (_actualScreen) {
        case Screens::Intro: return (_intro->handleEvent(_event, gameEngine));
        case Screens::Menu: return (_menu->handleEvent(_event, gameEngine));
        case Screens::Options: return (_options->handleEvent(_event, gameEngine));
        case Screens::Room: return (_room->handleEvent(_event, gameEngine));
        case Screens::Core: return (_core->handleEvent(_event, gameEngine));
        default: break;
    }
    return true;
}

void rtype::Game::run()
{
    while (_window.isOpen()) {
        if (_clock.getElapsedTime() >= sf::seconds(1.0f/120.0f)) {
            if(!processEvents(this))
                break;
            _window.clear(sf::Color::Black);
            update(this);
            _window.display();
            _clock.restart();
        }
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
            _room = new rtype::menu::RoomScreen;
            _lastScene = Screens::Room;
            _room->init();
            setActualScreen(Screens::Room);
            break;
        case 7:
            destroyLastScene();
            _core = new rtype::menu::CoreScreen;
            _lastScene = Screens::Core;
            _core->init();
            setActualScreen(Screens::Core);
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
    if (_lastScene == Screens::Room)
        delete _room;
    if (_lastScene == Screens::Core)
        delete _core;
}

void rtype::Game::destroy()
{
    destroyLastScene();
    delete _client;
}
