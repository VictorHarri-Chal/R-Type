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
            auto shipCompo = entities[x]->getComponent<ecs::component::IShip>(ecs::component::compoType::SHIP);
            auto transformCompo = entities[x]->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
            if (shipCompo->getShipType() == ecs::component::shipType::ZIGZAG) {
                if (transformCompo->getY() < 450) {
                    transformCompo->setSpeedY(transformCompo->getSpeedY() + 0.01);
                } else if (transformCompo->getY() > 450) {
                    transformCompo->setSpeedY(transformCompo->getSpeedY() - 0.01);
                }
            } else if (shipCompo->getShipType() == ecs::component::shipType::RUSHER) {
                if (transformCompo->getX() < -200) {
                    ecs::component::Alive *aliveCompo = entities[x]->getComponent<ecs::component::Alive>(ecs::component::compoType::ALIVE);
                    aliveCompo->setAlive(false);
                }
            } else if (shipCompo->getShipType() == ecs::component::shipType::KAMIKAZE) {
                if (transformCompo->getX() < 200) {
                    ecs::component::Alive *aliveCompo = entities[x]->getComponent<ecs::component::Alive>(ecs::component::compoType::ALIVE);
                    aliveCompo->setAlive(false);
                }
            } else if (shipCompo->getShipType() == ecs::component::shipType::TURRET) {
                if (transformCompo->getX() < 1630) {
                   transformCompo->setSpeedX(0.0f);
                }
            } else if (shipCompo->getShipType() == ecs::component::shipType::BOSS) {
                if (transformCompo->getX() < 20) {
                   transformCompo->setSpeedX(2.0f);
                } else if (transformCompo->getX() > 1300) {
                    transformCompo->setSpeedX(-2.0f);
                }
            }
        }
    }
}

rtype::ecs::system::SystemType rtype::ecs::system::EnemypathSystem::getSystemType() const
{
    return (rtype::ecs::system::SystemType::ENEMYPATHSYSTEM);
}