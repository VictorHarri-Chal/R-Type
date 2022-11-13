/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** stealthy.cpp
*/

#include "stealthy.hpp"

rtype::ecs::component::Stealthy::Stealthy()
{
    _health = 3.0f;
    _maxHealth = _health;
    _damage = 0.6f;
    _speed = 6.0f;
    _cadency = sf::seconds(1.0/5.0f);
    _isSkillActive = false;
    _skillDuration = sf::seconds(5.f);
    _skillCooldown = sf::seconds(10.f);
}

rtype::ecs::component::compoType rtype::ecs::component::Stealthy::getType() const
{
    return (rtype::ecs::component::compoType::SHIP);
}

rtype::ecs::component::shipType rtype::ecs::component::Stealthy::getShipType() const
{
    return rtype::ecs::component::shipType::STEALTHY;
}
