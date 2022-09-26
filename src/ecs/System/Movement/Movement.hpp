/**
 * @file Movement.hpp
 * @author Cédric Corge (cedric.corge@epitech.eu)
 * @brief Movement system header file
 * @version 0.1
 * @date 2022-06-01
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef MOVEMENT_HPP_
#define MOVEMENT_HPP_

#include "../ISystem.hpp"

namespace indie
{
    namespace ecs
    {
        namespace system
        {
            /// @brief Movement system
            class MovementSystem : public ISystem {
              public:
                /**
                 * @brief Create new movement system.
                 */
                MovementSystem()
                {
                }
                /**
                 * @brief Destroy movement system.
                 */
                ~MovementSystem()
                {
                }

                /**
                 * @brief Update all position of given entities.
                 *
                 * @param entities vector of entities.
                 */
                void update(std::vector<std::unique_ptr<indie::ecs::entity::Entity>> &entities) override;

                /**
                 * @brief Get the type of system.
                 *
                 * @return enum value correspond to the type of system
                 */
                indie::ecs::system::SystemType getSystemType() const override;

              private:
            };
        } // namespace system
    }     // namespace ecs
} // namespace indie

#endif /* !MOVEMENT_HPP_ */
