/*
** EPITECH PROJECT, 2022
** System (ECS)
** File description:
** System (ECS)
*/

#pragma once

#include <memory>
#include <vector>
#include "../Entity/entity.hpp"

namespace rtype
{
    class Game;
    /// \file Docs/how_to_use_ecs.md
    namespace ecs
    {
        namespace system
        {
            /**
             * @brief Enum for system types
             * 
             */
            enum SystemType {
                COLLIDESYSTEM,
                DRAWABLE2DSYSTEM,
                ENEMYPATHSYSTEM,
                MOVEMENTSYSTEM,
                PARTICLESSYSTEM,
                SOUNDSYSTEM
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
                 * @param gameEngine the game engine.
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
