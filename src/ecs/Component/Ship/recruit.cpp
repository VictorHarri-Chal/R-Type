/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** recruit.cpp
*/

#include "recruit.hpp"

rtype::ecs::component::Recruit::Recruit()
{
    _health = 3;
}

rtype::ecs::component::compoType rtype::ecs::component::Recruit::getType() const
{
    return (rtype::ecs::component::compoType::SHIP);
}

rtype::ecs::component::shipType rtype::ecs::component::Recruit::getShipType() const
{
    return rtype::ecs::component::shipType::RECRUIT;
}

bool rtype::ecs::component::Recruit::getDirectionHorizontal() const
{
    return this->_directionHorizontal;
}

bool rtype::ecs::component::Recruit::getDirectionVertical() const
{
    return this->_directionVertical;
}

void rtype::ecs::component::Recruit::setDirectionHorizontal(bool dir)
{
    _directionHorizontal = dir;
}

void rtype::ecs::component::Recruit::setDirectionVertical(bool dir)
{
    _directionVertical = dir;
}

float rtype::ecs::component::Recruit::getHealth() const
{
    return (this->_health);
}

void rtype::ecs::component::Recruit::setHealth(float health)
{
    this->_health = health;
}