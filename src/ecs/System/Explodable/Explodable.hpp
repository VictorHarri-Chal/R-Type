/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Explodable.hpp
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
                 * @brief Destroy the boxes on the map
                 *
                 * @param compoToRemove Component to be removed
                 * @param entities Entity to be removed
                 * @param explodableCompo Explodable component
                 * @param transformCompo Transform component
                 */
                void destroyBoxes(std::vector<int> &compoToRemove,
                    std::vector<std::unique_ptr<rtype::ecs::entity::Entity>> &entities,
                    rtype::ecs::component::Explodable *explodableCompo,
                    rtype::ecs::component::Transform *transformCompo);

                float getValue(float position, float index, char operand);
                float getNewValue(float bombPos);

                std::map<size_t, rtype::ecs::entity::Entity *> getEntityByPosition(
                    std::vector<std::unique_ptr<rtype::ecs::entity::Entity>> &entities, float x, float y);

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
