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
#include "../Component/IComponent.hpp"
#include "../Component/Alive/Alive.hpp"
#include "../Component/Collide/Collide.hpp"
#include "../Component/Destroyable/Destroyable.hpp"
#include "../Component/Drawable2D/Drawable2D.hpp"
#include "../Component/Explodable/Explodable.hpp"
#include "../Component/IComponent.hpp"
#include "../Component/Inventory/Inventory.hpp"
#include "../Component/Sound/Sound.hpp"
#include "../Component/Transform/Transform.hpp"
#include "../../game/Game.hpp"

namespace rtype
{
    /// \file Docs/doc-Ecs
    namespace ecs
    {
        namespace entity
        {
            /**
             * @brief Entity Type for entity object creation
             *
             */
            enum entityType { PLAYER, ENNEMY, MISSILE, BOSS, BUILDING, UNKNOWN };
            /// @brief Entity class
            class Entity {
              public:
                /**
                 * @brief Create new entity.
                 *
                 * @param type Entity type
                 */
                Entity(entityType type);
                /**
                 * @brief Construct a new Entity object
                 *
                 */
                Entity();
                /**
                 * @brief Destroy entity.
                 */
                ~Entity();

                /**
                 * @brief Check if the entity have a component of the given type.
                 *
                 * @param type the compoType value to check.
                 *
                 * @return true The component is present
                 * @return false The component isn't present
                 */
                bool hasCompoType(rtype::ecs::component::compoType type)
                {
                    for (auto &compo : _componentVector) {
                        if (compo->getType() == type)
                            return (true);
                    }
                    return (false);
                }

                /**
                 * @brief Add component to entity
                 *
                 * @tparam T the component to add
                 * @tparam Type The type of component
                 * @tparam Args The necessary params to create the component
                 * @param type Type of component to check if he already exist
                 * @param args The necessary params to create the component
                 */
                template <typename T, typename... Args> void addComponent(component::compoType type, Args... args)
                {
                    if (hasCompoType(type)) {
                        std::cout << "Component already exist" << std::endl;
                        return;
                    }
                    this->_componentVector.push_back(std::unique_ptr<T>(new T{std::forward<Args>(args)...}));
                }

                /**
                 * @brief Remove component to entity
                 *
                 * @tparam Type The type of component
                 * @param type Type of component who want remove
                 */
                void remove(rtype::ecs::component::compoType type)
                {
                    std::vector<std::unique_ptr<rtype::ecs::component::IComponent>>::iterator it = this->_componentVector.begin();

                    if (hasCompoType(type) == false) {
                        std::cout << "Component not found" << std::endl;
                        return;
                    }
                    for (auto &compo : _componentVector) {
                        it++;
                        if (compo->getType() == type)
                            break;
                    }
                    this->_componentVector.erase(it);
                }

                /**
                 * @brief Get the Drawable Vector
                 *
                 * @return std::vector<rtype::ecs::component::Drawable2D *> Vector of Drawable2D component
                 */
                std::vector<rtype::ecs::component::Drawable2D *> getDrawableVector() const
                {
                    std::vector<rtype::ecs::component::Drawable2D *> vector;
                    for (auto &compo : _componentVector) {
                        if (compo->getType() == rtype::ecs::component::compoType::DRAWABLE2D) {
                            vector.push_back(dynamic_cast<rtype::ecs::component::Drawable2D *>(compo.get()));
                        }
                    }
                    return (vector);
                }

                /**
                 * @brief Get the Component of the given type
                 *
                 * @tparam T The type of component to get
                 * @param type The compoType value of the component to get
                 *
                 * @return T* Pointer to the wanted component
                 */
                template <typename T> T *getComponent(rtype::ecs::component::compoType type)
                {
                    for (auto &compo : _componentVector) {
                        if (compo->getType() == type) {
                            return (dynamic_cast<T *>(compo.get()));
                        }
                    }
                    std::cout << "Component not found" << std::endl;
                    return (nullptr);
                }

                /**
                 * @brief Get the Entity Type
                 *
                 * @return rtype::ecs::entity::entityType The entity type
                 */
                rtype::ecs::entity::entityType getEntityType() const;
                /**
                 * @brief Get the id of Entity
                 *
                 * @return size_t The entity id
                 */
                size_t getId(void) const;
                /**
                 * @brief set the id of Entity
                 *
                 * @param id id of entity to set
                 */
                void setId(size_t id);

              private:
                /**
                 * @brief Vector of component
                 *
                 */
                std::vector<std::unique_ptr<rtype::ecs::component::IComponent>> _componentVector;
                /**
                 * @brief Entity type object
                 *
                 */
                entity::entityType _type;
                /**
                 * @brief Entity id
                 *
                 */
                size_t _id;
            };
        }
    }
}
