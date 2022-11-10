/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** entity.hpp
*/

#pragma once

#include <vector>
#include <memory>
#include <iostream>
#include "../Component/IComponent.hpp"
#include "../Component/Alive/alive.hpp"
#include "../Component/Collide/collide.hpp"
#include "../Component/Ship/IShip.hpp"
#include "../Component/Drawable2D/drawable2d.hpp"
#include "../Component/Projectile/projectile.hpp"
#include "../Component/Sound/sound.hpp"
#include "../Component/Transform/transform.hpp"
#include "../Component/Ship/recruit.hpp"
#include "../Component/Ship/sniper.hpp"
#include "../Component/Ship/stealthy.hpp"
#include "../Component/Ship/tank.hpp"
#include "../Component/Ship/support.hpp"
#include "../Component/Ship/zigzag.hpp"
#include "../Component/Ship/rusher.hpp"
#include "../Component/Ship/kamikaze.hpp"
#include "../Component/Ship/turret.hpp"
#include "../Component/Ship/boss.hpp"


namespace rtype
{
    /// \file Docs/how_to_use_ecs.md
    namespace ecs
    {
        namespace entity
        {
            /**
             * @brief Entity Type for entity object creation
             *
             */
            enum entityType { PLAYER1, PLAYER2, PLAYER3, PLAYER4, ENEMY, ALLY_PROJECTILE, ENEMY_PROJECTILE, PARTICLE, HIT, HEART, TEXT, RECTANGLE, STATIC_SPRITE, UNKNOWN };
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
                        std::cout << "Component not found in remove(): " << type << std::endl;
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
                    std::cout << "Component not found in getComponent():" << type << std::endl;
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
