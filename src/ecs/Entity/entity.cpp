/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** entity.cpp
*/

#include "entity.hpp"

rtype::ecs::entity::Entity::Entity()
{
    this->_id = 0;
}

rtype::ecs::entity::Entity::Entity(rtype::ecs::entity::entityType type)
{
    this->_type = type;
    this->_id = 0;
}

rtype::ecs::entity::Entity::~Entity()
{
}

rtype::ecs::entity::entityType rtype::ecs::entity::Entity::getEntityType() const
{
    return (this->_type);
}

size_t rtype::ecs::entity::Entity::getId() const
{
    return this->_id;
}

void rtype::ecs::entity::Entity::setId(size_t id)
{
    this->_id = id;
}