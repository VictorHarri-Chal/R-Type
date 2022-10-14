/*
** EPITECH PROJECT, 2022
** Explodable (COMPONENT)
** File description:
** Explodable (COMPONENT)
*/

#include "Explodable.hpp"

rtype::ecs::component::Explodable::Explodable()
{
    this->_range = 0.0;
    this->_explosionTime = 2;
    this->_explode = false;
    this->_exploded = false;
}

rtype::ecs::component::Explodable::Explodable(float range, int explosionTime) : _seconds(explosionTime)
{
    this->_range = range;
    this->_explosionTime = explosionTime;
    this->_explode = false;
    this->_exploded = false;
    this->_tStart = std::chrono::system_clock::now();
}

rtype::ecs::component::Explodable::~Explodable()
{
}

rtype::ecs::component::compoType rtype::ecs::component::Explodable::getType() const
{
    return (rtype::ecs::component::compoType::EXPLODABLE);
}

void rtype::ecs::component::Explodable::setRange(float range)
{
    this->_range = range;
}

void rtype::ecs::component::Explodable::setExplosionTime(int explosionTime)
{
    this->_explosionTime = explosionTime;
}

void rtype::ecs::component::Explodable::setExplode(bool explode)
{
    this->_explode = explode;
}

void rtype::ecs::component::Explodable::setExploded(bool exploded)
{
    this->_exploded = exploded;
}

float rtype::ecs::component::Explodable::getRange() const
{
    return (this->_range);
}

int rtype::ecs::component::Explodable::getExplosionTime() const
{
    return (this->_explosionTime);
}

bool rtype::ecs::component::Explodable::getExplode() const
{
    return (this->_explode);
}

bool rtype::ecs::component::Explodable::getExploded() const
{
    return (this->_exploded);
}

std::chrono::time_point<std::chrono::system_clock> rtype::ecs::component::Explodable::getTStart() const
{
    return (this->_tStart);
}

std::chrono::seconds rtype::ecs::component::Explodable::getSeconds() const
{
    return (this->_seconds);
}

int rtype::ecs::component::Explodable::getPlayer() const
{
    return (this->_player);
}

void rtype::ecs::component::Explodable::setPlayer(int player)
{
    this->_player = player;
}