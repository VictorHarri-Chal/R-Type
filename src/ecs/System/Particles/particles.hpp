/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Particles.hpp
*/

#pragma once

#include <map>
#include "../ISystem.hpp"

namespace rtype
{
    namespace ecs
    {
        namespace system
        {
            /// @brief Particles system
            class Particles : public ISystem {
              public:
                /**
                 * @brief Construct a new Particles object
                 *
                 */
                Particles() {}
                /**
                 * @brief Destroy the Particles object
                 *
                 */
                ~Particles() {}
                /**
                 * @brief Update Particles entities
                 *
                 * @param entities Entity to update
                 */
                void update(std::vector<rtype::ecs::entity::Entity*> entities, rtype::Game*gameEngine);
                /**
                 * @brief Get the System Type object
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
