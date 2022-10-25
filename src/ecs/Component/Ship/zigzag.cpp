/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** zigzag.cpp
*/

#include "zigzag.hpp"

rtype::ecs::component::Zigzag::Zigzag(bool dirHor, bool dirVer, int currWave)
{
    _directionHorizontal = dirHor;
    _directionVertical = dirVer;
    _health = 2.0f * (currWave * 0.4f);
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