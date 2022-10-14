/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** explodable.cpp
*/

#include "explodable.hpp"
#include <cmath>

rtype::ecs::system::Explodable::Explodable()
{
}

rtype::ecs::system::Explodable::~Explodable()
{
}


void rtype::ecs::system::Explodable::update(std::vector<rtype::ecs::entity::Entity*> entities, rtype::Game*gameEngine)
{

}

rtype::ecs::system::SystemType rtype::ecs::system::Explodable::getSystemType() const
{
    return (rtype::ecs::system::SystemType::EXPLODABLESYSTEM);
}