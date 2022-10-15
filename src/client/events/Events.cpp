/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Events.cpp
*/

#include "Events.hpp"
#include <iostream>

namespace rtype
{
    void Events::getCharKeys(rtype::Event &event, sf::Event sfmlEvent)
    {
        if (sfmlEvent.type == sf::Event::KeyPressed) {
            if (sfmlEvent.key.code == sf::Keyboard::A)
                event.key.code = 'a';
            else if (sfmlEvent.key.code == sf::Keyboard::B)
                event.key.code = 'b';
            else if (sfmlEvent.key.code == sf::Keyboard::C)
                event.key.code = 'c';
            else if (sfmlEvent.key.code == sf::Keyboard::D)
                event.key.code = 'd';
            else if (sfmlEvent.key.code == sf::Keyboard::E)
                event.key.code = 'e';
            else if (sfmlEvent.key.code == sf::Keyboard::F)
                event.key.code = 'f';
            else if (sfmlEvent.key.code == sf::Keyboard::G)
                event.key.code = 'g';
            else if (sfmlEvent.key.code == sf::Keyboard::H)
                event.key.code = 'h';
            else if (sfmlEvent.key.code == sf::Keyboard::I)
                event.key.code = 'i';
            else if (sfmlEvent.key.code == sf::Keyboard::J)
                event.key.code = 'j';
            else if (sfmlEvent.key.code == sf::Keyboard::K)
                event.key.code = 'k';
            else if (sfmlEvent.key.code == sf::Keyboard::L)
                event.key.code = 'l';
            else if (sfmlEvent.key.code == sf::Keyboard::M)
                event.key.code = 'm';
            else if (sfmlEvent.key.code == sf::Keyboard::N)
                event.key.code = 'n';
            else if (sfmlEvent.key.code == sf::Keyboard::O)
                event.key.code = 'o';
            else if (sfmlEvent.key.code == sf::Keyboard::P)
                event.key.code = 'p';
            else if (sfmlEvent.key.code == sf::Keyboard::Q)
                event.key.code = 'q';
            else if (sfmlEvent.key.code == sf::Keyboard::R)
                event.key.code = 'r';
            else if (sfmlEvent.key.code == sf::Keyboard::S)
                event.key.code = 's';
            else if (sfmlEvent.key.code == sf::Keyboard::T)
                event.key.code = 't';
            else if (sfmlEvent.key.code == sf::Keyboard::U)
                event.key.code = 'u';
            else if (sfmlEvent.key.code == sf::Keyboard::V)
                event.key.code = 'v';
            else if (sfmlEvent.key.code == sf::Keyboard::W)
                event.key.code = 'w';
            else if (sfmlEvent.key.code == sf::Keyboard::X)
                event.key.code = 'x';
            else if (sfmlEvent.key.code == sf::Keyboard::Y)
                event.key.code = 'y';
            else if (sfmlEvent.key.code == sf::Keyboard::Z)
                event.key.code = 'z';
            else if (sfmlEvent.key.code == sf::Keyboard::Space)
                event.key.code = ' ';
            else if (sfmlEvent.key.code == sf::Keyboard::Backslash)
                event.key.code = '\'';
            else if (sfmlEvent.key.code == sf::Keyboard::Tab)
                event.key.code = '\t';
            else
                event.key.code = '\0';
        }
    }

    void Events::getSystemKeys(rtype::Event &event, sf::Event sfmlEvent)
    {
        if (sfmlEvent.type == sf::Event::KeyPressed) {
            if (sfmlEvent.key.code == sf::Keyboard::Return)
                event.key.enter = true;
            else if (sfmlEvent.key.code == sf::Keyboard::Backspace)
                event.key.backspace = true;
            else if (sfmlEvent.key.code == sf::Keyboard::Left)
                event.key.left = true;
            else if (sfmlEvent.key.code == sf::Keyboard::Right)
                event.key.right = true;
            else if (sfmlEvent.key.code == sf::Keyboard::Up)
                event.key.up = true;
            else if (sfmlEvent.key.code == sf::Keyboard::Down)
                event.key.down = true;
            else if (sfmlEvent.key.code == sf::Keyboard::LControl)
                event.key.l_control = true;
            else if (sfmlEvent.key.code == sf::Keyboard::RControl)
                event.key.r_control = true;
            else if (sfmlEvent.key.code == sf::Keyboard::LShift)
                event.key.l_shift = true;
            else if (sfmlEvent.key.code == sf::Keyboard::RShift)
                event.key.r_shift = true;
            else if (sfmlEvent.key.code == sf::Keyboard::LAlt)
                event.key.l_alt = true;
            else if (sfmlEvent.key.code == sf::Keyboard::RAlt)
                event.key.r_alt = true;
        }
        if (sfmlEvent.type == sf::Event::KeyReleased) {
            if (sfmlEvent.key.code == sf::Keyboard::Return)
                event.key.enter = false;
            else if (sfmlEvent.key.code == sf::Keyboard::Backspace)
                event.key.backspace = false;
            else if (sfmlEvent.key.code == sf::Keyboard::Left)
                event.key.left = false;
            else if (sfmlEvent.key.code == sf::Keyboard::Right)
                event.key.right = false;
            else if (sfmlEvent.key.code == sf::Keyboard::Up)
                event.key.up = false;
            else if (sfmlEvent.key.code == sf::Keyboard::Down)
                event.key.down = false;
            else if (sfmlEvent.key.code == sf::Keyboard::LControl)
                event.key.l_control = false;
            else if (sfmlEvent.key.code == sf::Keyboard::RControl)
                event.key.r_control = false;
            else if (sfmlEvent.key.code == sf::Keyboard::LShift)
                event.key.l_shift = false;
            else if (sfmlEvent.key.code == sf::Keyboard::RShift)
                event.key.r_shift = false;
            else if (sfmlEvent.key.code == sf::Keyboard::LAlt)
                event.key.l_alt = false;
            else if (sfmlEvent.key.code == sf::Keyboard::RAlt)
                event.key.r_alt = false;
        }
    }

    // void Events::getControllerEvents(rtype::Event &event, int controllerId, sf::Event sfmlEvent)
    // {
    //     if (sf::Joystick::isConnected(controllerId)) {
    //         if (sf::Joystick::isButtonPressed(controllerId, rtype::Event::ControllerCode::X_BUTTON))
    //             event.controller[controllerId].code = rtype::Event::ControllerCode::X_BUTTON;
    //         else if (sf::Joystick::isButtonPressed(controllerId, rtype::Event::ControllerCode::O_BUTTON))
    //             event.controller[controllerId].code = rtype::Event::ControllerCode::O_BUTTON;
    //         else if (sf::Joystick::isButtonPressed(controllerId, rtype::Event::ControllerCode::T_BUTTON))
    //             event.controller[controllerId].code = rtype::Event::ControllerCode::T_BUTTON;
    //         else if (sf::Joystick::isButtonPressed(
    //                      controllerId, rtype::Event::ControllerCode::OPTION_BUTTON))
    //             event.controller[controllerId].code = rtype::Event::ControllerCode::OPTION_BUTTON;
    //         else if (sf::Joystick::isButtonPressed(
    //                      controllerId, rtype::Event::ControllerCode::UP_BUTTON))
    //             event.controller[controllerId].code = rtype::Event::ControllerCode::UP_BUTTON;
    //         else if (sf::Joystick::isButtonPressed(
    //                      controllerId, rtype::Event::ControllerCode::DOWN_BUTTON))
    //             event.controller[controllerId].code = rtype::Event::ControllerCode::DOWN_BUTTON;
    //         else if (sf::Joystick::isButtonPressed(
    //                      controllerId, rtype::Event::ControllerCode::LEFT_BUTTON))
    //             event.controller[controllerId].code = rtype::Event::ControllerCode::LEFT_BUTTON;
    //         else if (sf::Joystick::isButtonPressed(
    //                      controllerId, rtype::Event::ControllerCode::RIGHT_BUTTON))
    //             event.controller[controllerId].code = rtype::Event::ControllerCode::RIGHT_BUTTON;
    //         else
    //             event.controller[controllerId].code = rtype::Event::ControllerCode::CONTROLLER_NONE;

    //         float xAxisLeft = sf::Joystick::getAxisPosition(controllerId, sf::Joystick::X);
    //         float yAxisLeft = sf::Joystick::getAxisPosition(controllerId, sf::Joystick::Y);
    //         float xAxisRight = sf::Joystick::getAxisPosition(controllerId, sf::Joystick::U);
    //         float yAxisRight = sf::Joystick::getAxisPosition(controllerId, sf::Joystick::R);

    //         if (xAxisLeft >= -1 && xAxisLeft <= -0.75)
    //             event.controller[controllerId].leftJoystick = rtype::Event::JoystickDirection::LEFT;
    //         else if (xAxisLeft >= 0.75 && xAxisLeft <= 1)
    //             event.controller[controllerId].leftJoystick = rtype::Event::JoystickDirection::RIGHT;
    //         else if (yAxisLeft >= -1 && yAxisLeft <= -0.75)
    //             event.controller[controllerId].leftJoystick = rtype::Event::JoystickDirection::UP;
    //         else if (yAxisLeft >= 0.75 && yAxisLeft <= 1)
    //             event.controller[controllerId].leftJoystick = rtype::Event::JoystickDirection::DOWN;
    //         else
    //             event.controller[controllerId].leftJoystick = rtype::Event::JoystickDirection::JOYSTICK_NONE;
    //         if (xAxisRight >= -1 && xAxisRight <= -0.75)
    //             event.controller[controllerId].rightJoystick = rtype::Event::JoystickDirection::LEFT;
    //         else if (xAxisRight >= 0.75 && xAxisRight <= 1)
    //             event.controller[controllerId].rightJoystick = rtype::Event::JoystickDirection::RIGHT;
    //         else if (yAxisRight >= -1 && yAxisRight <= -0.75)
    //             event.controller[controllerId].rightJoystick = rtype::Event::JoystickDirection::UP;
    //         else if (yAxisRight >= 0.75 && yAxisRight <= 1)
    //             event.controller[controllerId].rightJoystick = rtype::Event::JoystickDirection::DOWN;
    //         else
    //             event.controller[controllerId].rightJoystick = rtype::Event::JoystickDirection::JOYSTICK_NONE;
    //         event.controller[controllerId].connected = true;
    //     } else
    //         event.controller[controllerId].connected = false;
    // }

    void Events::getMouseButtons(rtype::Event &event, sf::Event sfmlEvent)
    {
        (void) sfmlEvent;
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2i pos = sf::Mouse::getPosition();
            event.position = sf::Vector2f(pos);
        }
        sf::Vector2i global_pos = sf::Mouse::getPosition();
        event.global_position = sf::Vector2f(global_pos);
    }

    bool Events::inputUpdate(rtype::Event &event, sf::Event sfmlEvent)
    {
        // event.resized = rtype::raylib::Window::isWindowResized();
        this->getCharKeys(event, sfmlEvent);
        this->getSystemKeys(event, sfmlEvent);
        this->getMouseButtons(event, sfmlEvent);
        // this->getControllerEvents(event, 0);
        // this->getControllerEvents(event, 1);
        // this->getControllerEvents(event, 2);
        // this->getControllerEvents(event, 3);
        if (sfmlEvent.key.code == sf::Keyboard::Escape)
            return false;
        return true;
    }
} // namespace rtype
