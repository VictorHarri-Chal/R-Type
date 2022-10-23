/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** enemypath.cpp
*/

#include "enemypath.hpp"
#include <cmath>

void rtype::ecs::system::EnemypathSystem::update(std::vector<rtype::ecs::entity::Entity*> entities, rtype::Game*gameEngine)
{
    (void) gameEngine;
    for (size_t x = 0; x < entities.size(); x++) {
        if (entities[x]->hasCompoType(ecs::component::compoType::SHIP)) {
            auto shipCompo = entities[x]->getComponent<ecs::component::Ship>(ecs::component::compoType::SHIP);
            if (shipCompo->getShipType() == ecs::component::shipType::ZIGZAG) {
                auto transformCompo = entities[x]->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
                if (transformCompo->getY() < 450) {
                    shipCompo->setDirectionVertical(true);
                    // shipCompo->setDirectionHorizontal(true);
                    // transformCompo->setSpeedX(0.40);
                } else if (transformCompo->getY() > 450) {
                    shipCompo->setDirectionVertical(false);
                    // shipCompo->setDirectionHorizontal(false);
                    // transformCompo->setSpeedX(-0.40);
                }
                if (shipCompo->getDirectionVertical()) {
                    transformCompo->setSpeedY(transformCompo->getSpeedY() + 0.03);
                } else if (!shipCompo->getDirectionVertical()) {
                    transformCompo->setSpeedY(transformCompo->getSpeedY() - 0.03);
                }
                // if (shipCompo->getDirectionHorizontal()) {
                //     transformCompo->setSpeedX(transformCompo->getSpeedX() + 0.8);
                // } else if (!shipCompo->getDirectionHorizontal()) {
                //     transformCompo->setSpeedX(transformCompo->getSpeedX() - 0.8);
                // }
            } else if (shipCompo->getShipType() == ecs::component::shipType::RUSHER) {

            }
        }
    }
}

rtype::ecs::system::SystemType rtype::ecs::system::EnemypathSystem::getSystemType() const
{
    return (rtype::ecs::system::SystemType::ENEMYPATHSYSTEM);
}