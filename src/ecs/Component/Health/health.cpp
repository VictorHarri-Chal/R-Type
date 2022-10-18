/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** health.cpp
*/

#include "health.hpp"

rtype::ecs::component::Health::Health(int health)
{
    this->_health = health;
}

rtype::ecs::component::Health::~Health()
{
}

void rtype::ecs::component::Health::setHealth(int health)
{
    this->_health = health;
}

int rtype::ecs::component::Health::getHealth() const
{
    return (this->_health);
}

rtype::ecs::component::compoType rtype::ecs::component::Health::getType() const
{
    return (rtype::ecs::component::compoType::HEALTH);
}
