/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** MenuScreen.cpp
*/

#include "MenuScreen.hpp"

rtype::menu::MenuScreen::MenuScreen() : _cursorPosition(NEW_GAME)
{
}

void rtype::menu::MenuScreen::init()
{
    // this->_positionsCursor[NEW_GAME] = tools::Tools::getPercentage(27.f, false);
    // this->_positionsCursor[LOAD_GAME] = tools::Tools::getPercentage(47.f, false);
    // this->_positionsCursor[EXIT] = tools::Tools::getPercentage(67.f, false);
}

void rtype::menu::MenuScreen::draw()
{
    for (auto &system : this->_systems) {
        // system->update(this->_entities);
    }
}

int rtype::menu::MenuScreen::handleEvent(rtype::Event &event)
{
    
    return 0;
}

void rtype::menu::MenuScreen::update()
{
    
}

void rtype::menu::MenuScreen::addEntity(std::unique_ptr<rtype::ecs::entity::Entity> entity)
{
    this->_entities.push_back(std::move(entity));
}

int rtype::menu::MenuScreen::checkCursorPosition(bool direction)
{
    // if (direction) {
    //     if (_cursorPosition == NEW_GAME) {
    //         _cursorPosition = LOAD_GAME;
    //         return this->_positionsCursor[_cursorPosition];
    //     }
    //     if (_cursorPosition == LOAD_GAME) {
    //         _cursorPosition = EXIT;
    //         return this->_positionsCursor[_cursorPosition];
    //     }
    //     if (_cursorPosition == EXIT)
    //         return this->_positionsCursor[_cursorPosition];
    // } else if (!direction) {
    //     if (_cursorPosition == NEW_GAME)
    //         return this->_positionsCursor[_cursorPosition];
    //     if (_cursorPosition == LOAD_GAME) {
    //         _cursorPosition = NEW_GAME;
    //         return this->_positionsCursor[_cursorPosition];
    //     }
    //     if (_cursorPosition == EXIT) {
    //         _cursorPosition = LOAD_GAME;
    //         return this->_positionsCursor[_cursorPosition];
    //     }
    // }
    return 0;
}

void rtype::menu::MenuScreen::addSystem(std::unique_ptr<rtype::ecs::system::ISystem> system)
{
    this->_systems.push_back(std::move(system));
}