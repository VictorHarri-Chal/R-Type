/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** recruit.cpp
*/

#include "recruit.hpp"

rtype::ecs::component::Recruit::Recruit()
{
    _health = 3.0f;
    _damage = 1.0f;
    _speed = 10.0f;
    _cadency = sf::seconds(1.0/3.0f);
}

rtype::ecs::component::compoType rtype::ecs::component::Recruit::getType() const
{
    return (rtype::ecs::component::compoType::SHIP);
}

rtype::ecs::component::shipType rtype::ecs::component::Recruit::getShipType() const
{
    return rtype::ecs::component::shipType::RECRUIT;
}