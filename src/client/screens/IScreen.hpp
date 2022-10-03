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
#include "../../ecs/Entity/Entity.hpp"

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
         * @brief Draw the screen
         * 
         */
        virtual void draw(rtype::Game *gameEngine) = 0;
        /**
         * @brief Update the screen
         * 
         */
        virtual void update() = 0;
        /**
         * @brief Handle events
         * 
         * @param event Event to be handled
         * @return int The scene number
         */
        virtual int handleEvent(rtype::Event &event) = 0;
    };
}