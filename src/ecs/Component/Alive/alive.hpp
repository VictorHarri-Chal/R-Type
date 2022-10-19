/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** alive.hpp
*/

#pragma once

#include "../IComponent.hpp"

namespace rtype
{
    namespace ecs
    {
        namespace component
        {
            class Alive : public IComponent {
                public:
                    Alive();
                    Alive(bool isAlive);
                    ~Alive();
                    void setAlive(bool isAlive);
                    bool getAlive() const;

                    rtype::ecs::component::compoType getType() const;

                protected:
                private:
                    bool _alive;
            };
        }
    }
}
