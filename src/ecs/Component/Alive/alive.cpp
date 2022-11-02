/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** alive.cpp
*/

#include "alive.hpp"

rtype::ecs::component::Alive::Alive()
{
    this->_alive = true;
}

void rtype::ecs::component::Alive::setAlive(bool alive)
{
    this->_alive = alive;
}

bool rtype::ecs::component::Alive::getAlive() const
{
    return (this->_alive);
}

rtype::ecs::component::compoType rtype::ecs::component::Alive::getType() const
{
    return (rtype::ecs::component::compoType::ALIVE);
}
