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

void indie::ecs::system::MovementSystem::update(std::vector<std::unique_ptr<indie::ecs::entity::Entity>> &entities)
{
    for (auto &entity : entities) {
        if (entity->hasCompoType(ecs::component::compoType::TRANSFORM)) {
            indie::ecs::component::Transform *transformCompo =
                entity->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
            if (entity->hasCompoType(indie::ecs::component::compoType::COLLIDE) == true) {
                if (entity->getComponent<indie::ecs::component::Collide>(indie::ecs::component::compoType::COLLIDE)
                        ->getCollide()
                    == false) {
                    transformCompo->setX(transformCompo->getX() + transformCompo->getSpeedX());
                    transformCompo->setY(transformCompo->getY() + transformCompo->getSpeedY());
                }
            }
        }
    }
}

indie::ecs::system::SystemType indie::ecs::system::MovementSystem::getSystemType() const
{
    return (indie::ecs::system::SystemType::MOVEMENTSYSTEM);
}