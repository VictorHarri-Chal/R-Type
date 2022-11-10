/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Particles.cpp
*/

#include "particles.hpp"
#include <cmath>

void rtype::ecs::system::ParticlesSystem::update(std::vector<rtype::ecs::entity::Entity*> entities, rtype::Game*gameEngine)
{
    (void) gameEngine;
    if (_particleClock.getElapsedTime() >= sf::seconds(1.0/2.5f)) {
        for (auto &entity : entities) {
            if (entity->getEntityType() == rtype::ecs::entity::PARTICLE) {
                rtype::ecs::component::Drawable2D *drawable2dCompo =
                entity->getComponent<rtype::ecs::component::Drawable2D>(rtype::ecs::component::compoType::DRAWABLE2D);
                sf::IntRect rect = drawable2dCompo->getRect();
                if (rect.left == 165) {
                    ecs::component::Alive *aliveCompo = entity->getComponent<ecs::component::Alive>(ecs::component::compoType::ALIVE);
                    aliveCompo->setAlive(false);
                } else
                    rect.left += 35;
                drawable2dCompo->setRect(rect);
            } else if (entity->getEntityType() == rtype::ecs::entity::HIT) {
                rtype::ecs::component::Drawable2D *drawable2dCompo =
                entity->getComponent<rtype::ecs::component::Drawable2D>(rtype::ecs::component::compoType::DRAWABLE2D);
                sf::IntRect rect = drawable2dCompo->getRect();
                if (rect.left == 266) {
                    ecs::component::Alive *aliveCompo = entity->getComponent<ecs::component::Alive>(ecs::component::compoType::ALIVE);
                    aliveCompo->setAlive(false);
                } else
                    rect.left += 20;
                drawable2dCompo->setRect(rect);
            }
        }
        _particleClock.restart();
    }
}

rtype::ecs::system::SystemType rtype::ecs::system::ParticlesSystem::getSystemType() const
{
    return (rtype::ecs::system::SystemType::PARTICLESSYSTEM);
}