/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Movement.hpp
*/

#ifndef MOVEMENT_HPP_
#define MOVEMENT_HPP_

#include "../ISystem.hpp"

namespace rtype
{
    class Game;
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
                void update(std::vector<rtype::ecs::entity::Entity*> entities, rtype::Game*gameEngine) override;

                /**
                 * @brief Get the type of system.
                 *
                 * @return enum value correspond to the type of system
                 */
                rtype::ecs::system::SystemType getSystemType() const override;

              private:
            };
        } // namespace system
    }     // namespace ecs
} // namespace rtype

#endif /* !MOVEMENT_HPP_ */
