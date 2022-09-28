/**
 * @file Movement.cpp
 * @author Cédric Corge (cedric.corge@epitech.eu)
 * @brief Movement system source file
 * @version 0.1
 * @date 2022-06-01
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "Movement.hpp"

void rtype::ecs::system::MovementSystem::update(std::vector<std::unique_ptr<rtype::ecs::entity::Entity>> &entities, rtype::Game *gameEngine)
{
    for (auto &entity : entities) {
        if (entity->hasCompoType(ecs::component::compoType::TRANSFORM)) {
            rtype::ecs::component::Transform *transformCompo =
                entity->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
            if (entity->hasCompoType(rtype::ecs::component::compoType::COLLIDE) == true) {
                if (entity->getComponent<rtype::ecs::component::Collide>(rtype::ecs::component::compoType::COLLIDE)
                        ->getCollide()
                    == false) {
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