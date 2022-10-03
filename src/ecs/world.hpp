/*
** EPITECH PROJECT, 2022
** Entity (ENTITY)
** File description:
** Entity (ENTITY)
*/

#pragma once

#include <vector>
#include <memory>
#include <iostream>
#include "Entity/Entity.hpp"
#include "System/ISystem.hpp"

namespace rtype
{
    /// \file Docs/doc-Ecs
    namespace ecs
    {
        namespace world
        {
            /// @brief World class don't delete entity in world the destructor will do it
            class World {
              public:
                /**
                 * @brief Construct a new World object
                 *
                 */
                World();
                /**
                 * @brief Destroy entity pointer.
                 */
                ~World();

                /**
                 * @brief Add entity to world
                 *
                 * @tparam entity the Entity to add
                 * @param entity Entity who want to add to world
                 */
                void addEntity(entity::Entity *entity);

                /**
                 * @brief Add System to world
                 *
                 * @tparam System the system to add
                 * @param System system who want to add to world
                 */
                void addSystem(system::ISystem *system);

                /**
                 * @brief Get the Entity of the given id
                 *
                 * @param id The id of the entity to get
                 *
                 * @return rtype::ecs::entity::Entity* Pointer to the wanted Entity if entity exist | nullptr if entity doesn't exist
                 */
                rtype::ecs::entity::Entity *getEntity(size_t id) const;

                /**
                 * @brief Get the Entities vector with all entities
                 *
                 * @return std::vector<rtype::ecs::entity::Entity*> with all entities contain in this world
                 */
                std::vector<rtype::ecs::entity::Entity*> getEntities() const;

                /**
                 * @brief Get the System vector with all system in the world²
                 *
                 * @return std::vector<rtype::ecs::system::ISystem*> with all System contain in this world
                 */
                std::vector<rtype::ecs::system::ISystem*> getSystems() const;

              private:
                /**
                 * @brief Vector of component
                 *
                 */
                std::vector<rtype::ecs::entity::Entity*> _entitiesVector;
                /**
                 * @brief Vector of component
                 *
                 */
                std::vector<rtype::ecs::system::ISystem*> _systemsVector;
                /**
                 * @brief Entity type object
                 *
                 */
                size_t nbEntities;
            };
        }
    }
}
