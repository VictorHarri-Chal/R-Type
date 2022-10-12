/*
** EPITECH PROJECT, 2022
** Alive (COMPONENT)
** File description:
** Alive (COMPONENT)
*/

#ifndef ALIVE_HPP_
#define ALIVE_HPP_


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

#endif /* !ALIVE_HPP_ */
