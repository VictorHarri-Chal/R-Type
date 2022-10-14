/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Explodable.hpp
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
                 * @param gameEngine the game engine.
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
                /**
                 * @brief Get the Vvalue of the bomb
                 * 
                 * @param position Position of the bomb
                 * @param index Index of the bomb
                 * @param operand Operand of the bomb
                 * @return float Value of the bomb
                 */
                float getValue(float position, float index, char operand);
                /**
                 * @brief Get the new value of the bomb
                 * 
                 * @param bombPos Position of the bomb
                 * @return float Value of the bomb
                 */
                float getNewValue(float bombPos);
                /**
                 * @brief Get the Entity By Position 
                 * 
                 * @param entities Entity to check
                 * @param x X position
                 * @param y Y position
                 * @return std::map<size_t, rtype::ecs::entity::Entity *> Entity by position
                 */
                std::map<size_t, rtype::ecs::entity::Entity *> getEntityByPosition(
                    std::vector<std::unique_ptr<rtype::ecs::entity::Entity>> &entities, float x, float y);

                /**
                 * @brief Get the System Type object
                 *
                 * @return rtype::ecs::system::SystemType the type of system
                 */
                rtype::ecs::system::SystemType getSystemType() const;

              protected:
              private:
            };
        } // namespace system
    }     // namespace ecs
} // namespace rtype

#endif /* !EXPLODABLE_HPP_ */
