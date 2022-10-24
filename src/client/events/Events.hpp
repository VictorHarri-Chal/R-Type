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
         * @param event Event class to modify
         * @param sfmlEvent Sfml event
         *
         * @return true If event is handled
         * @return false If event is not handled
         */
        bool inputUpdate(rtype::Event &event, sf::Event sfmlEvent);
        /**
         * @brief Get a char input
         * @param event event class to modify
         * @param sfmlEvent Sfml event
         */
        void getCharKeys(rtype::Event &event, sf::Event sfmlEvent);

        /**
         * @brief Get a system input
         *
         * @param event event class to modify
         * @param sfmlEvent Sfml event
         */
        void getSystemKeys(rtype::Event &event, sf::Event sfmlEvent);

        // /**
        //  * @brief Get a controller event
        //  *
        //  * @param event event class to modify
        //  * @param controllerId id of the controller
        //  * @param sfmlEvent Sfml event
        //  */
        // void getControllerEvents(rtype::Event &event, int controllerId, sf::Event sfmlEvent);
        /**
         * @brief Get the Mouse Buttons
         *
         * @param event Event class to modify
         * @param sfmlEvent Sfml event
         */
        void getMouseButtons(rtype::Event &event, sf::Event sfmlEvent);
        /**
         * @brief Init the event variables values
         *
         * @param event Event class to modify
         */
        void initEvents(rtype::Event &event);
    };
} // namespace rtype
