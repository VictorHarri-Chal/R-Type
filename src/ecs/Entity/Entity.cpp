/*
** EPITECH PROJECT, 2022
** Entity
** File description:
** Entity
*/

#include "Entity.hpp"

rtype::ecs::entity::Entity::Entity()
{
}

rtype::ecs::entity::Entity::Entity(rtype::ecs::entity::entityType type)
{
    this->_type = type;
}

rtype::ecs::entity::Entity::~Entity()
{
}

rtype::ecs::entity::entityType rtype::ecs::entity::Entity::getEntityType() const
{
    return (this->_type);
}
