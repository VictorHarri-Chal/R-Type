/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** boss.cpp
*/

#include "boss.hpp"

rtype::ecs::component::Boss::Boss(int currWave)
{
    if (currWave == 5) {
        _health = 30.0f;
        _damage = 1.0f;
        _speed = 2.0f;
        _cadency = sf::seconds(1.0/1.0f);
    } else if (currWave == 10) {
        _health = 70.0f;
        _damage = 1.0f;
        _speed = 2.0f;
        _cadency = sf::seconds(1.0/1.2f);
    } else {
        _health = 30.0f;
        _damage = 1.0f;
        _speed = 2.0f;
        _cadency = sf::seconds(1.0/1.0f);
    }
}

rtype::ecs::component::compoType rtype::ecs::component::Boss::getType() const
{
    return (rtype::ecs::component::compoType::SHIP);
}

rtype::ecs::component::shipType rtype::ecs::component::Boss::getShipType() const
{
    return rtype::ecs::component::shipType::BOSS;
}