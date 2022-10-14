/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** events.hpp
*/

/// @file
///
/// The Event data structure.

#ifndef RTYPE_EVENT_HPP_
#define RTYPE_EVENT_HPP_

#include "../src/sfml/Sfml.hpp"

namespace rtype
{
    /// Contains an event's data.
    ///
    /// Event data is fetched by first checking its type and then accessing the correspoding member.
    struct Event {
        /// Key code for keyboard events.
        ///
        /// Keys are represented by their corresponding character, meaning that some keys are not currently
        /// representable using this format (such as the Enter key).
        using Key = char;

        /// Size events parameters (Event::Type::Resized).
        // struct SizeEvent {
        //     /// Old size, in units.
        //     vec2u oldSize;
        //     /// New size, in units.
        //     vec2i newSize;
        // };

        /// @brief Keyboard event parameters (Event::Type::KeyPressed, Event::Type::KeyReleased).
        struct KeyEvent {
            /// Is the Left Alt key pressed?
            bool l_alt;
            /// Is the Right Alt key pressed?
            bool r_alt;
            /// Is the Left Control key pressed?
            bool l_control;
            /// Is the Right Control key pressed?
            bool r_control;
            /// Is the Left Shift key pressed?
            bool l_shift;
            /// Is the Right Shift key pressed?
            bool r_shift;
            /// Is the up key pressed?
            bool up;
            /// Is the down key pressed?
            bool down;
            /// Is the left key pressed?
            bool left;
            /// Is the right key pressed?
            bool right;
            /// Is the enter key pressed?
            bool enter;
            /// Is the backspace key pressed?
            bool backspace;
            /// Is the space key pressed?
            bool space;
            /// Code of the key that has been pressed.
            Key code;
        };

        /// Controller button input
        enum ControllerCode {
            /// Nothing is happening
            CONTROLLER_NONE,
            /// Up arrow
            UP_BUTTON,
            /// Right arrow
            RIGHT_BUTTON,
            /// Down arrow
            DOWN_BUTTON,
            /// Left arrow
            LEFT_BUTTON,
            /// Triangle key
            T_BUTTON,
            /// Circle button
            O_BUTTON,
            /// Cross button
            X_BUTTON,
            /// Square button
            S_BUTTON,
            /// L1
            L1_BUTTON,
            /// L2
            L2_BUTTON,
            /// R1
            R1_BUTTON,
            /// R2
            R2_BUTTON,
            /// Share button
            SHARE_BUTTON,
            /// Touchpad button
            TOUCHPAD_BUTTON,
            /// Option button
            OPTION_BUTTON,
            /// L3
            L3_BUTTON,
            /// R3
            R3_BUTTON
        };

        /// Right joystick events
        enum JoystickDirection {
            /// Nothing is happening
            JOYSTICK_NONE,
            /// Joystick going up
            UP,
            /// Joystick going right
            RIGHT,
            /// Joystick going down
            DOWN,
            /// Joystick going left
            LEFT
        };

        /// Event happening on the controller
        struct ControllerEvent {
            /// Controller button input
            int code;
            /// Left joystick events
            JoystickDirection leftJoystick;
            /// Right joystick events
            JoystickDirection rightJoystick;
            /// Is controller connected?
            bool connected;
        };
        /// Mouse position on click
        sf::Vector2f position;
        /// Mouse position global
        sf::Vector2f global_position;

        // Member data
        union {
            /// Is the window resized?
            bool resized;
            /// Key event parameters (Event::KeyPressed, Event::KeyReleased).
            KeyEvent key;
            /// Controller events
            ControllerEvent controller[4];
        };
    };
}

#endif //RTYPE_EVENT_HPP_
