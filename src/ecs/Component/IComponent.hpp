/*
** EPITECH PROJECT, 2022
** Component (ECS)
** File description:
** Component (ECS)
*/

#pragma once

namespace rtype
{
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
                DRAWABLE3D,
                ALIVE,
                COLLECTABLE,
                INVENTORY,
                EXPLODABLE,
                COLLIDE,
                SOUND,
                DESTROYABLE,
                MODEL,
                ANIMATED,
                UNKNOWNCOMPO
            };
            /**
             * @brief Enum for drawable type
             *
             */
            enum drawableType { CIRCLE, TEXT, RECTANGLE, SPHERE, CUBE, OBJECT, UNKNOWNDRAWABLE };
            /**
             * @brief Enum for bonus type
             *
             */
            enum bonusType { BOMBUP, SPEEDUP, FIREUP, WALLPASS, UNKNOWNBONUS };

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
