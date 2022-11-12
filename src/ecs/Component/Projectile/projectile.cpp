/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** projectile.cpp
*/

#include "projectile.hpp"

rtype::ecs::component::Projectile::Projectile(rtype::ecs::component::projectileType type, float damage, bool isPoweredUp)
{
    _projectileType = type;
    _damage = damage;
    _isPoweredUp = isPoweredUp;
}   

rtype::ecs::component::compoType rtype::ecs::component::Projectile::getType() const
{
    return (rtype::ecs::component::compoType::PROJECTILE);
}

rtype::ecs::component::projectileType rtype::ecs::component::Projectile::getProjectileType() const
{
    return this->_projectileType;
}

float rtype::ecs::component::Projectile::getDamage() const
{
    return (this->_damage);
}

void rtype::ecs::component::Projectile::setDamage(float damage)
{
    this->_damage = damage;
}

bool rtype::ecs::component::Projectile::getIsPoweredUp() const
{
    return (this->_isPoweredUp);
}

void rtype::ecs::component::Projectile::setIsPoweredUp(bool isPoweredUp)
{
    this->_isPoweredUp = isPoweredUp;
}
