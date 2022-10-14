/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** projectile.cpp
*/

#include "projectile.hpp"

rtype::ecs::component::Projectile::Projectile(bool type)
{
    _type = type;
}   

rtype::ecs::component::Projectile::~Projectile()
{
}

rtype::ecs::component::compoType rtype::ecs::component::Projectile::getType() const
{
    return (rtype::ecs::component::compoType::PROJECTILE);
}

bool rtype::ecs::component::Projectile::getProjectileType() const
{
    return this->_type;
}
