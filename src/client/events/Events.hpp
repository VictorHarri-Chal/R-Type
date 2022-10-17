/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Events.hpp
*/

#pragma once

#include "../../../include/EventCode.hpp"
#include "../../sfml/Sfml.hpp"

namespace rtype
{
    /**
     * @brief Events base class
     *
     */
    class Events {
      public:
        /**
         * @brief Get input events and update game
         *
         * @param event Event to be handled
         *
         * @return true escape not pressed
         * @return false escape is pressed
         */
        bool inputUpdate(rtype::Event &event, sf::Event _sfmlEvent);
        /**
         * @brief Get a char input
         *
         * @param event event class to modify
         */
        void getCharKeys(rtype::Event &event, sf::Event _sfmlEvent);

        /**
         * @brief Get a system input
         *
         * @param event event class to modify
         */
        void getSystemKeys(rtype::Event &event, sf::Event _sfmlEvent);

        /**
         * @brief Get a controller event
         *
         * @param event event class to modify
         * @param controllerId id of the controller
         */
        void getControllerEvents(rtype::Event &event, int controllerId, sf::Event _sfmlEvent);

        void getMouseButtons(rtype::Event &event, sf::Event sfmlEvent);
    };
} // namespace rtype
