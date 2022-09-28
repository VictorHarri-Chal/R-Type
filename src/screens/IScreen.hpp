  /*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** IScreen.hpp
*/

#pragma once

#include <memory>
#include "../ecs/System/ISystem.hpp"
#include "../../include/EventCode.hpp"
#include "../sfml/Sfml.hpp"
#include "../ecs/Entity/Entity.hpp"
#include "../ecs/System/Draw2D/Draw2D.hpp"

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
        virtual void draw() = 0;
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
        /**
       * @brief Add entity to the screen
         * 
         * @param entity Entity to add to the screen
         */
        virtual void addEntity(std::unique_ptr<rtype::ecs::entity::Entity> entity) = 0;
        /**
         * @brief Add system to the screen
         * 
         * @param system System to add to the screen
         */
        virtual void addSystem(std::unique_ptr<rtype::ecs::system::ISystem> system) = 0;
    };
}
