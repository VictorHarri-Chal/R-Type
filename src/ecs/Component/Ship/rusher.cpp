/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** rusher.cpp
*/

#include "rusher.hpp"

rtype::ecs::component::Rusher::Rusher(int currWave)
{
    _health = 1.0f * (currWave * 0.2f);
    _damage = 1.0f;
    _speed = 0.20f;
    _cadency = sf::seconds(1.0/1.5f);
}

rtype::ecs::component::compoType rtype::ecs::component::Rusher::getType() const
{
    return (rtype::ecs::component::compoType::SHIP);
}

rtype::ecs::component::shipType rtype::ecs::component::Rusher::getShipType() const
{
    return rtype::ecs::component::shipType::RUSHER;
}
