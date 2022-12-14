/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** support.cpp
*/

#include "support.hpp"

rtype::ecs::component::Support::Support()
{
    _health = 5.0f;
    _maxHealth = _health;
    _damage = 1.0f;
    _speed = 5.0f;
    _cadency = sf::seconds(1.0/4.0f);
    _isSkillActive = false;
    _skillDuration = sf::seconds(5.f);
    _skillCooldown = sf::seconds(15.f);

}

rtype::ecs::component::compoType rtype::ecs::component::Support::getType() const
{
    return (rtype::ecs::component::compoType::SHIP);
}

rtype::ecs::component::shipType rtype::ecs::component::Support::getShipType() const
{
    return rtype::ecs::component::shipType::SUPPORT;
}