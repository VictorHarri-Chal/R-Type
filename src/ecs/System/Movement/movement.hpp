/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** movement.hpp
*/

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
                MovementSystem() {}
                /**
                 * @brief Destroy movement system.
                 */
                ~MovementSystem() {}

                /**
                 * @brief Update all position of given entities.
                 *
                 * @param entities vector of entities.
                 * @param gameEngine the game engine.
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
