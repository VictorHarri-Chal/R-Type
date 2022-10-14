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
         * 
         */
        virtual void update(rtype::Game *gameEngine) = 0;
        /**
         * @brief Handle events
         * 
         * @param event Event to be handled
         * @return int The scene number
         */
        virtual int handleEvent(rtype::Event &event, rtype::Game *gameEngine) = 0;

        virtual bool isButtonPressed(size_t index, rtype::Game *gameEngine, rtype::Event &event) = 0;

        virtual bool isMouseOnButton(size_t index, rtype::Game *gameEngine, rtype::Event &event) = 0;
    };
}
