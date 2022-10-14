/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** explodable.hpp
*/

#ifndef EXPLODABLE_HPP_
#define EXPLODABLE_HPP_

#include <map>
#include "../ISystem.hpp"

namespace rtype
{
    namespace ecs
    {
        namespace system
        {
            /// @brief Explodable system
            class Explodable : public ISystem {
              public:
                /**
                 * @brief Construct a new Explodable object
                 *
                 */
                Explodable();
                /**
                 * @brief Destroy the Explodable object
                 *
                 */
                ~Explodable();
                /**
                 * @brief Update explodable entities
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

#endif /* !EXPLODABLE_HPP_ */
