/**
 * @file Sound.hpp
 * @author Cédric Corge (cedric.corge@epitech.eu)
 * @brief Sound system header file
 * @version 0.1
 * @date 2022-06-01
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include "../ISystem.hpp"

namespace indie
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
                void update(std::vector<std::unique_ptr<indie::ecs::entity::Entity>> &entities);

                /**
                 * @brief Get the System Type object
                 * 
                 * @return indie::ecs::system::SystemType SystemType
                 */
                indie::ecs::system::SystemType getSystemType() const;

              protected:
              private:
            };
        } // namespace system
    }     // namespace ecs
} // namespace indie
