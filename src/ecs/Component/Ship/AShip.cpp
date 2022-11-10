/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** AShip.cpp
*/

#include "AShip.hpp"

float rtype::ecs::component::AShip::getHealth() const
{
    return (this->_health);
}

void rtype::ecs::component::AShip::setHealth(float health)
{
    this->_health = health;
}

float rtype::ecs::component::AShip::getMaxHealth() const
{
    return (this->_maxHealth);
}

void rtype::ecs::component::AShip::setMaxHealth(float maxHealth)
{
    this->_maxHealth = maxHealth;
}

float rtype::ecs::component::AShip::getDamage() const
{
    return (this->_damage);
}

void rtype::ecs::component::AShip::setDamage(float damage)
{
    this->_damage = damage;
}

float rtype::ecs::component::AShip::getSpeed() const
{
    return (this->_speed);
}

void rtype::ecs::component::AShip::setSpeed(float speed)
{
    this->_speed = speed;
}

sf::Time rtype::ecs::component::AShip::getCadency() const
{
    return (this->_cadency);
}

void rtype::ecs::component::AShip::setCadency(sf::Time cadency)
{
    this->_cadency = cadency;
}

sf::Clock rtype::ecs::component::AShip::getClock() const
{
    return (this->_clock);
}

void rtype::ecs::component::AShip::restartClock()
{
    _clock.restart();
}