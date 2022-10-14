/*
** EPITECH PROJECT, 2022
** Collide (COMPONENT)
** File description:
** Collide (COMPONENT)
*/

#include "collide.hpp"

rtype::ecs::component::Collide::Collide()
{
    this->_collide = false;
}

rtype::ecs::component::Collide::~Collide()
{
}

rtype::ecs::component::compoType rtype::ecs::component::Collide::getType() const
{
    return (rtype::ecs::component::compoType::COLLIDE);
}

bool rtype::ecs::component::Collide::checkCollision(rtype::ecs::component::Collide *otherEntityCollide)
{
    return (true);
}

void rtype::ecs::component::Collide::setCollide(bool collide)
{
    this->_collide = collide;
}

bool rtype::ecs::component::Collide::getCollide() const
{
    return (this->_collide);
}
