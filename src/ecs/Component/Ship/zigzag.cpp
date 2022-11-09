/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** zigzag.cpp
*/

#include "zigzag.hpp"

rtype::ecs::component::Zigzag::Zigzag(int currWave)
{
    _health = 0.9f + (currWave * 0.4f);
    _damage = 1.0f;
    _speed = 0.15f;
    _cadency = sf::seconds(1.0/1.0f);
}

rtype::ecs::component::compoType rtype::ecs::component::Zigzag::getType() const
{
    return (rtype::ecs::component::compoType::SHIP);
}

rtype::ecs::component::shipType rtype::ecs::component::Zigzag::getShipType() const
{
    return rtype::ecs::component::shipType::ZIGZAG;
}