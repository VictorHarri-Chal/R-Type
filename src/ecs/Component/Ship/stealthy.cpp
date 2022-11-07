/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** stealthy.cpp
*/

#include "stealthy.hpp"

rtype::ecs::component::Stealthy::Stealthy()
{
    _health = 2.0f;
    _damage = 0.6f;
    _speed = 8.0f;
    _cadency = sf::seconds(1.0/3.0f);
}

rtype::ecs::component::compoType rtype::ecs::component::Stealthy::getType() const
{
    return (rtype::ecs::component::compoType::SHIP);
}

rtype::ecs::component::shipType rtype::ecs::component::Stealthy::getShipType() const
{
    return rtype::ecs::component::shipType::STEALTHY;
}