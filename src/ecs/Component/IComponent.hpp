/*
** EPITECH PROJECT, 2022
** Component (ECS)
** File description:
** Component (ECS)
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

namespace rtype
{
    namespace ecs
    {
        namespace component
        {
            enum drawableType { CIRCLE, TEXT, RECTANGLE, SPHERE, CUBE, OBJECT, UNKNOWNDRAWABLE };
            enum bonusType { BOMBUP, SPEEDUP, FIREUP, WALLPASS, UNKNOWNBONUS };
            enum compoType {
                TRANSFORM,
                DRAWABLE2D,
                ALIVE,
                INVENTORY,
                EXPLODABLE,
                COLLIDE,
                SOUND,
                DESTROYABLE,
                MODEL
            };
            class IComponent {
                public:
                    virtual ~IComponent() = default;
                    virtual rtype::ecs::component::compoType getType() const = 0;

                protected:
                private:
            };
        }
    }
}

#endif /* !ICOMPONENT_HPP_ */
