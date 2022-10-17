/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Sound.hpp
*/

#pragma once

#include "../ISystem.hpp"

namespace rtype
{
    namespace ecs
    {
        namespace system
        {
            /// @brief Sound system
            class Sound : public ISystem {
              public:
                Sound();
                ~Sound();

                /**
                 * @brief Update all the entities with the system properties.
                 *
                 * @param entities vector of entites to update
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