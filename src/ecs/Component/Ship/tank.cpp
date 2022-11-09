/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** tank.cpp
*/

#include "tank.hpp"

rtype::ecs::component::Tank::Tank()
{
    _health = 6.0f;
    _maxHealth = _health;
    _damage = 1.0f;
    _speed = 4.0f;
    _cadency = sf::seconds(1.0/4.0f);
}

rtype::ecs::component::compoType rtype::ecs::component::Tank::getType() const
{
    return (rtype::ecs::component::compoType::SHIP);
}

rtype::ecs::component::shipType rtype::ecs::component::Tank::getShipType() const
{
    return rtype::ecs::component::shipType::TANK;
}