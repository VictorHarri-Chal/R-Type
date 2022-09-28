/*
** EPITECH PROJECT, 2022
** System (ECS)
** File description:
** System (ECS)
*/

#pragma once

#include <memory>
#include <vector>
#include "../Entity/Entity.hpp"

namespace rtype
{
    class Game;
    /// \file Docs/doc-Ecs
    namespace ecs
    {
        namespace system
        {
            /**
             * @brief Enum for system types
             * 
             */
            enum SystemType {
                DRAWABLE2DSYSTEM,
                MOVEMENTSYSTEM,
                COLLIDESYSTEM,
                SOUNDSYSTEM,
                EXPLODABLESYSTEM
            };
            /// @brief System
            class ISystem {
              public:
                /**
                 * @brief Destroy system.
                 */
                virtual ~ISystem() = default;

                /**
                 * @brief Update all the entities with the system properties.
                 *
                 * @param entities vector of entites to update
                 */
                virtual void update(std::vector<rtype::ecs::entity::Entity*> entities, rtype::Game*gameEngine) = 0;

                /**
                 * @brief Get the type of system.
                 *
                 * @return enum value correspond to the type of system
                 */
                virtual rtype::ecs::system::SystemType getSystemType() const = 0;

              private:
            };
        }
    }
}
