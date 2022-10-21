/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** collide.hpp
*/

#pragma once

#include "../ISystem.hpp"

namespace rtype
{
    namespace ecs
    {
        namespace system
        {
            /// @brief Collide system
            class CollideSystem : public ISystem {
              public:
                /**
                 * @brief Construct a new Collide object
                 *
                 */
                CollideSystem() {}
                /**
                 * @brief Destroy the Collide object
                 *
                 */
                ~CollideSystem() {}
                /**
                 * @brief Update all the entities with the system properties.
                 *
                 * @param entities Vector of entites to update
                 * @param gameEngine Game engine
                 */
                void update(std::vector<rtype::ecs::entity::Entity*> entities, rtype::Game*gameEngine);
                /**
                 * @brief Get the type of system.
                 *
                 * @return rtype::ecs::system::SystemType SystemType
                 */
                rtype::ecs::system::SystemType getSystemType() const;

              protected:
              private:
            };
        } // namespace system
    }     // namespace ecs
} // namespace rtype
