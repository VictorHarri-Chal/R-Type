/**
 * @file Explodable.hpp
 * @author Cédric Corge (cedric.corge@epitech.eu)
 * @brief Explodable system header file
 * @version 0.1
 * @date 2022-06-01
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef EXPLODABLE_HPP_
#define EXPLODABLE_HPP_

#include <map>
#include "../ISystem.hpp"

namespace indie
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
                void update(std::vector<std::unique_ptr<indie::ecs::entity::Entity>> &entities);
                /**
                 * @brief Destroy the boxes on the map
                 *
                 * @param compoToRemove Component to be removed
                 * @param entities Entity to be removed
                 * @param explodableCompo Explodable component
                 * @param transformCompo Transform component
                 */
                void destroyBoxes(std::vector<int> &compoToRemove,
                    std::vector<std::unique_ptr<indie::ecs::entity::Entity>> &entities,
                    indie::ecs::component::Explodable *explodableCompo,
                    indie::ecs::component::Transform *transformCompo);

                float getValue(float position, float index, char operand);
                float getNewValue(float bombPos);

                std::map<size_t, indie::ecs::entity::Entity *> getEntityByPosition(
                    std::vector<std::unique_ptr<indie::ecs::entity::Entity>> &entities, float x, float y);

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

#endif /* !EXPLODABLE_HPP_ */
