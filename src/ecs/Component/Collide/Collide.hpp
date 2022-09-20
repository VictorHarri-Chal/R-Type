/*
** EPITECH PROJECT, 2022
** Collide (COMPONENT)
** File description:
** Collide (COMPONENT)
*/

#ifndef COLLIDE_HPP_
#define COLLIDE_HPP_

#include "../IComponent.hpp"

namespace rtype
{
    namespace ecs
    {
        namespace component
        {
            class Collide : public IComponent {
              public:
                Collide();
                ~Collide();
                bool checkCollision(rtype::ecs::component::Collide *otherEntityCollide);
                void setCollide(bool collide);
                bool getCollide() const;

                rtype::ecs::component::compoType getType() const;

              protected:
              private:
                bool _collide;
            };
        } // namespace component
    }     // namespace ecs
} // namespace rtype

#endif /* !COLLIDE_HPP_ */
