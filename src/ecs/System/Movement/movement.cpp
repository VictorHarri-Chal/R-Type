/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** movement.cpp
*/

#include "movement.hpp"

void rtype::ecs::system::MovementSystem::update(std::vector<rtype::ecs::entity::Entity*> entities, rtype::Game*gameEngine)
{
    (void) gameEngine;
    for (auto &entity : entities) {
        if (entity->hasCompoType(ecs::component::compoType::TRANSFORM)) {
            rtype::ecs::component::Transform *transformCompo =
                entity->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
            if (entity->hasCompoType(rtype::ecs::component::compoType::COLLIDE)) {
                if (entity->getComponent<rtype::ecs::component::Collide>(rtype::ecs::component::compoType::COLLIDE)
                        ->getCollide() == false) {
                    transformCompo->setX(transformCompo->getX() + transformCompo->getSpeedX());
                    transformCompo->setY(transformCompo->getY() + transformCompo->getSpeedY());
                }
            }
        }
    }
}

rtype::ecs::system::SystemType rtype::ecs::system::MovementSystem::getSystemType() const
{
    return (rtype::ecs::system::SystemType::MOVEMENTSYSTEM);
}