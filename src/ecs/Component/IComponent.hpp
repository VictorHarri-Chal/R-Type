/*
** EPITECH PROJECT, 2022
** Component (ECS)
** File description:
** Component (ECS)
*/


#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

#include "../../sfml/Sfml.hpp"

namespace rtype
{
    /// \file Docs/doc-Ecs
    namespace ecs
    {
        namespace component
        {
            class Transform;

            /**
             * @brief Enum for component type
             *
             */
            enum compoType {
                TRANSFORM,
                DRAWABLE2D,
                ALIVE,
                INVENTORY,
                PROJECTILE,
                COLLIDE,
                SOUND,
                SHIP,
                HEALTH,
                UNKNOWNCOMPO
            };
            /**
             * @brief Enum for drawable type
             *
             */
            enum drawableType { SPRITE, TEXT, RECTANGLE, UNKNOWNDRAWABLE };
            /**
             * @brief Enum for ship type
             * @param ALLY Allies ship
             * @param ZIGZAG Enemy ship who have a zigzag movement
             * @param RUSHER Enemy ship who goes straight on allies ship
             */
            enum shipType { ALLY_SHIP, ZIGZAG, RUSHER, UNKNOWNSHIP };
            /**
             * @brief Enum for projectile type
             * @param ALLY Allies projectile
             * @param ENEMY Enemy projectile
             */
            enum projectileType { ALLY_PROJECTILE, ENEMY_PROJECTILE, UNKNOWNPROJECTILE };
            /**
             * @brief Enum for bonus type
             *
             */
            enum bonusType { UNKNOWNBONUS };

            /// @brief Component interface
            class IComponent {
              public:
                /**
                 * @brief Create a new IComponent.
                 */
                virtual ~IComponent() = default;

                /**
                 * @brief Get type of the component.
                 *
                 * @return the compoType value of the component.
                 */
                virtual rtype::ecs::component::compoType getType() const = 0;

              private:
            };
        }
    }
}

#endif /* !ICOMPONENT_HPP_ */