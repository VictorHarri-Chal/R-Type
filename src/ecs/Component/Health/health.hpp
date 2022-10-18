/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** health.hpp
*/

#ifndef HEALTH_HPP_
#define HEALTH_HPP_


#include "../IComponent.hpp"

namespace rtype
{
    namespace ecs
    {
        namespace component
        {
            class Health : public IComponent {
                public:
                    Health(int health);
                    ~Health();
                    void setHealth(int isHealth);
                    int getHealth() const;

                    rtype::ecs::component::compoType getType() const;

                protected:
                private:
                    bool _health;
            };
        }
    }
}

#endif /* !HEALTH_HPP_ */
