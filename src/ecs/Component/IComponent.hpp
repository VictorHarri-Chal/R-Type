/*
** EPITECH PROJECT, 2022
** Component (ECS)
** File description:
** Component (ECS)
*/


#pragma once
#include "../../sfml/Sfml.hpp"

namespace rtype
{
    /// \file Docs/how_to_use_ecs.md
    namespace ecs
    {
        namespace component
        {
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
                UNKNOWNCOMPO
            };
            /**
             * @brief Enum for drawable type
             *
             */
            enum drawableType { SPRITE, TEXT, RECTANGLE, UNKNOWNDRAWABLE };
            /**
             * @brief Enum for projectile type
             * @param ALLY Allies projectile
             * @param ENEMY Enemy projectile
             * @param MINE Enemy boss projectile
             */
            enum projectileType { ALLY_PROJECTILE, ENEMY_PROJECTILE, MINE, UNKNOWNPROJECTILE };
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
