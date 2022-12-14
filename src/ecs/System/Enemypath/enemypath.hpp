/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** enemypath.hpp
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
            /// @brief Enemypath system
            class EnemypathSystem : public ISystem {
              public:
                /**
                 * @brief Construct a new Enemypath object
                 *
                 */
                EnemypathSystem() {}
                /**
                 * @brief Destroy the Enemypath object
                 *
                 */
                ~EnemypathSystem() {}
                /**
                 * @brief Update Enemypath entities
                 *
                 * @param entities Entity to update
                 * @param gameEngine Game engine
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

