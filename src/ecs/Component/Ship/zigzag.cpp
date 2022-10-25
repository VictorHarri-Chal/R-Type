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
    _health = 2 * (currWave * 0.4);
}

rtype::ecs::component::compoType rtype::ecs::component::Zigzag::getType() const
{
    return (rtype::ecs::component::compoType::SHIP);
}

rtype::ecs::component::shipType rtype::ecs::component::Zigzag::getShipType() const
{
    return rtype::ecs::component::shipType::ZIGZAG;
}

bool rtype::ecs::component::Zigzag::getDirectionHorizontal() const
{
    return this->_directionHorizontal;
}

bool rtype::ecs::component::Zigzag::getDirectionVertical() const
{
    return this->_directionVertical;
}

void rtype::ecs::component::Zigzag::setDirectionHorizontal(bool dir)
{
    _directionHorizontal = dir;
}

void rtype::ecs::component::Zigzag::setDirectionVertical(bool dir)
{
    _directionVertical = dir;
}

float rtype::ecs::component::Zigzag::getHealth() const
{
    return (this->_health);
}

void rtype::ecs::component::Zigzag::setHealth(float health)
{
    this->_health = health;
}