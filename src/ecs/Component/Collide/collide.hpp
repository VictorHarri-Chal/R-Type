/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** collide.hpp
*/

#pragma once

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
