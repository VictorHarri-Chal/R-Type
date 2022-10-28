/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** kamikaze.cpp
*/

#include "kamikaze.hpp"

rtype::ecs::component::Kamikaze::Kamikaze(int currWave)
{
    (void) currWave;
    _health = 1.0f;
    _damage = 2.0f;
    _speed = 0.25f;
}

rtype::ecs::component::compoType rtype::ecs::component::Kamikaze::getType() const
{
    return (rtype::ecs::component::compoType::SHIP);
}

rtype::ecs::component::shipType rtype::ecs::component::Kamikaze::getShipType() const
{
    return rtype::ecs::component::shipType::KAMIKAZE;
}