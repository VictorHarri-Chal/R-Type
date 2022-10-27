/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** turret.cpp
*/

#include "turret.hpp"

rtype::ecs::component::Turret::Turret(int currWave)
{
    _health = 4.0f * (currWave * 0.6f);
    _damage = 1.0f;
    _speed = 0.15f;
    _cadency = sf::seconds(1.0/3.0f);
}

rtype::ecs::component::compoType rtype::ecs::component::Turret::getType() const
{
    return (rtype::ecs::component::compoType::SHIP);
}

rtype::ecs::component::shipType rtype::ecs::component::Turret::getShipType() const
{
    return rtype::ecs::component::shipType::TURRET;
}