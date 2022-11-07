/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** sniper.cpp
*/

#include "sniper.hpp"

rtype::ecs::component::Sniper::Sniper()
{
    _health = 3.0f;
    _damage = 1.5f;
    _speed = 5.0f;
    _cadency = sf::seconds(1.0/2.0f);
}

rtype::ecs::component::compoType rtype::ecs::component::Sniper::getType() const
{
    return (rtype::ecs::component::compoType::SHIP);
}

rtype::ecs::component::shipType rtype::ecs::component::Sniper::getShipType() const
{
    return rtype::ecs::component::shipType::SNIPER;
}