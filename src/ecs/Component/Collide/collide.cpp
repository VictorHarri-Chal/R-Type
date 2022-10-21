/*
** EPITECH PROJECT, 2022
** Collide (COMPONENT)
** File description:
** Collide (COMPONENT)
*/

#include "collide.hpp"

rtype::ecs::component::Collide::Collide()
{
    this->_collide = true;
}

rtype::ecs::component::Collide::~Collide()
{
}

rtype::ecs::component::compoType rtype::ecs::component::Collide::getType() const
{
    return (rtype::ecs::component::compoType::COLLIDE);
}

void rtype::ecs::component::Collide::setCollide(bool collide)
{
    this->_collide = collide;
}

bool rtype::ecs::component::Collide::getCollide() const
{
    return (this->_collide);
}
