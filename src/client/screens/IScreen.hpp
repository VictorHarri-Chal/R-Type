  /*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** IScreen.hpp
*/

#pragma once

#include <memory>
#include "../../ecs/System/ISystem.hpp"
#include "../../../include/EventCode.hpp"
#include "../../sfml/Sfml.hpp"
#include "../../ecs/Entity/entity.hpp"

namespace rtype
{
    /// @brief IScreen class
    class IScreen {
      public:
        /**
         * @brief Destroy the IScreen object
         * 
         */
        virtual ~IScreen() = default;
        /**
         * @brief Init the screen
         * 
         */
        virtual void init() = 0;
        /**
         * @brief Update the screen
         * @param gameEngine Game engine
         * 
         */
        virtual void update(rtype::Game *gameEngine) = 0;
        /**
         * @brief Handle events
         * 
         * @param event Event to be handled
         * @param gameEngine Game engine
         * @return int The scene number
         */
        virtual int handleEvent(rtype::Event &event, rtype::Game *gameEngine) = 0;
        /**
         * @brief Check if button is pressed
         * 
         * @param index Index of the button
         * @param gameEngine Game engine
         * @param event Event to be handled
         * @return true If button is pressed
         * @return false If button is not pressed
         */
        virtual bool isButtonPressed(size_t index, rtype::Game *gameEngine, rtype::Event &event) = 0;
        /**
         * @brief Check if mouse is on button
         * 
         * @param index Index of the button
         * @param gameEngine Game engine
         * @param event Event to be handled
         * @return true If mouse is on button
         * @return false If mouse is not on button
         */
        virtual bool isMouseOnButton(size_t index, rtype::Game *gameEngine, rtype::Event &event) = 0;
    };
}
