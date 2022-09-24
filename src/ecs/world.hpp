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


namespace rtype
{
    namespace ecs
    {
        namespace world
        {
            /// @brief Entity class
            class World {
              public:
                /**
                 * @brief Construct a new World object
                 *
                 */
                World();
                /**
                 * @brief Destroy entity.
                 */
                ~World();

                /**
                 * @brief Add entity to world
                 *
                 * @tparam entity the Entity to add
                 * @param entity Entity who want to add to world
                 */
                void addComponent(entity::Entity *entity)
                {
                    entity->setId(this->nbEntities);
                    this->_entitiesVector.push_back(entity);
                    nbEntities++;
                }

              private:
                /**
                 * @brief Vector of component
                 *
                 */
                std::vector<rtype::ecs::entity::Entity*> _entitiesVector;
                /**
                 * @brief Entity type object
                 *
                 */
                size_t nbEntities;
            };
        }
    }
}
