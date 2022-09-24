/*
** EPITECH PROJECT, 2022
** World (WORLD)
** File description:
** World (WORLD)
*/

#include "world.hpp"

rtype::ecs::world::World::World()
{
    this->nbEntities = 0;
    this->_entitiesVector.reserve(1);
}

rtype::ecs::world::World::~World()
{
}
