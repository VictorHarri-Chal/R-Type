/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Collide.hpp
*/


#include "../ISystem.hpp"

namespace rtype
{
    namespace ecs
    {
        namespace system
        {
            /// @brief Collide system
            class CollideSystem : public ISystem {
              public:
                /**
                 * @brief Construct a new Collide object
                 *
                 */
                CollideSystem() {}
                /**
                 * @brief Destroy the Collide object
                 *
                 */
                ~CollideSystem() {}
                /**
                 * @brief Update all the entities with the system properties.
                 *
                 * @param entities Vector of entites to update
                 * @param gameEngine Game engine
                 */
                void update(std::vector<rtype::ecs::entity::Entity*> entities, rtype::Game*gameEngine);
                /**
                 * @brief Check collisions bewteen two entities
                 * 
                 * @param entity First entity
                 * @param otherEntity Second entity
                 * @param collide Collide component of the first entity
                 * @param otherEntityCollide Collide component of the second entity
                 * @param compoToRemove Vector of components to remove
                 * @param count Count of the entity
                 * 
                 * @return true if there is a collision
                 */
                // bool checkCollision(std::unique_ptr<rtype::ecs::entity::Entity> &entity,
                //     std::unique_ptr<rtype::ecs::entity::Entity> &otherEntity, rtype::ecs::component::Collide *collide,
                //     rtype::ecs::component::Collide *otherEntityCollide, std::vector<int> &compoToRemove, int &count);
                /**
                 * @brief Get the type of system.
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
