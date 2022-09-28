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
    size_t size = this->_entitiesVector.size();

    for (size_t i = 0; i < size; i++){
        rtype::ecs::entity::Entity *tmp = this->_entitiesVector[i];
        delete tmp;
    }
}

rtype::ecs::entity::Entity *rtype::ecs::world::World::getEntity(size_t id) const
{
    if (id > this->_entitiesVector.size()) {
        std::cout << "Entity not found" << std::endl;
        return (nullptr);
    }
    return (this->_entitiesVector[id]);
}

void rtype::ecs::world::World::addEntity(entity::Entity *entity)
{
    entity->setId(this->nbEntities);
    this->_entitiesVector.push_back(entity);
    nbEntities++;
}

std::vector<rtype::ecs::entity::Entity*> rtype::ecs::world::World::getEntities() const
{
    return (this->_entitiesVector);
}